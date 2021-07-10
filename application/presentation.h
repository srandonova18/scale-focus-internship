#pragma once

#include <nanodbc.h>

typedef void (*MENU_HADLER)();

struct MENU_OPTION
{
	int number = 0;
	const char* message;
	MENU_HADLER handler;
};

void loginMenu(nanodbc::connection);