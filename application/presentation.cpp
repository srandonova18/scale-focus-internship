#include <iostream>
#include <conio.h>

#include "presentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "userData.h"

void loginMenu(nanodbc::connection connection)
{
	USER user;

	std::cout << std::endl;

	std::cout << "username: ";
	safeCin<std::string>(user.username);

	std::cout << "password: ";
	user.password = inputPassword();

	user = findUserByUsernameAndPassword(connection, user);

	std::cout << std::endl;

	user.showUser(user);
}




