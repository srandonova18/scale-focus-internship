#pragma once

#include "presentation.h"
#include "helpers.h"

std::vector<MENU_OPTION_USER> initializeUserManagementViewMenuOptions();

void userManagementView(nanodbc::connection, USER&, const USER&);

std::vector<MENU_OPTION_USER> initializeEditUserMenuOptions();

void editUserMenu(nanodbc::connection, USER&, const USER&);

void mainMenuAdminToUserWrapper(nanodbc::connection connection, USER& user, const USER& currentUser);

