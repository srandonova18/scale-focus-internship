#include <iostream>

#include "teamDefine.h"
#include "userData.h"
#include "teamData.h"
#include "teamPresentation.h"

void addTeam(nanodbc::connection connection, TEAM& newTeam, const USER& currentUser)
{
	std::cout << std::endl << "Enter title: ";
	newTeam.title = inputString(25, "Enter title: ");

	insertTeam(connection, newTeam, currentUser);

	std::cout << std::endl << std::endl << "The new team has been registered in the system." << std::endl;

	teamManagementView(connection, newTeam, currentUser);
}

void showTeam(TEAM team)
{
	std::cout << std::endl << "Id: " << team.id << std::endl;
	std::cout << "Title: " << team.title << std::endl;
	std::cout << "Date of creation:  ";
	std::cout << team.dateOfCreation.day << "/" << team.dateOfCreation.month << "/" << team.dateOfCreation.year << std::endl;
}
