#include "projectDefine.h"
#include "userData.h"
#include "projectData.h"

void addProject(nanodbc::connection connection, PROJECT& newProject, const USER& currentUser)
{
	std::cout << std::endl << "Enter title: ";
	newProject.title = inputName();

	std::cout << std::endl << "Enter description: ";
	newProject.description = inputName();

	insertProject(connection, newProject, currentUser);

	std::cout << std::endl << std::endl << "The new project has been registered in the system." << std::endl;

	//projectManagementView(connection, newproject, currentUser);
}
