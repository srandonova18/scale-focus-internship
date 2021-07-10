#pragma once

#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "teamDefine.h"

void insertTeam(nanodbc::connection, const TEAM&, const USER&);

void getAllTeams(nanodbc::connection, TEAM&, const USER&);

TEAM findTeamById(nanodbc::connection connection, const TEAM& team);

void editTitle(nanodbc::connection connection, std::string title, const TEAM& team, const USER& currentUser);

void editTitleMenu(nanodbc::connection connection, TEAM& team, const USER& currentUser);


