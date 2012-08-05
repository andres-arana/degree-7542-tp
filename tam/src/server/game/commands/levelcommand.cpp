#include "levelcommand.h"
#include "../levels/level.h"
#include "../levels/exceptions/nomorelevelsexception.h"
#include "../sessions/gamesession.h"
#include "../messages/servermessages.h"
#include "utils/stringutils.h"
#include "logger/tri_logger.h"
#include "sockets/data.h"
#include <fstream>

#define LEVEL_RESPONSE_CMD "/level "
#define IMAGE_RESPONSE_CMD "/img "
#define DESCRIPTOR_RESPONSE_CMD "/xml "
#define LEVEL_START_CMD "/levelStart "
#define CHUNK_SIZE 5120
#define NO_MORE_LEVELS_FLAG "0"

using namespace server::game::commands;
using namespace server::game::levels;
using namespace server::game::levels::exceptions;
using namespace server::game::messages;
using namespace server::game::sessions;
using namespace common::utils;
using namespace common::sockets;
using namespace std;

void LevelCommand::sendFile(client::GameClient* gameClient, const string& path, 
		long fileLength) {
	
	int chunkSize;		
	long bytesRead, bytesLeft, totalBytesSent = 0;
	bytesLeft = fileLength;
	ifstream file(path.c_str(), ios::in);
	while (totalBytesSent < fileLength) {
		chunkSize = bytesLeft < CHUNK_SIZE ? bytesLeft : CHUNK_SIZE;
		char* buffer = new char[chunkSize];
		file.read(buffer, chunkSize);
		bytesRead = file.gcount();
		Data* data = new Data(buffer, bytesRead, false);
		gameClient->sendMessage(data);
		totalBytesSent += bytesRead;
		bytesLeft -= bytesRead;
	}
	file.close();
}

void LevelCommand::sendLevelHeader(
		client::GameClient* gameClient, const Level& level) {
	
	string header = LEVEL_RESPONSE_CMD 
			+ StringUtils::numberToString<int>(level.getLevelNumber());
	gameClient->sendMessage(header);
	TRI_LOG_STR("LevelCommand: levelHeader --> " + header); 
}

void LevelCommand::sendBackgroundImage(
		client::GameClient* gameClient, const Level& level) {
	
	long imageLength = level.getLevelBackgroundSize();
	TRI_LOG(imageLength);
	string imageResponseHeader = IMAGE_RESPONSE_CMD 
			+ StringUtils::numberToString<long>(imageLength);
	gameClient->sendMessage(imageResponseHeader);
	TRI_LOG_STR("LevelCommand: backgroundImageHeader --> " + imageResponseHeader);
	this->sendFile(gameClient, level.getLevelBackgroundPath(), imageLength);
}

void LevelCommand::sendLevelDescriptor(
		client::GameClient* gameClient, const Level& level) {
	
	long xmlLength = level.getLevelFileSize();
	string xmlResponseHeader = DESCRIPTOR_RESPONSE_CMD 
			+ StringUtils::numberToString<long>(xmlLength);
	gameClient->sendMessage(xmlResponseHeader);
	TRI_LOG_STR("LevelCommand: xmlResponseHeader --> " + xmlResponseHeader);
	this->sendFile(gameClient, level.getLevelFilePath(), xmlLength);
}

void LevelCommand::execute(
		client::GameClient* gameClient, const string& params) {	
	
	sessions::GameSession* gameSession = gameClient->getGameSession();		
	try {
		LevelManager& levelManager = gameSession->getLevelManager(); 
		Level level = levelManager.getCurrentLevel();
		this->sendLevelHeader(gameClient, level);
		this->sendBackgroundImage(gameClient, level);
		this->sendLevelDescriptor(gameClient, level);
		TRI_LOG_STR("LevelCommand: Nivel " 
				+ StringUtils::numberToString<int>(level.getLevelNumber()) 
				+ " enviado a " + gameClient->getNick());
		levelManager.markCurrentLevelAsSent();
		if (gameSession->hasLevelToStart()) {
			gameSession->broadcastMessage(LEVEL_START_CMD);
			levelManager.prepareNextLevel();
			TRI_LOG_STR("LevelCommand: Senial de Comienzo de Nivel enviada.");
		}	
	} catch (const NoMoreLevelsException& e) {
		string finalScoreMsg = MSG_RESPONSE_CMD;
		finalScoreMsg
				.append(ServerMessages::TOTAL_SCORE)
				.append(gameClient->getNick())
				.append(": ")
				.append(StringUtils::numberToString<int>(gameClient->getTotalScore()));
		
		string levelResponse = LEVEL_RESPONSE_CMD;
		levelResponse.append(NO_MORE_LEVELS_FLAG);
		gameClient->sendMessage(levelResponse);
		gameSession->broadcastMessage(finalScoreMsg);
		
		TRI_LOG_STR("LevelCommand: No hay mas niveles para " 
				+ gameClient->getNick());	
	}
}
