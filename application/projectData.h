#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "projectDefine.h"
#include "userDefine.h"

void insertProject(nanodbc::connection, const PROJECT&, const USER&);

void getAllProjects(nanodbc::connection, PROJECT&, const USER&);
