#pragma once

#include <iostream>
#include <nanodbc.h>

struct USER
{
	int id = 0;
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	nanodbc::date dateOfCreation;
	int creatorId = 0;
	nanodbc::date dateOfLastChange;
	int lastChangerId = 0;
	bool isDeleted = false;

	void addUser(nanodbc::connection);
	void showUser(USER);
};

void insertUser(nanodbc::connection connection, const USER& user);
