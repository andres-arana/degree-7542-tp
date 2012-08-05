#include "levelcompletedcommand.h"
#include "../sessions/gamesession.h"
#include "../levels/levelmanager.h"
#include "logger/tri_logger.h"
#include "utils/stringutils.h"

#define NOT_COMPLETED "-1"

using namespace server::game;
using namespace server::game::commands;
using namespace server::game::levels;
using namespace server::game::sessions;
using namespace common::utils;
using namespace std;

void LevelCompletedCommand::execute(
		client::GameClient* gameClient, const string& params) {
  
  GameSession* gameSession = gameClient->getGameSession();
  string completedMessage = MSG_RESPONSE_CMD;
  if (params != NOT_COMPLETED) {
	  TRI_LOG_STR("LevelCompletedCommand - Nivel completado.");
	  int score = StringUtils::stringToNumber<int>(params);
	  TRI_LOG(score);
	  gameClient->addScore(score);			
		completedMessage
			.append("Felicitaciones ")
			.append(gameClient->getNick())
			.append("! Has completado el Nivel con ")
			.append(params)
			.append(" puntos.");			       	
  } else {
  	completedMessage
  		.append(gameClient->getNick())
  		.append(" no ha podido completar el nivel.");
  }
  gameSession->broadcastMessage(completedMessage);
}
