#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "teamDefine.h"

void insertTeam(nanodbc::connection connection, const TEAM& team, const USER& currentUser);

void getAllTeams(nanodbc::connection connection, TEAM& team, const USER& currentUser);

TEAM findTeamById(nanodbc::connection connection, const TEAM& team);

void editTeamTitle(nanodbc::connection connection, std::string title,
	const TEAM& team, const USER& currentUser);

void editTeamTitleMenu(nanodbc::connection connection, TEAM& team, const USER& currentUser);


