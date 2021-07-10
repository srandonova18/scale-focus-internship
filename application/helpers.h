#pragma once

#include <iostream>
#include <vector>

#include "presentation.h"

typedef void (*MENU_HADLER_CONST_USER)(nanodbc::connection connection, const USER& user, const USER& currentUser);
typedef void (*MENU_HADLER_USER)(nanodbc::connection connection, USER& user, const USER& currentUser);

struct MENU_OPTION_CONST_USER
{
	int number = 0;
	const char* message;
	MENU_HADLER_CONST_USER handler;
};

struct MENU_OPTION_USER
{
	int number = 0;
	const char* message;
	MENU_HADLER_USER handler;
};

template <class T>
bool safeCin(T& data)
{
	if (!(std::cin >> data))
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		return false;
	}

	return true;
};

void handleUserChoiceConstUser(std::vector<MENU_OPTION_CONST_USER>&, nanodbc::connection, const USER&, const USER&);

template <class T>
void showMenuOptions(std::vector<T>& options)
{
	std::cout << std::endl;

	for (size_t i = 0; i < options.size(); i++)
	{
		std::cout << options.at(i).number;
		std::cout << options.at(i).message;
		std::cout << std::endl;
	}
}

void handleUserChoiceUser(std::vector<MENU_OPTION_USER>&, nanodbc::connection, USER&, const USER&);

