#include "levelstartcommand.h"
#include "logger/tri_logger.h"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string LevelStartCommand::buildRequest() const {
	// Es una senial del server. No deberia haber request.
	return "";
}

void LevelStartCommand::executeResponse(GameClient* gameClient) {
	gameClient->setLevelStart(true);
	Command::executeResponse(gameClient);
}
