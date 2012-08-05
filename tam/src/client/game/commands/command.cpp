#include "command.h"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

Command::Command() {
	
}

Command::~Command() {
	
}

void Command::setParams(const string& params) {
	this->params = params;
}

void Command::executeResponse(GameClient* gameClient) {
	gameClient->setResponseReceived(true);
}
