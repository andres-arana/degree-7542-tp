#include "availablesessionscommand.h"
#include "../sessions/gamesessionmanager.h"
#include "utils/stringutils.h"
#include "logger/tri_logger.h"
#include <list>

#define SESSIONS_RESPONSE_CMD "/sessions "

using namespace server::game::commands;
using namespace server::game::sessions;
using namespace common::utils;
using namespace std;

void AvailableSessionsCommand::execute(		
		client::GameClient* gameClient, const string& params) {
	
	string sessionsResponse = SESSIONS_RESPONSE_CMD;
	list<GameSession*>::const_iterator i;
	list<GameSession*> gameSessions 
			= GameSessionManager::getInstance().getGameSessions();
	for (i = gameSessions.begin(); i != gameSessions.end(); ++i) {
		if ((*i)->isMultiplayer() && !(*i)->isFull()) {
			string session;
			session					
					.append(StringUtils::numberToString<int>((*i)->getSessionId()))
					.append(1, REC_SEPARATOR)
					.append((((*i)->getGameClients())[0])->getNick())
					.append(1, REC_SEPARATOR);
			sessionsResponse.append(session);
		}
	}
	gameClient->sendMessage(sessionsResponse);
	TRI_LOG_STR("AvailableSessionsCommand: Las sesiones fueron enviadas a " +
			gameClient->getNick()); 
}
