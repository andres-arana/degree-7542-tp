#include "gameserver.h"
#include "sockets/tcpsocket.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "sessions/gamesessionmanager.h"
#include "logger/tri_logger.h"

using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::threads;
using namespace server;
using namespace server::game;
using namespace server::game::sessions;
using namespace std;

unsigned short GameServer::DEFAULT_PORT = 8888;

void GameServer::startServer(const string& ip, unsigned short port) {	
	Server::startServer(ip, port);
}
			
void GameServer::startServer(unsigned short port) {
	Server::startServer(port);
}

void GameServer::shutdownServer() {
	if (this->acceptorSocket) {
		Server::shutdownServer();
	  GameSessionManager::getInstance().disconnectAllGameSessions();
	  TRI_LOG_STR("GameServer Shutdown --> OK.");
	}
}

void GameServer::run() {
	while (!this->hasToShutdown) {
		try {
			TcpSocket* clientSocket = this->acceptorSocket->acceptConnection();
			client::GameClient* newGameClient	= new client::GameClient(clientSocket);
			GameSessionManager::getInstance().addAwaitingClient(newGameClient);
			newGameClient->init();
			TRI_LOG_STR("GameServer: Cliente Conectado.");
		} catch (const TcpSocketException& e) {
			if (!this->hasToShutdown) {
				throw e;
			}
		}
  }
}
