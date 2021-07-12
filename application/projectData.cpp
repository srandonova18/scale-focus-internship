#include "projectData.h"
#include "projectPresentation.h"

void insertProject(nanodbc::connection connection, const PROJECT& project, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		INSERT INTO
			[project_management_application].[dbo].[projects]

		(title, description, creator_id, last_changer_id)

		VALUES
		(?, ?, ?, ?)
	)"));

	statement.bind(0, project.title.c_str());
	statement.bind(1, project.description.c_str());
	statement.bind(2, &currentUser.id);
	statement.bind(3, &currentUser.id);

	execute(statement);
}

void getAllProjects(nanodbc::connection connection, PROJECT& project, const USER& currentUser)
{
	PROJECT foundProject;

	nanodbc::statement statement(connection);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT
		*
	FROM [project_management_application].[dbo].[projects]
	)"));

	auto result = execute(statement);

	while (result.next())
	{
		foundProject.id = result.get<int>("id");
		foundProject.title = result.get<nanodbc::string>("title", "");
		foundProject.description = result.get<nanodbc::string>("description", "");
		foundProject.teamId = result.get<int>("team_id");
		foundProject.dateOfCreation = result.get<nanodbc::date>("date_of_creation");
		foundProject.creatorId = result.get<int>("creator_id");
		foundProject.dateOfLastChange = result.get<nanodbc::date>("date_of_last_change");
		foundProject.lastChangerId = result.get<int>("last_changer_id");
		//foundProject.isDeleted = result.get<int>("is_deleted");

		showProject(foundProject);
	}

	projectManagementView(connection, project, currentUser);
}

void editTitle(nanodbc::connection connection, std::string title, const PROJECT& project, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		UPDATE 
			[project_management_application].[dbo].[projects]
		SET
			title = ?,
			[date_of_last_change] = getdate()
			last_changer_id = ?
		WHERE
			id = ?	
	)"));

	statement.bind(0, title.c_str());
	statement.bind(1, &project.id);
	statement.bind(2, &currentUser.id);

	execute(statement);
}

void editDescription(nanodbc::connection connection, std::string description, const PROJECT& project, const USER& currentUser)
{
	nanodbc::statement statement(connection);

	nanodbc::prepare(statement, NANODBC_TEXT(R"(
		UPDATE 
			[project_management_application].[dbo].[projects]
		SET
			description = ?,
			[date_of_last_change] = getdate()
			last_changer_id = ?
		WHERE
			id = ?	
	)"));

	statement.bind(0, description.c_str());
	statement.bind(1, &project.id);
	statement.bind(2, &currentUser.id);

	execute(statement);
}

