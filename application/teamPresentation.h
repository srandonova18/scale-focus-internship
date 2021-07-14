#pragma once

#include "presentation.h"
#include "helpers.h"

using namespace std;

std::vector<MENU_OPTION_TEAM> initializeTeamManagementViewMenuOptions();

void teamManagementView(nanodbc::connection connection, TEAM& team, const USER& currentUser);

std::vector<MENU_OPTION_TEAM> initializeEditTeamMenuOptions();

void editTeamMenu(nanodbc::connection connection, TEAM& team, const USER& currentUser);

void stillUnderDevelopmentMessage(nanodbc::connection connection, TEAM& team, const USER& currentUser);

void mainMenuAdminToTeamWrapper(nanodbc::connection connection, TEAM& team, const USER& currentUser);



