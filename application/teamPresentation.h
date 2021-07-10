#pragma once

#include "presentation.h"
#include "helpers.h"

std::vector<MENU_OPTION_TEAM> initializeTeamManagementViewMenuOptions();

void teamManagementView(nanodbc::connection, TEAM&, const USER&);



