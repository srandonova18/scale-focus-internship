#include <iostream>
#include <conio.h>
#include <nanodbc.h>
#include <cstring>

#include "userData.h"
#include "helpers.h"
#include "userDefine.h"
#include "userPresentation.h"

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

void insertUser(nanodbc::connection connection, const USER& user, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		INSERT INTO
			[project_management_application].[dbo].[users]

		(username, password, first_name, last_name, creator_id, last_changer_id)

		VALUES
		(?, ?, ?, ?, ?, ?)
	)"));

	statement.bind(0, user.username.c_str());
	statement.bind(1, user.password.c_str());
	statement.bind(2, user.firstName.c_str());
	statement.bind(3, user.lastName.c_str());
	statement.bind(4, &currentUser.id);
	statement.bind(5, &currentUser.id);

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

void getAllUsers(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	USER foundUser;

	nanodbc::statement statement(connection);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT
		*
	FROM [project_management_application].[dbo].[users]
	)"));

	auto result = execute(statement);

	while (result.next())
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

		showUser(foundUser);
	}

	userManagementView(connection, user, currentUser);
}

USER findUserById(nanodbc::connection connection, const USER& user)
{
	USER foundUser;

	nanodbc::statement statement(connection);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT
		*
	FROM [project_management_application].[dbo].[users]
	WHERE
		Id = ?
	)"));

	statement.bind(0, &user.id);

	auto result = execute(statement);

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

void editUsername(nanodbc::connection connection, std::string username, const USER& user, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		UPDATE 
			[project_management_application].[dbo].[users]
		SET
			username = ?,
			[date_of_last_change] = getdate()
		WHERE
			id = ?	
	)"));

	statement.bind(0, username.c_str());
	//statement.bind(1, &currentUser.id);
	statement.bind(1, &user.id);

	execute(statement);
}

void editUsernameMenu(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	std::string newUsername;

	std::cout << "Enter new username: ";
	newUsername = inputName();

	editUsername(connection, newUsername, user, currentUser);

	std::cout << "The username was edited successfully." << std::endl;

	editUserMenu(connection, user, currentUser);
}