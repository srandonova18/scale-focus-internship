#pragma once

#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"

struct TEAM
{
	int id = 0;
	std::string title = "";
	nanodbc::date dateOfCreation;
	int creatorId = 0;
	nanodbc::date dateOfLastChange;
	int lastChangerId = 0;
	bool isDeleted = false;
};

void addTeam(nanodbc::connection connection, TEAM& team, const USER& currentUser);

