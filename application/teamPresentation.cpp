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
		{3, ". Delete team", stillUnderDevelopmentMessage},
		{4, ". View all teams", getAllTeams},
		{5, ". Return to main menu", mainMenuAdminToTeamWrapper}
	};

	return menu;
}

void mainMenuAdminToTeamWrapper(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	USER user;
	PROJECT project;

	mainMenuAdmin(connection, user, team, project, currentUser);
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
		{1, ". Title", editTeamTitleMenu},
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

void stillUnderDevelopmentMessage(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	std::cout << "\nSorry, this functionality is still under development. :)\n";

	teamManagementView(connection, team, currentUser);
}
