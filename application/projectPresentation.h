#pragma once

#include "helpers.h"
#include "projectDefine.h"

std::vector<MENU_OPTION_PROJECT> initializeProjectManagementViewMenuOptions();

void projectManagementView(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

void projectManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team,
	PROJECT& project, const USER& currentUser);

void mainMenuUserToProjectWrapper(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

void stillUnderDevelopmentMessage(nanodbc::connection connection, PROJECT& project, const USER& currentUser);

void editProjectMenu(nanodbc::connection connection, PROJECT& project, const USER& currentUser);
