#include <iostream>
#include <conio.h>
#include <vector>

#include "userPresentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "presentation.h"

std::vector<MENU_OPTION> initializeUserManagementViewMenuOptions()
{
	std::vector<MENU_OPTION> menu =
	{
		{1, ".Create new user",},
		{2, ".Edit user", },
		{3, ".Delete user",},
		{4, "View all users"}
	};

	return menu;
}

void userManagementView()
{
	USER newUser;
	std::vector<MENU_OPTION> options = initializeUserManagementViewMenuOptions();

	showMenuOptions(options);
	handleUserChoice(options);


	/*std::cout << "USER MENU" << std::endl;

	newUser = newUser.addUser();

	newUser.showUser(newUser);*/


}


