#pragma once

#include <iostream>
#include <nanodbc.h>

struct PROJECT
{
	int id = 0;
	std::string title = "";
	std::string description = "";
	int teamId = 0;
	nanodbc::date dateOfCreation;
	int creatorId = 0;
	nanodbc::date dateOfLastChange;
	int lastChangerId = 0;
	bool isDeleted = false;
};

