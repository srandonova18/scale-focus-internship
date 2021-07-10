#pragma once

#include <nanodbc.h>

#include "userDefine.h"

USER loginMenu(nanodbc::connection);

bool isAdmin(const USER&);