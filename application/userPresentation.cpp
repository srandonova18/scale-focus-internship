#include <iostream>
#include <conio.h>

#include "userPresentation.h"
#include "helpers.h"
#include "userDefine.h"

void userMenu()
{
	USER newUser;

	std::cout << "USER MENU" << std::endl;

	newUser = newUser.addUser();

	newUser.showUser(newUser);
}
