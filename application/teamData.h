#pragma once

#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "teamDefine.h"

void insertTeam(nanodbc::connection, const TEAM&, const USER&);


