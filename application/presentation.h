#pragma once

#include "userDefine.h"
#include "teamDefine.h"
#include "helpers.h"

struct MENU_OPTION_VIEW;

USER loginMenu(nanodbc::connection);

bool isAdmin(const USER&);

std::vector<MENU_OPTION_VIEW> initializeMainMenuOptions();

void teamManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, const USER& currentUser);

void userManagementViewWrapper(nanodbc::connection connection, USER& user, TEAM& team, const USER& currentUser);

void mainMenu(nanodbc::connection connection, USER& user, TEAM& team, const USER& currentUser);