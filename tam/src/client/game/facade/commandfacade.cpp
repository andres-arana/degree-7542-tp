#include "commandfacade.h"
#include "../commands/commandfactory.h"
#include "../commands/command.h"
#include "../model/outcomingrequestqueue.h"

#define LEVEL_FAILED "-1"

using namespace client::game::facade;
using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

CommandFacade::CommandFacade() {
	
}

CommandFacade::~CommandFacade() {
	
}

void CommandFacade::addRequest(const string& cmdName, const string& params) {
	client::game::commands::Command* command 
			= CommandFactory::getInstance().getCommandByName(cmdName);
	command->setParams(params);
	OutcomingRequestQueue::getInstance().addRequest(command);
}

void CommandFacade::login(const string& loginName) {
	CommandFacade::addRequest(LOGIN_CMD, loginName);
}

void CommandFacade::getAvailableSessions() {
	CommandFacade::addRequest(SESSIONS_CMD);
}

void CommandFacade::joinSession(const string& sessionId) {
	CommandFacade::addRequest(JOIN_CMD, sessionId);
}

void CommandFacade::createSinglePlayerSession() {
	CommandFacade::addRequest(CREATE_SINGLE_CMD);
}

void CommandFacade::createMultiPlayerSession() {
	CommandFacade::addRequest(CREATE_MULTI_CMD);
}

void CommandFacade::getNextLevel() {
	CommandFacade::addRequest(LEVEL_CMD);
}

void CommandFacade::sendChatMessage(const string& message) {
	CommandFacade::addRequest(MESSAGE_CMD, message);
}

void CommandFacade::markLevelAsCompleted(const string& score) {
	CommandFacade::addRequest(LEVEL_COMPLETED_CMD, score);
}

void CommandFacade::markLevelAsFailed() {
	CommandFacade::addRequest(LEVEL_COMPLETED_CMD, LEVEL_FAILED);
}

void CommandFacade::sendFeedback(const string& feedbackStr) {
	CommandFacade::addRequest(FEEDBACK_CMD, feedbackStr);
}
