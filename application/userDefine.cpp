#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"
#include "userData.h"
#include "helpers.h"
#include "userPresentation.h"

void addUser(nanodbc::connection connection, const USER& currentUser)
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

	std::cout << std::endl << "The new user has been registered in the system." << std::endl;

	userManagementView(connection, currentUser);
}

void showUser(USER user)
{
	std::cout << std::endl << "Id: " << user.id << std::endl;
	std::cout << "First name: " << user.firstName << std::endl;
	std::cout << "Last name: " << user.lastName << std::endl;
	std::cout << "Username: " << user.username << std::endl;
	std::cout << "Date of profile creation:  ";
	std::cout << user.dateOfCreation.day << "/" << user.dateOfCreation.month << "/" << user.dateOfCreation.year << std::endl;
}
