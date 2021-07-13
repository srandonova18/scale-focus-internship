#include "projectPresentation.h"
#include "projectData.h"

std::vector<MENU_OPTION_PROJECT> initializeProjectManagementViewMenuOptions()
{
	std::vector<MENU_OPTION_PROJECT> menu =
	{
		{1, ". Create new project", addProject},
		{2, ". Edit project", editProjectMenu},
		{3, ". Delete project"},
		{4, ". View all projects", getAllProjects},
		{5, ". Return to main menu", mainMenuUserToProjectWrapper}
	};

	return menu;
}

void projectManagementView(nanodbc::connection connection, PROJECT& project, const USER& currentUser)
{
	std::vector<MENU_OPTION_PROJECT> options = initializeProjectManagementViewMenuOptions();

	std::cout << std::endl;

	showMenuOptions<MENU_OPTION_PROJECT>(options);
	handleUserChoiceProject(options, connection, project, currentUser);
}

void projectManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser)
{
	projectManagementView(connection, project, currentUser);
}

void mainMenuUserToProjectWrapper(nanodbc::connection connection, PROJECT& project, const USER& currentUser)
{
	USER user;
	TEAM team;

	mainMenuUser(connection, user, team, project, currentUser);
}

std::vector<MENU_OPTION_PROJECT> initializeEditProjectMenuOptions()
{
	std::vector<MENU_OPTION_PROJECT> menu =
	{
		{1, ". Title", editProjectTitleMenu},
		{2, ". Description", editProjectDescriptionMenu},
		{3, ". Return to project management view", projectManagementView}
	};

	return menu;
}

void editProjectMenu(nanodbc::connection connection, PROJECT& project, const USER& currentUser)
{
	std::vector<MENU_OPTION_PROJECT> options = initializeEditProjectMenuOptions();

	std::cout << std::endl << "Enter project id: ";
	std::cin >> project.id;

	showMenuOptions<MENU_OPTION_PROJECT>(options);
	handleUserChoiceProject(options, connection, project, currentUser);
}

