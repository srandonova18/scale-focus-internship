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
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		std::cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			std::cout << "The input is invalid, please try again." << std::endl;
		}
	}
	
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
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		std::cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			std::cout << "The input is invalid, please try again." << std::endl;
		}
	}

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
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		std::cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			std::cout << "The input is invalid, please try again." << std::endl;
		}
	}

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
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		std::cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			std::cout << "The input is invalid, please try again." << std::endl;
		}
	}

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, team, currentUser);
		}
	}
}

void handleUserChoiceView(std::vector<MENU_OPTION_VIEW>& options, nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser)
{
	int choice;
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		std::cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			std::cout << "The input is invalid, please try again." << std::endl;
		}
	}

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, user, team, project, currentUser);
		}
	}
}

void handleUserChoiceProject(std::vector<MENU_OPTION_PROJECT>& options, nanodbc::connection connection, PROJECT& project, const USER& currentUser)
{
	int choice;
	bool isInputValid = false;
	bool isInputInTheRange = false;

	while (!isInputInTheRange or !isInputValid) {

		std::cout << "\nEnter your choice: ";
		isInputValid = safeCin<int>(choice);
		isInputInTheRange = isInputInRange(options.size(), choice);
		if (!isInputValid or !isInputInTheRange)
		{
			std::cout << "The input is invalid, please try again." << std::endl;
		}
	}

	for (size_t i = 0; i < options.size(); i++)
	{
		if (choice == options.at(i).number)
		{
			options.at(i).handler(connection, project, currentUser);
		}
	}
}


bool isInputInRange(size_t size, size_t inputSize)
{
	return (inputSize > 0 and inputSize <= size);
}


