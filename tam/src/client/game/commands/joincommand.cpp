#include "joincommand.h"

#define JOIN_REQUEST_CMD "/join "
#define JOIN_SUCCESS "1"
#define OPPONENT_CONNECTED "2"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string JoinCommand::buildRequest() const {
	string joinRequest = JOIN_REQUEST_CMD;
	joinRequest.append(this->params);
	return joinRequest;
}
		
void JoinCommand::executeResponse(GameClient* gameClient) {
	gameClient->setJoinSuccess(this->params == JOIN_SUCCESS);
	gameClient->setOpponentConnected(this->params == OPPONENT_CONNECTED);
	Command::executeResponse(gameClient);	
}
