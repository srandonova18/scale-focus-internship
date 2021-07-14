#include <iostream>
#include <conio.h>
#include <vector>

#include "presentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "userData.h"
#include "userPresentation.h"
#include "teamPresentation.h"
#include "projectPresentation.h"

USER loginMenu(nanodbc::connection connection)
{
	USER currentUser;
	bool isInputValid = false;

	std::cout << std::endl;

	std::cout << "Username: ";
	currentUser.username = inputString(64, "Username: ");

	std::cout << "Password: ";
	currentUser.password = inputPassword();

	currentUser = findUserByUsernameAndPassword(connection, currentUser);

	return currentUser;
}

bool isAdmin(const USER& currentUser)
{
	return currentUser.id == 1;
}

void userManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser)
{
	userManagementView(connection, user, currentUser);
}

void teamManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser)
{
	teamManagementView(connection, team, currentUser);
}

std::vector<MENU_OPTION_VIEW> initializeMainMenuAdminOptions()
{
	std::vector<MENU_OPTION_VIEW> menu =
	{
		{1, ". User management view", userManagementViewWrapper},
		{2, ". Team management view", teamManagementViewWrapper}
	};

	return menu;
}

void mainMenuAdmin(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser)
{
	std::vector<MENU_OPTION_VIEW> options = initializeMainMenuAdminOptions();

	showMenuOptions<MENU_OPTION_VIEW>(options);
	handleUserChoiceView(options, connection, user, team, project, currentUser);
}

std::vector<MENU_OPTION_VIEW> initializeMainMenuUserOptions()
{
	std::vector<MENU_OPTION_VIEW> menu =
	{
		{1, ". Project management view", projectManagementViewWrapper}
	};

	return menu;
}

void mainMenuUser(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser)
{
	std::vector<MENU_OPTION_VIEW> options = initializeMainMenuUserOptions();

	showMenuOptions<MENU_OPTION_VIEW>(options);
	handleUserChoiceView(options, connection, user, team, project, currentUser);
}








