#include "serverlistener.h"
#include "gameclient.h"
#include "../commands/command.h"
#include "../commands/commandfactory.h"
#include "../commands/exceptions/commandexception.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "sockets/tcpsocket.h"
#include "logger/tri_logger.h"

#define WHITESPACE ' '

using namespace client::game::model;
using namespace client::game::commands;
using namespace client::game::commands::exceptions;
using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::threads;
using namespace common::protocol;
using namespace std;

ServerListener::ServerListener(GameClient* gameClient) : 
	gameClient(gameClient) {
	
}

ServerListener::~ServerListener() {
	
}

void ServerListener::parseResponse(const string& response) {
	string cmdName = response;
	string param = "";
	// Busco Params.
	size_t space = cmdName.find(WHITESPACE);
	if (space != string::npos) {
		param = cmdName.substr(space + 1);
		cmdName.erase(space);
	}
	try {
		TRI_LOG_STR("ServerListener: Response recibido --> " + response);
		Command* command = CommandFactory::getInstance().getCommandByName(cmdName);
		command->setParams(param);
		command->executeResponse(this->gameClient);
		delete command;
	} catch (const CommandException& e) {
		TRI_LOG_STR("ServerListener: El comando " + cmdName 
				+ " no existe o se produjo un error al ejecutarlo.");
	}
}

void ServerListener::run() {
	TcpSocket* tcpSocket = this->gameClient->getSocket();
	while (!this->isStopped()) {
		try {
			string response = this->protocolReceiver.receiveStrFromSocket(*tcpSocket);
			this->parseResponse(response);		
		} catch (const TcpSocketException& e) {
			this->stop();
			TRI_LOG_STR("ServerListener Detenido.");			
		}
	}
}
