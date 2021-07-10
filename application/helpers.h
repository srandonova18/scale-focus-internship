#pragma once

#include <iostream>
#include <vector>

#include "presentation.h"

typedef void (*MENU_HADLER)(nanodbc::connection connection, const USER& user, const USER& currentUser);
typedef void (*MENU_HADLER_USER)(nanodbc::connection connection, USER& user, const USER& currentUser);

struct MENU_OPTION
{
	int number = 0;
	const char* message;
	MENU_HADLER handler;
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

void showMenuOptions(std::vector<MENU_OPTION>&);

void handleUserChoice(std::vector<MENU_OPTION>&, nanodbc::connection, const USER&, const USER&);

void showMenuOptionsUser(std::vector<MENU_OPTION_USER>&);

void handleUserChoiceUser(std::vector<MENU_OPTION_USER>&, nanodbc::connection, USER&, const USER&);