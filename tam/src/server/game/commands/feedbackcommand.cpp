#include "feedbackcommand.h"
#include "../sessions/gamesession.h"
#include "logger/tri_logger.h"

using namespace server::game::commands;
using namespace server::game::sessions;
using namespace std;

#define FEEDBACK_RESPONSE_CMD "/feedback "

void FeedbackCommand::execute(
		client::GameClient* gameClient, const string& params) {

	string response = FEEDBACK_RESPONSE_CMD;
	response.append(params);
	gameClient->getGameSession()->broadcastMessage(response, gameClient);
	TRI_LOG_STR("FeedbackCommand: Se envio feedback de " + gameClient->getNick());
}
