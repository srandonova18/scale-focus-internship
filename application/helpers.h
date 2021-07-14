#pragma once

#include <iostream>
#include <vector>

#include "presentation.h"

typedef void (*MENU_HANDLER_CONST_USER)(nanodbc::connection connection, const USER& user, const USER& currentUser);
typedef void (*MENU_HANDLER_USER)(nanodbc::connection connection, USER& user, const USER& currentUser);

typedef void (*MENU_HANDLER_CONST_TEAM)(nanodbc::connection connection, const TEAM& team, const USER& currentUser);
typedef void (*MENU_HANDLER_TEAM)(nanodbc::connection connection, TEAM& team, const USER& currentUser);

typedef void (*MENU_HANDLER_VIEW)(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser);

typedef void (*MENU_HANDLER_CONST_PROJECT)(nanodbc::connection connection, const PROJECT& team, const USER& currentUser);
typedef void (*MENU_HANDLER_PROJECT)(nanodbc::connection connection, PROJECT& team, const USER& currentUser);


struct MENU_OPTION_CONST_USER
{
	int number = 0;
	const char* message;
	MENU_HANDLER_CONST_USER handler;
};

struct MENU_OPTION_USER
{
	int number = 0;
	const char* message;
	MENU_HANDLER_USER handler;
};

struct MENU_OPTION_CONST_TEAM
{
	int number = 0;
	const char* message;
	MENU_HANDLER_CONST_TEAM handler;
};

struct MENU_OPTION_TEAM
{
	int number = 0;
	const char* message;
	MENU_HANDLER_TEAM handler;
};

struct MENU_OPTION_VIEW
{
	int number = 0;
	const char* message;
	MENU_HANDLER_VIEW handler;
};

struct MENU_OPTION_CONST_PROJECT
{
	int number = 0;
	const char* message;
	MENU_HANDLER_CONST_PROJECT handler;
};

struct MENU_OPTION_PROJECT
{
	int number = 0;
	const char* message;
	MENU_HANDLER_PROJECT handler;
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

void handleUserChoiceConstTeam(std::vector<MENU_OPTION_CONST_TEAM>&, nanodbc::connection, const TEAM&, const USER&);

void handleUserChoiceTeam(std::vector<MENU_OPTION_TEAM>&, nanodbc::connection, TEAM&, const USER&);

void handleUserChoiceView(std::vector<MENU_OPTION_VIEW>& options, nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser);

void handleUserChoiceProject(std::vector<MENU_OPTION_PROJECT>& options, nanodbc::connection connection, PROJECT& project, const USER& currentUser);

bool isInputInRange(size_t size, size_t inputSize);
