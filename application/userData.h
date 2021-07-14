#pragma once

#include <iostream>
#include <nanodbc.h>
#include <string>

#include "userDefine.h"

std::string inputString(size_t size, std::string message);

std::string inputPassword();

void insertUser(nanodbc::connection connection, const USER& user, const USER& currentUser);

USER findUserByUsernameAndPassword(nanodbc::connection connection, const USER& user);

void getAllUsers(nanodbc::connection connection, USER& user, const USER& currentUser);

void editUsername(nanodbc::connection connection, std::string username,
	const USER& user, const USER& currentUser);

void editUsernameMenu(nanodbc::connection connection, USER& user, const USER& currentUser);

void editPassword(nanodbc::connection connection, std::string password,
	const USER& user, const USER& currentUser);

void editPasswordMenu(nanodbc::connection connection, USER& user, const USER& currentUser);

void editFirstName(nanodbc::connection connection, std::string firstName,
	const USER& user, const USER& currentUser);

void editFirstNameMenu(nanodbc::connection connection, USER& user, const USER& currentUser);

void editLastName(nanodbc::connection connection, std::string lastName,
	const USER& user, const USER& currentUser);

void editLastNameMenu(nanodbc::connection connection, USER& user, const USER& currentUser);