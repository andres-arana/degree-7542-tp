#include "feedbackcommand.h"

#define FEEDBACK_CMD "/feedback "
#define JOIN_SUCCESS "1"
#define OPPONENT_CONNECTED "2"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string FeedbackCommand::buildRequest() const {
	string feedbackDispatch = FEEDBACK_CMD;
	feedbackDispatch.append(this->params);
	return feedbackDispatch;
}
		
void FeedbackCommand::executeResponse(GameClient* gameClient) {
	gameClient->setFeedbackStr(this->params);
	Command::executeResponse(gameClient);	
}
