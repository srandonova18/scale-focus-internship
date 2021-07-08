#include <iostream>

#include "userDefine.h"
#include "userData.h"

USER USER::addUser()
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

	return newUser;
}

void USER::showUser(USER user)
{
	std::cout << user.firstName << " " << user.lastName << " " << user.username;
}
