#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"
#include "userData.h"

void USER::addUser(nanodbc::connection connection)
{
	USER newUser;

	std::cout << "first name: ";
	newUser.firstName = inputName();
	
	std::cout << "last name: ";
	newUser.lastName = inputName();

	std::cout << "username: ";
	newUser.username = inputName();

	std::cout << "password: ";
	inputPassword(newUser.password);

	insertUser(connection, newUser);

	//return newUser;
}

void insertUser(nanodbc::connection connection, const USER& user)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		INSERT INTO
		[project_management_application].[dbo].[user]

		(username, password, first_name, last_name, creator_id, last_changer_id)

		VALUES
		(?, ?, ?, ?, ?, ?)
	)"));

	int mockId = 1;

	statement.bind(0, user.username.c_str());
	statement.bind(1, user.password);
	statement.bind(2, user.firstName.c_str());
	statement.bind(3, user.lastName.c_str());
	statement.bind(4, &mockId);
	statement.bind(5, &mockId);

	execute(statement);
}

void USER::showUser(USER user)
{
	std::cout << user.firstName << " " << user.lastName << " " << user.username;
}
