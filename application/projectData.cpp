#include "projectData.h"

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
	statement.bind(4, &currentUser.id);
	statement.bind(5, &currentUser.id);

	execute(statement);
}
