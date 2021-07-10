#include <iostream>
#include <conio.h>
#include <nanodbc.h>
#include <cstring>

#include "userData.h"
#include "helpers.h"
#include "userDefine.h"

std::string inputName()
{
	std::string name;

	safeCin<std::string>(name);

	return name;
}

std::string inputPassword()
{
	char ch;
	std::string password;

	while ((ch = _getch()) != '\r')
	{
		password += ch;
		std::cout << "*";
	}

	return password;
}

void insertUser(nanodbc::connection connection, const USER& user)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		INSERT INTO
		[project_management_application].[dbo].[users]

		(username, password, first_name, last_name, creator_id, last_changer_id)

		VALUES
		(?, ?, ?, ?, ?, ?)
	)"));

	int mockId = 1;

	statement.bind(0, user.username.c_str());
	statement.bind(1, user.password.c_str());
	statement.bind(2, user.firstName.c_str());
	statement.bind(3, user.lastName.c_str());
	statement.bind(4, &mockId);
	statement.bind(5, &mockId);

	execute(statement);
}

USER findUserByUsernameAndPassword(nanodbc::connection connection, const USER& user)
{
	USER foundUser;

	nanodbc::statement statement(connection);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT
		*
	FROM [project_management_application].[dbo].[users]
	WHERE
		username = ? AND password = ?
	)"));

	statement.bind(0, user.username.c_str());
	statement.bind(1, user.password.c_str());

	auto result = execute(statement);
	nanodbc::string password;

	if (result.next())
	{
		foundUser.id = result.get<int>("id");
		foundUser.username = result.get<nanodbc::string>("username", "");

		foundUser.password = result.get<nanodbc::string>("password", "");

		foundUser.firstName = result.get<nanodbc::string>("first_name", "");
		foundUser.lastName = result.get<nanodbc::string>("last_name", "");
		foundUser.dateOfCreation = result.get<nanodbc::date>("date_of_creation");
		foundUser.creatorId = result.get<int>("creator_id");
		foundUser.dateOfLastChange = result.get<nanodbc::date>("date_of_last_change");
		foundUser.lastChangerId = result.get<int>("last_changer_id");
		foundUser.isDeleted = result.get<int>("is_deleted");
	}

	return foundUser;
}