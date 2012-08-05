#include "messagecommand.h"
#include "../sessions/gamesession.h"
#include "logger/tri_logger.h"

using namespace server::game;
using namespace server::game::commands;
using namespace server::game::sessions;
using namespace std;

void MessageCommand::execute(
		client::GameClient* gameClient, const string& message) {   
  
  string msgToSend = MSG_RESPONSE_CMD;
  msgToSend.append(1, REC_SEPARATOR) // Inicio del Nick.
      .append(gameClient->getNick())
      .append(1, REC_SEPARATOR) // Fin del Nick.
      .append(message);
	
	GameSession* gameSession = gameClient->getGameSession();
	// Siempre deberia estar en una sesion si esta mandando un mensaje.	
	if (gameSession) { 
		gameSession->broadcastMessage(msgToSend);      
  	TRI_LOG_STR("MessageCommand - Se envio: " + msgToSend);
	}
}
