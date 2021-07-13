#pragma once

#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "teamDefine.h"

void insertTeam(nanodbc::connection, const TEAM&, const USER&);

void getAllTeams(nanodbc::connection, TEAM&, const USER&);

TEAM findTeamById(nanodbc::connection connection, const TEAM& team);

void editTeamTitle(nanodbc::connection connection, std::string title, const TEAM& team, const USER& currentUser);

void editTeamTitleMenu(nanodbc::connection connection, TEAM& team, const USER& currentUser);


