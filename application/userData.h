#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>
#include "userDefine.h"

std::string inputName();

std::string inputPassword();

void insertUser(nanodbc::connection, const USER&);

USER findUserByUsernameAndPassword(nanodbc::connection, const USER&);