#include <iostream>

#include "teamDefine.h"
#include "userData.h"
#include "teamData.h"

void addTeam(nanodbc::connection connection, TEAM& newTeam, const USER& currentUser)
{
	std::cout << std::endl << "Enter title: ";
	newTeam.title = inputName();

	insertTeam(connection, newTeam, currentUser);

	std::cout << std::endl << std::endl << "The new team has been registered in the system." << std::endl;

	//teamManagementView(connection, newUser, currentUser);
}
