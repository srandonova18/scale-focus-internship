#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"
#include "userData.h"
#include "helpers.h"
#include "userPresentation.h"

void addUser(nanodbc::connection connection, USER& newUser, const USER& currentUser)
{
	std::cout << std::endl << "Enter first name: ";
	newUser.firstName = inputString(32, "Enter first name: ");

	std::cout << std::endl << "Enter last name: ";
	newUser.lastName = inputString(32, "Enter last name: ");

	std::cout << std::endl << "Enter username: ";
	newUser.username = inputString(64, "Enter username: ");

	std::cout << std:: endl << "Enter password: ";
	newUser.password = inputPassword();

	insertUser(connection, newUser, currentUser);

	std::cout << std::endl << std::endl << "The new user has been registered in the system." << std::endl;

	userManagementView(connection, newUser, currentUser);
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
