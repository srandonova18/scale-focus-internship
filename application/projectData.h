#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "projectDefine.h"
#include "userDefine.h"

void insertProject(nanodbc::connection, const PROJECT&, const USER&);

void getAllProjects(nanodbc::connection, PROJECT&, const USER&);

void editProjectTitle(nanodbc::connection, std::string, const PROJECT&, const USER&);

void editProjectDescription(nanodbc::connection connection, std::string, const PROJECT&, const USER&);

void editProjectTitleMenu(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

void editProjectDescriptionMenu(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

bool isCreator(PROJECT project, USER currentUser);

PROJECT getProjectById(nanodbc::connection connection, int id);
