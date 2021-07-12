#pragma once

#include "helpers.h"
#include "projectDefine.h"

std::vector<MENU_OPTION_PROJECT> initializeProjectManagementViewMenuOptions();

void projectManagementView(nanodbc::connection connection, PROJECT& project, const USER& currentUser);
