#include <iostream>
#include <conio.h>

#include "presentation.h"
#include "helpers.h"

void loginMenu()
{
	std::string username;
	
	//std::cout << "Login" << std::endl;
	std::cout << "username: ";
	safeCin<std::string>(username);
	std::cout << username << std::endl;
	std::cout << "password: ";
}




