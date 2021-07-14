#pragma once

#include <iostream>
#include <nanodbc.h>

enum STATUS
{
	PENDING,
	IN_PROGRESS,
	COMPLETED,
	UNKNOWN
};

struct TASK
{
	int id = 0;
	int assigneeId = 0;
	std::string title = "";
	std::string description = "";
	STATUS status = STATUS::UNKNOWN;
	nanodbc::date dateOfCreation = { 0, 0, 0 };
	int creatorId = 0;
	nanodbc::date dateOfLastChange = { 0, 0, 0 };
	int lastChangerId = 0;
	bool isDeleted = false;
};
