#include "availablesessionscommand.h"
#include "logger/tri_logger.h"

#define AVAILABLE_SESSIONS_REQUEST_CMD "/sessions"
#define REC_SEPARATOR '\30'

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

list<Session*>* AvailableSessionsCommand::parseSessionList() {
	list<Session*>* sessionList = new list<Session*>();
	size_t posSep = 0;
	size_t posId = this->params.find(REC_SEPARATOR);
	while (posId != string::npos && posSep != string::npos) {
		string id = this->params.substr(posSep, posId - posSep);
		posSep = this->params.find(REC_SEPARATOR, posId + 1);
		string name = this->params.substr(posId + 1, posSep - posId - 1);
		sessionList->push_back(new Session(id, name));
		TRI_LOG_STR("AvailableSessionsCommand: Session(" + id + ", " + name + ")");
		posId = this->params.find(REC_SEPARATOR, ++posSep);
	}
	return sessionList;
}

string AvailableSessionsCommand::buildRequest() const {
	return AVAILABLE_SESSIONS_REQUEST_CMD;
}
		
void AvailableSessionsCommand::executeResponse(GameClient* gameClient) {
	Command::executeResponse(gameClient);
	list<Session*>* sessionList = this->parseSessionList();
	gameClient->setAvailableSessions(sessionList);
}
