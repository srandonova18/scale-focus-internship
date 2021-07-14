#pragma once

#include <iostream>
#include <nanodbc.h>

struct USER
{
	int id = 0;
	std::string username = "";
	std::string password = "";
	std::string firstName = "";
	std::string lastName = "";
	nanodbc::date dateOfCreation = { 0, 0, 0 };
	int creatorId = 0;
	nanodbc::date dateOfLastChange = { 0, 0, 0 };
	int lastChangerId = 0;
	bool isDeleted = false;
};

void addUser(nanodbc::connection connection, USER& newUser, const USER& currentUser);

void showUser(USER user);
