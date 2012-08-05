#include "createsinglesessioncommand.h"
#include "../sessions/gamesessionmanager.h"
#include "logger/tri_logger.h"

using namespace server::game::commands;
using namespace server::game::sessions;
using namespace std;

void CreateSingleSessionCommand::execute(
		client::GameClient* gameClient, const string& params) {

	GameSessionManager& gameSessionMgr = GameSessionManager::getInstance();
	GameSession* gameSession = gameSessionMgr.createSinglePlayerGameSession();
	gameSessionMgr.addClientToGameSession(gameClient, gameSession);
	TRI_LOG_STR("CreateSingleSessionCommand: " + gameClient->getNick() 
			+ " ha iniciado una Sesion Single Player.");			
}
