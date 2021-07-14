#pragma once

#include <iostream>
#include <nanodbc.h>

#include "userDefine.h"

struct PROJECT
{
	int id = 0;
	std::string title = "";
	std::string description = "";
	int teamId = 0;
	nanodbc::date dateOfCreation = { 0, 0, 0 };
	int creatorId = 0;
	nanodbc::date dateOfLastChange = { 0, 0, 0 };
	int lastChangerId = 0;
	bool isDeleted = false;
};

void addProject(nanodbc::connection connection, PROJECT& newProject, const USER& currentUser);

void showProject(PROJECT project);

