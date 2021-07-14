#pragma once

#include "presentation.h"
#include "helpers.h"

std::vector<MENU_OPTION_USER> initializeUserManagementViewMenuOptions();

void userManagementView(nanodbc::connection connection, USER& user, const USER& currentUser);

std::vector<MENU_OPTION_USER> initializeEditUserMenuOptions();

void editUserMenu(nanodbc::connection connection, USER& user, const USER& currentUser);

void stillUnderDevelopmentMessage(nanodbc::connection connection, USER& user, const USER& currentUser);

void mainMenuAdminToUserWrapper(nanodbc::connection connection, USER& user, const USER& currentUser);

