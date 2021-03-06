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
		{3, ". Delete user", stillUnderDevelopmentMessage},
		{4, ". View all users", getAllUsers},
		{5, ". Return to main menu", mainMenuAdminToUserWrapper}
	};

	return menu;
}

void mainMenuAdminToUserWrapper(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	TEAM team;
	PROJECT project;

	mainMenuAdmin(connection, user, team, project, currentUser);
}

void userManagementView(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	std::vector<MENU_OPTION_USER> options = initializeUserManagementViewMenuOptions();

	std::cout << std::endl;

	showMenuOptions<MENU_OPTION_USER>(options);
	handleUserChoiceUser(options, connection, user, currentUser);
}

std::vector<MENU_OPTION_USER> initializeEditUserMenuOptions()
{
	std::vector<MENU_OPTION_USER> menu =
	{
		{1, ". Username", editUsernameMenu},
		{2, ". Password", editPasswordMenu},
		{3, ". First name", editFirstNameMenu},
		{4, ". Last name", editLastNameMenu},
		{5, ". Return to user management view", userManagementView}
	};

	return menu;
}

void editUserMenu(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	std::vector<MENU_OPTION_USER> options = initializeEditUserMenuOptions();

	std::cout << std::endl << "Enter user id: ";
	std::cin >> user.id;

	showMenuOptions<MENU_OPTION_USER>(options);
	handleUserChoiceUser(options, connection, user, currentUser);
}

void stillUnderDevelopmentMessage(nanodbc::connection connection, USER& user, const USER& currentUser)
{
	std::cout << "\nSorry, this functionality is still under development. :)\n";

	userManagementView(connection, user, currentUser);
}




