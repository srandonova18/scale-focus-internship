#pragma once

#include "userDefine.h"
#include "teamDefine.h"
#include "projectDefine.h"
#include "helpers.h"

struct MENU_OPTION_VIEW;

USER loginMenu(nanodbc::connection);

bool isAdmin(const USER&);

bool isRegistered(const USER&);

std::vector<MENU_OPTION_VIEW> initializeMainMenuAdminOptions();

void teamManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser);

void userManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser);

void mainMenuAdmin(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser);

std::vector<MENU_OPTION_VIEW> initializeMainMenuUserOptions();

void mainMenuUser(nanodbc::connection connection, USER& user, TEAM& team, PROJECT& project, const USER& currentUser);

void mainMenu(nanodbc::connection connection);
