#include "teamData.h"
#include "teamPresentation.h"
#include "userData.h"

void insertTeam(nanodbc::connection connection, const TEAM& team, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		INSERT INTO
			[project_management_application].[dbo].[teams]

		(title, creator_id, last_changer_id)

		VALUES
		(?, ?, ?)
	)"));

	statement.bind(0, team.title.c_str());
	statement.bind(1, &currentUser.id);
	statement.bind(2, &currentUser.id);

	execute(statement);
}

void getAllTeams(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	TEAM foundTeam;

	nanodbc::statement statement(connection);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT
		*
	FROM [project_management_application].[dbo].[teams]
	)"));

	auto result = execute(statement);

	while (result.next())
	{
		foundTeam.id = result.get<int>("id");
		foundTeam.title = result.get<nanodbc::string>("title", "");
		foundTeam.dateOfCreation = result.get<nanodbc::date>("date_of_creation");
		foundTeam.creatorId = result.get<int>("creator_id");
		foundTeam.dateOfLastChange = result.get<nanodbc::date>("date_of_last_change");
		foundTeam.lastChangerId = result.get<int>("last_changer_id");
		foundTeam.isDeleted = result.get<int>("is_deleted");

		showTeam(foundTeam);
	}

	teamManagementView(connection, team, currentUser);
}

TEAM findTeamById(nanodbc::connection connection, const TEAM& team)
{
	TEAM foundTeam;

	nanodbc::statement statement(connection);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT
		*
	FROM [project_management_application].[dbo].[teams]
	WHERE
		Id = ?
	)"));

	statement.bind(0, &team.id);

	auto result = execute(statement);

	if (result.next())
	{
		foundTeam.id = result.get<int>("id");
		foundTeam.title = result.get<nanodbc::string>("title", "");
		foundTeam.dateOfCreation = result.get<nanodbc::date>("date_of_creation");
		foundTeam.creatorId = result.get<int>("creator_id");
		foundTeam.dateOfLastChange = result.get<nanodbc::date>("date_of_last_change");
		foundTeam.lastChangerId = result.get<int>("last_changer_id");
		foundTeam.isDeleted = result.get<int>("is_deleted");
	}

	return foundTeam;
}

void editTitle(nanodbc::connection connection, std::string title, const TEAM& team, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		UPDATE 
			[project_management_application].[dbo].[teams]
		SET
			[title] = ?,
			[date_of_last_change] = getdate()
		WHERE
			id = ?	
	)"));

	statement.bind(0, title.c_str());
	statement.bind(1, &team.id);

	execute(statement);
}

void editTitleMenu(nanodbc::connection connection, TEAM& team, const USER& currentUser)
{
	std::string newTitle;

	std::cout << std::endl << "Enter new title name: ";
	newTitle = inputName();

	editTitle(connection, newTitle, team, currentUser);

	std::cout << std::endl << "The title was edited successfully." << std::endl;

	//editTeamMenu(connection, user, currentUser);
}
