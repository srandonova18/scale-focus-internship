#include <iostream>
#include <conio.h>

#include "presentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "userData.h"

USER loginMenu(nanodbc::connection connection)
{
	USER currentUser;

	std::cout << std::endl;

	std::cout << "username: ";
	safeCin<std::string>(currentUser.username);

	std::cout << "password: ";
	currentUser.password = inputPassword();

	currentUser = findUserByUsernameAndPassword(connection, currentUser);

	return currentUser;
}

bool isAdmin(const USER& currentUser)
{
	return currentUser.id == 1;
}




