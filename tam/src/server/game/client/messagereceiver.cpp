#include "messagereceiver.h"
#include "gameclient.h"
#include "sockets/tcpsocket.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "protocol/protocolreceiver.h"
#include "../sessions/gamesession.h"
#include "../commands/commandfactory.h"
#include "../commands/command.h"
#include "../commands/exceptions/commandexception.h"
#include "../messages/servermessages.h"
#include "logger/tri_logger.h"

#define WHITESPACE ' '

using namespace common::protocol;
using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace server::game::client;
using namespace server::game::sessions;
using namespace server::game::commands;
using namespace server::game::commands::exceptions;
using namespace server::game::messages;
using namespace std;

MessageReceiver::MessageReceiver(client::GameClient* gameClient) : 
	gameClient(gameClient),
	hasToShutdown(false) {
	
}

MessageReceiver::~MessageReceiver() {

}

void MessageReceiver::setHasToShutdown(bool shutdown) {
	this->hasToShutdown = shutdown;
}

void MessageReceiver::processMessage(const string& message) {
	string cmdName = message;
	string param = "";
	// Busco Params.
	size_t space = cmdName.find(WHITESPACE);
	if (space != string::npos) {
		param = cmdName.substr(space + 1);
		cmdName.erase(space);
	}
	try {
		Command* command = CommandFactory::getInstance().getCommandByName(cmdName);
		command->execute(this->gameClient, param);
		delete command;
	} catch (const CommandException& e) {
		TRI_LOG_STR("El comando " + cmdName 
				+ " no existe o se produjo un error al ejecutarlo.");
	}
}

void MessageReceiver::run() {
	ProtocolReceiver protocolRec;
	TcpSocket* tcpSocket = this->gameClient->getSocket();
	while (!this->isStopped()) {
		try {
			string message = protocolRec.receiveStrFromSocket(*tcpSocket);
			TRI_LOG_STR("MessageReceiver: Mensaje Recibido --> " + message);
			this->processMessage(message);
		} catch (const TcpSocketException& e) {
			this->stop();
			TRI_LOG_STR("MessageReceiver Detenido --> " 
				+ this->gameClient->getNick() + " se ha desconectado.");
			if (!this->hasToShutdown) { 
				GameSession* gameSession = gameClient->getGameSession();
				// Siempre deberia estar en una sesion si se esta mandando un mensaje.	
				if (gameSession) { 
					gameSession->broadcastMessage(MSG_RESPONSE_CMD 
						+ this->gameClient->getNick()	+ ServerMessages::ON_LOGOUT_SUFFIX);
				}
			}
		}
	}
}
