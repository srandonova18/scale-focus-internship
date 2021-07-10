#include "teamData.h"

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
