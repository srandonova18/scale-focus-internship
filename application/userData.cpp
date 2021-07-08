#include <iostream>
#include <conio.h>

#include "userData.h"
#include "helpers.h"

std::string inputName()
{
	std::string name;

	safeCin<std::string>(name);

	return name;
}

char* inputPassword(char* password)
{
	int numberOfSymbols = 0;
	while ((password[numberOfSymbols] = _getch()) != '\r')
	{
		std::cout << "*";
		numberOfSymbols++;
	}

	return password;
}