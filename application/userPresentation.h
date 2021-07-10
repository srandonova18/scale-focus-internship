#pragma once

#include "presentation.h"

std::vector<MENU_OPTION> initializeUserManagementViewMenuOptions();

void userManagementView(nanodbc::connection, const USER&);

