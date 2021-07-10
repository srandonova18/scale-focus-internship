#pragma once

#include <iostream>
#include <vector>

#include "userPresentation.h"
#include "helpers.h"
#include "userDefine.h"
#include "presentation.h"

void showMenuOptions(std::vector<MENU_OPTION>& options)
{
	for (size_t i = 0; i < options.size(); i++)
	{
		std::cout << options.at(i).number;
		std::cout << options.at(i).message;
		std::cout << std::endl;
	}
}

void handleUserChoice(std::vector<MENU_OPTION>& options, nanodbc::connection connection, const USER& user)
{
	char choice;

	std::cout << "Enter your choice: ";
	std::cin >> choice;

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, user);
		}
	}
}


