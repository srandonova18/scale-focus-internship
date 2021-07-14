#pragma once

#include <iostream>
#include <nanodbc.h>

struct WORK_LOG
{
	int id = 0;
	int taskId = 0;
	int userId = 0;
	float hoursSpent = 0.0;
	nanodbc::date date = { 0, 0, 0 };
	bool isDeleted = false;
};
