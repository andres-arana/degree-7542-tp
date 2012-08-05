#include "levelcompletedcommand.h"

#define LEVEL_COMPLETED_REQUEST_CMD "/levelCompleted "

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string LevelCompletedCommand::buildRequest() const {
	string levelCompletedRequest = LEVEL_COMPLETED_REQUEST_CMD;
	levelCompletedRequest.append(this->params);
	return levelCompletedRequest;
}
		
void LevelCompletedCommand::executeResponse(GameClient* gameClient) {
	// No se espera respuesta del servidor.
}
