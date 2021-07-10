#include <iostream>
#include <conio.h>
#include <vector>

#include "userPresentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "presentation.h"
#include "userData.h"

std::vector<MENU_OPTION_USER> initializeUserManagementViewMenuOptions()
{
	std::vector<MENU_OPTION_USER> menu =
	{
		{1, ". Create new user", addUser},
		{2, ". Edit user", editUserMenu},
		{3, ". Delete user",},
		{4, ". View all users", getAllUsers}
	};

	return menu;
}

void userManagementView(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	std::vector<MENU_OPTION_USER> options = initializeUserManagementViewMenuOptions();

	std::cout << std::endl;

	showMenuOptionsUser(options);
	handleUserChoiceUser(options, connection, user, currentUser);
}

std::vector<MENU_OPTION_USER> initializeEditUserMenuOptions()
{
	std::vector<MENU_OPTION_USER> menu =
	{
		{1, ". Username", editUsernameMenu},
		{2, ". Password", },
		{3, ". First name",},
		{4, ". Last name",}
	};

	return menu;
}

void editUserMenu(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	std::vector<MENU_OPTION_USER> options = initializeEditUserMenuOptions();

	std::cout << std::endl << "Enter user id: ";
	std::cin >> user.id;

	showMenuOptionsUser(options);
	handleUserChoiceUser(options, connection, user, currentUser);
}




