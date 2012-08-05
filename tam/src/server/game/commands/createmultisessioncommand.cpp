#include "createmultisessioncommand.h"
#include "../sessions/gamesessionmanager.h"
#include "logger/tri_logger.h"

using namespace server::game::commands;
using namespace server::game::sessions;
using namespace std;

void CreateMultiSessionCommand::execute(
		client::GameClient* gameClient, const string& params) {

	GameSessionManager& gameSessionMgr = GameSessionManager::getInstance();
	GameSession* gameSession = gameSessionMgr.createMultiPlayerGameSession();
	gameSessionMgr.addClientToGameSession(gameClient, gameSession);
	TRI_LOG_STR("CreateMultiSessionCommand: " + gameClient->getNick() 
			+ " ha iniciado una Sesion Multi Player.");			
}
