#include <iostream>
#include <vector>

#include "teamPresentation.h"
#include "helpers.h"
#include "teamDefine.h"
#include "presentation.h"
#include "teamData.h"

std::vector<MENU_OPTION_TEAM> initializeTeamManagementViewMenuOptions()
{
	std::vector<MENU_OPTION_TEAM> menu =
	{
		{1, ". Create new team", addTeam},
		{2, ". Edit team", editTeamMenu},
		{3, ". Delete team",},
		{4, ". View all teams", getAllTeams},
		{5, ". Return to main menu", mainMenuToTeamWrapper}
	};

	return menu;
}

void mainMenuToTeamWrapper(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	USER user;

	mainMenu(connection, user, team, currentUser);
}

void teamManagementView(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	std::vector<MENU_OPTION_TEAM> options = initializeTeamManagementViewMenuOptions();

	std::cout << std::endl;

	showMenuOptions<MENU_OPTION_TEAM>(options);
	handleUserChoiceTeam(options, connection, team, currentUser);
}

std::vector<MENU_OPTION_TEAM> initializeEditTeamMenuOptions()
{
	std::vector<MENU_OPTION_TEAM> menu =
	{
		{1, ". Title", editTitleMenu},
		{2, ". Return to team management view", teamManagementView}
	};

	return menu;
}

void editTeamMenu(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	std::vector<MENU_OPTION_TEAM> options = initializeEditTeamMenuOptions();

	std::cout << std::endl << "Enter team id: ";
	std::cin >> team.id;

	showMenuOptions<MENU_OPTION_TEAM>(options);
	handleUserChoiceTeam(options, connection, team, currentUser);
}
