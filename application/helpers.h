#pragma once

#include <iostream>
#include <vector>

#include "presentation.h"

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

void handleUserChoice(std::vector<MENU_OPTION>&, nanodbc::connection connection, const USER& user);