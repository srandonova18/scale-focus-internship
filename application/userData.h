#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "userDefine.h"

std::string inputName();

std::string inputPassword();

void insertUser(nanodbc::connection, const USER&, const USER&);

USER findUserByUsernameAndPassword(nanodbc::connection, const USER&);

void getAllUsers(nanodbc::connection, USER&, const USER&);

void editUsername(nanodbc::connection, std::string, const USER&, const USER&);

void editUsernameMenu(nanodbc::connection, USER&, const USER&);

void editPassword(nanodbc::connection, std::string, const USER&, const USER&);

void editPasswordMenu(nanodbc::connection connection, USER& user, const USER& currentUser);

void editFirstName(nanodbc::connection, std::string, const USER&, const USER&);

void editFirstNameMenu(nanodbc::connection connection, USER& user, const USER& currentUser);

void editLastName(nanodbc::connection, std::string, const USER&, const USER&);

void editLastNameMenu(nanodbc::connection connection, USER& user, const USER& currentUser);