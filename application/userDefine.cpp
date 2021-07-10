#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"
#include "userData.h"
#include "helpers.h"

void USER::addUser(nanodbc::connection connection, USER currentUser)
{
	USER newUser;

	std::cout << std::endl << "first name: ";
	newUser.firstName = inputName();

	std::cout << "last name: ";
	newUser.lastName = inputName();

	std::cout << "username: ";
	newUser.username = inputName();

	std::cout << "password: ";
	newUser.password = inputPassword();

	insertUser(connection, newUser, currentUser);
}

void USER::showUser(USER user)
{
	std::cout << std::endl << "Id: " << user.id << std::endl;
	std::cout << "First name: " << user.firstName << std::endl;
	std::cout << "Last name: " << user.lastName << std::endl;
	std::cout << "Username: " << user.username << std::endl;
	std::cout << "Date of profile creation:  ";
	std::cout << user.dateOfCreation.day << "/" << user.dateOfCreation.month << "/" << user.dateOfCreation.year << std::endl;
}
