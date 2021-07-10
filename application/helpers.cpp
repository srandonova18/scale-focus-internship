#pragma once

#include <iostream>
#include <vector>

#include "userPresentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "presentation.h"

void handleUserChoiceConstUser(std::vector<MENU_OPTION_CONST_USER>& options, nanodbc::connection connection, const USER& user, const USER& currentUser)
{
	int choice;

	std::cout << std::endl << "Enter your choice: ";
	std::cin >> choice;
	
	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, user, currentUser);
		}
	}
}

void handleUserChoiceUser(std::vector<MENU_OPTION_USER>& options, nanodbc::connection connection, USER& user, const USER& currentUser)
{
	int choice;

	std::cout << std::endl << "Enter your choice: ";
	std::cin >> choice;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, user, currentUser);
		}
	}
}

void handleUserChoiceConstTeam(std::vector<MENU_OPTION_CONST_TEAM>& options, nanodbc::connection connection, const TEAM& team, const USER& currentUser)
{
	int choice;

	std::cout << std::endl << "Enter your choice: ";
	std::cin >> choice;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, team, currentUser);
		}
	}
}

void handleUserChoiceTeam(std::vector<MENU_OPTION_TEAM>& options, nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	int choice;

	std::cout << std::endl << "Enter your choice: ";
	std::cin >> choice;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, team, currentUser);
		}
	}
}


