#pragma once

#include<iostream>
//#include<nanodbc.h>

struct USER
{
	int id = 0;
	std::string username;
	char password[10];
	std::string firstName;
	std::string lastName;
	//nanodbc::date dateOfCreation;
	int creatorId = 0;
	//nanodbc::date dateOfLastChange;
	int lastChangerId = 0;

	USER addUser();
	void showUser(USER);
};
