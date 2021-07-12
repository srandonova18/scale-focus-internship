#include "projectDefine.h"
#include "userData.h"
#include "projectData.h"
#include "projectPresentation.h"

void addProject(nanodbc::connection connection, PROJECT& newProject, const USER& currentUser)
{
	std::cout << std::endl << "Enter title: ";
	newProject.title = inputName();

	std::cout << std::endl << "Enter description: ";
	newProject.description = inputName();

	insertProject(connection, newProject, currentUser);

	std::cout << std::endl << std::endl << "The new project has been registered in the system." << std::endl;

	projectManagementView(connection, newProject, currentUser);
}

void showProject(PROJECT project)
{
	std::cout << std::endl << "Id: " << project.id << std::endl;
	std::cout << "Title: " << project.title << std::endl;
	std::cout << "Description: " << project.description << std::endl;
	std::cout << "Tead Id: " << project.teamId << std::endl;
	std::cout << "Date of profile creation:  ";
	std::cout << project.dateOfCreation.day << "/" << project.dateOfCreation.month << "/" << project.dateOfCreation.year << std::endl;
}
