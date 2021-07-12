#include "projectPresentation.h"

std::vector<MENU_OPTION_PROJECT> initializeProjectManagementViewMenuOptions()
{
	std::vector<MENU_OPTION_PROJECT> menu =
	{
		{1, ". Create new project", addProject},
		{2, ". Edit project"},
		{3, ". Delete project"},
		{4, ". View all projects"},
		{5, ". Return to main menu"}
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
