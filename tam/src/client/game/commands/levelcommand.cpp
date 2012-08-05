#include "levelcommand.h"
#include "logger/tri_logger.h"
#include "utils/stringutils.h"
#include "constants/gameconstants.h"
#include <fstream>

#define LEVEL_REQUEST_CMD "/level"
#define NO_MORE_LEVELS "0"

using namespace client::game::commands;
using namespace client::game::model;
using namespace common::constants;
using namespace common::protocol;
using namespace common::sockets;
using namespace common::utils;
using namespace std;

void LevelCommand::receiveFile(TcpSocket* tcpSocket, 
		long fileSize, const string& destination, ios_base::openmode mode) {
	
	long totalBytesReceived = 0;
	long bytesLeft = fileSize;
	ofstream file(destination.c_str(), mode);
	const Data* data = NULL;    
  while (totalBytesReceived < fileSize) {
  	data = this->protocolReceiver.receiveFromSocket(*tcpSocket);
  	file.write(data->getData(), data->getLength());
  	totalBytesReceived += data->getLength();
  	bytesLeft -= data->getLength();
  	delete data;
  }
  file.close();  	
}

long LevelCommand::getSizeFromHeader(TcpSocket* tcpSocket) {
	string header 
			= this->protocolReceiver.receiveStrFromSocket(*tcpSocket);
	TRI_LOG(header);
	size_t space = header.find(WHITESPACE);
	string sizeStr = header.substr(space + 1);
	return StringUtils::stringToNumber<long>(sizeStr);
}

void LevelCommand::receiveXml(TcpSocket* tcpSocket) {
	long xmlSize = this->getSizeFromHeader(tcpSocket);
	TRI_LOG(xmlSize);
	string destination 
			= GameConstants::TEMP_FOLDER_PATH + GameConstants::LEVEL_FILENAME;
	TRI_LOG(destination);
	this->receiveFile(tcpSocket, xmlSize, destination);	
}

void LevelCommand::receiveImage(TcpSocket* tcpSocket) {
	long imageSize = this->getSizeFromHeader(tcpSocket);
	TRI_LOG(imageSize);
	string destination 
			= GameConstants::TEMP_FOLDER_PATH + GameConstants::BACKGROUND_IMAGE_NAME;
	TRI_LOG(destination);
	this->receiveFile(tcpSocket, imageSize, destination, ios_base::binary);	
}

void LevelCommand::receiveLevel(GameClient* gameClient) {
	TcpSocket* tcpSocket = gameClient->getSocket();
	this->receiveImage(tcpSocket);
	this->receiveXml(tcpSocket);	
}

string LevelCommand::buildRequest() const {
	return LEVEL_REQUEST_CMD;
}
		
void LevelCommand::executeResponse(GameClient* gameClient) {
	string levelNumber = this->params;
	if (levelNumber != NO_MORE_LEVELS) {
		this->receiveLevel(gameClient);
		gameClient->setMoreLevels(true);
	} else {
		gameClient->setMoreLevels(false);
		TRI_LOG_STR("LevelCommand: No hay mas niveles.");		
	}
	Command::executeResponse(gameClient);			
}
