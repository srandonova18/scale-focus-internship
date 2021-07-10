#pragma once

#include <iostream>
#include <vector>

#include "userPresentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "presentation.h"

void showMenuOptions(std::vector<MENU_OPTION>& options)
{
	std::cout << std::endl;

	for (size_t i = 0; i < options.size(); i++)
	{
		std::cout << options.at(i).number;
		std::cout << options.at(i).message;
		std::cout << std::endl;
	}
}

void handleUserChoice(std::vector<MENU_OPTION>& options, nanodbc::connection connection, const USER& user, const USER& currentUser)
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

void showMenuOptionsUser(std::vector<MENU_OPTION_USER>& options)
{
	std::cout << std::endl;

	for (size_t i = 0; i < options.size(); i++)
	{
		std::cout << options.at(i).number;
		std::cout << options.at(i).message;
		std::cout << std::endl;
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


