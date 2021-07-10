#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"
#include "userData.h"
#include "helpers.h"

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
	newUser.password = inputPassword();

	insertUser(connection, newUser);
}

void USER::showUser(USER user)
{
	std::cout << user.id << user.firstName << " " << user.lastName << " " << user.username << " " << user.dateOfLastChange.day;
}
