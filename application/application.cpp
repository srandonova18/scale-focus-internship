#include <iostream>
#include <nanodbc.h>
#include <exception>
#include <conio.h>

#include "presentation.h"
#include "helpers.h"

using namespace std;

int main()
{
    try
    {
        nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};SERVER=DESKTOP-U38BG7I\\SQLEXPRESS;DATABASE=project_management_application;Trusted_Connection=yes;"); // an ODBC connection string to your database

        nanodbc::connection conn(connstr);

        return EXIT_SUCCESS;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}


