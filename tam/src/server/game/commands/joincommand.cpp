#include "joincommand.h"
#include "../messages/servermessages.h"
#include "../sessions/gamesessionmanager.h"
#include "utils/stringutils.h"
#include "logger/tri_logger.h"

using namespace server::game::commands;
using namespace server::game::messages;
using namespace server::game::sessions;
using namespace common::utils;
using namespace std;  

#define JOIN_RESPONSE_CMD "/join "
#define ERROR_FLAG "0"
#define SUCCESS_FLAG "1"
#define OPPONENT_FLAG "2"

void JoinCommand::execute(
		client::GameClient* gameClient, const string& sessionIdStr) {
	
	GameSessionManager& gameSessionMgr = GameSessionManager::getInstance(); 
	string joinResponse = JOIN_RESPONSE_CMD;   		
	int sessionId = StringUtils::stringToNumber<int>(sessionIdStr);
	GameSession* gameSession = gameSessionMgr.getGameSessionById(sessionId);
	
	if (!gameSession || gameSession->isFull()) {
		joinResponse.append(ERROR_FLAG);
		TRI_LOG_STR("JoinCommand: La sesion esta llena. " + gameClient->getNick() 
				+ " no pudo unirse.");				
	} else {
		// Se le notifica los Jugadores que ya se encontraban en la sesion.
		string opponentResponse = JOIN_RESPONSE_CMD;
		opponentResponse.append(OPPONENT_FLAG);		
		gameSession->broadcastMessage(opponentResponse);
		joinResponse.append(SUCCESS_FLAG);
		gameSessionMgr.addClientToGameSession(gameClient, gameSession);		
		string message = MSG_RESPONSE_CMD;
		message
				.append(gameClient->getNick())
				.append(ServerMessages::ON_LOGIN_SUFFIX);								
		gameSession->broadcastMessage(message);			
		TRI_LOG_STR("JoinCommand: " + gameClient->getNick() 
				+ " se ha unido al Game Session " + sessionIdStr);
	}
	gameClient->sendMessage(joinResponse);
}
