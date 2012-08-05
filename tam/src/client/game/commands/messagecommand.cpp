#include "messagecommand.h"
#include "../model/incomingmessagequeue.h"
#include "../model/message.h"

#define MESSAGE_REQUEST_CMD "/msg "

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string MessageCommand::buildRequest() const {
	string messageRequest = MESSAGE_REQUEST_CMD;
	messageRequest.append(this->params);
	return messageRequest;
}
		
void MessageCommand::executeResponse(GameClient* gameClient) {
	IncomingMessageQueue::getInstance().addMessageToQueue(
			Message::createMessage(this->params));	
}
