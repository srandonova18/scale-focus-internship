#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "projectDefine.h"
#include "userDefine.h"

void insertProject(nanodbc::connection connection, const PROJECT& project, const USER& currentUser);

void getAllProjects(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

void editProjectTitle(nanodbc::connection connection, std::string title,
	const PROJECT& project, const USER& currentUser);

void editProjectDescription(nanodbc::connection connection, std::string description,
	const PROJECT& project, const USER& currentUser);

void editProjectTitleMenu(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

void editProjectDescriptionMenu(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

bool isCreator(PROJECT project, USER currentUser);

PROJECT getProjectById(nanodbc::connection connection, int id);
