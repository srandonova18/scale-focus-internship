#pragma once

#include <nanodbc.h>

#include "userDefine.h"

typedef void (*MENU_HADLER)();

struct MENU_OPTION
{
	int number = 0;
	const char* message;
	MENU_HADLER handler;
};

USER loginMenu(nanodbc::connection);