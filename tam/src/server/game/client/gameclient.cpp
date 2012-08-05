#include "gameclient.h"
#include "../sessions/gamesession.h"
#include "sockets/data.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "threads/thread.h"
#include "logger/tri_logger.h"

using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::threads;
using namespace server::game;
using namespace server::game::client;
using namespace std;

GameClient::GameClient(TcpSocket* tcpSocket) :
	gameSession(NULL),
	clientSocket(tcpSocket),
	msgPool(new MessagePool()),
	totalScore(0) {
	
	this->msgReceiver = new MessageReceiver(this);	
	this->msgSender = new MessageSender(this->msgPool, this->clientSocket);	
}

GameClient::~GameClient() {
	TRI_LOG_STR("GameClient: Destructor.");
	this->disconnect();
	delete this->msgPool;
}

void GameClient::init() {
	this->msgSender->start();	
	this->msgReceiver->start();
}

void GameClient::setNick(const string& nick) {
	this->nick = nick;
}

const string& GameClient::getNick() const {
	return this->nick;
}

void GameClient::setGameSession(sessions::GameSession* gameSession) {
	this->gameSession = gameSession;
}

sessions::GameSession* GameClient::getGameSession() const {
	return this->gameSession;
}

TcpSocket* GameClient::getSocket() const {
	return this->clientSocket;
}

void GameClient::sendMessage(const string& message) {
	this->msgPool->addMessage(message);
}

void GameClient::sendMessage(Data* message) {
	this->msgPool->addMessage(message);
}

void GameClient::addScore(int score) {
	this->totalScore += score;
}

int GameClient::getTotalScore() const {
	return this->totalScore;
}

bool GameClient::isAlive() const {
	return !this->msgReceiver->isStopped();  
}

void GameClient::disconnect() {
  if (this->clientSocket) {   
    try {
      this->msgReceiver->setHasToShutdown(true);
      this->msgReceiver->stop(); 
      this->clientSocket->shutdownSocket(TcpSocket::DISABLE_ALL);
      this->clientSocket->closeSocket();
      this->msgReceiver->join();
      this->msgSender->stop();
      this->msgSender->join();
    } catch (const TcpSocketException& e) {
      TRI_LOG_STR("GameClient: El Cliente cerro el Socket.");      
    }
  	delete this->msgReceiver;
  	this->msgReceiver = NULL;
  	delete this->msgSender;
  	this->msgSender = NULL;
  	delete this->clientSocket;      
    this->clientSocket = NULL;
    TRI_LOG_STR("GameClient: El Cliente " + this->getNick() 
  			+ " ha sido desconectado."); 
  }
}
