#pragma once

#include <nanodbc.h>

#include "userDefine.h"
#include "teamDefine.h"

USER loginMenu(nanodbc::connection);

bool isAdmin(const USER&);