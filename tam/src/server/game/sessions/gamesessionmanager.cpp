#include "gamesessionmanager.h"
#include "threads/locks/lock.h"
#include "logger/tri_logger.h"

using namespace server::game;
using namespace server::game::sessions;
using namespace common::threads::locks;
using namespace std;

int GameSessionManager::SESSION_COUNTER = 0;

GameSessionManager::GameSessionManager() {
}

GameSessionManager::~GameSessionManager() {	
	list<client::GameClient*>::const_iterator i;
	for (i = this->awaitingClients.begin(); i != this->awaitingClients.end(); 
			++i) {
		delete (*i);			
	}
}				

GameSessionManager& GameSessionManager::getInstance() {
  static GameSessionManager instance;
  return instance;
}

sessions::GameSession* GameSessionManager::createGameSession(
		bool isMultiplayer) {
			
	sessions::GameSession* gameSession 
			= new GameSession(SESSION_COUNTER++, isMultiplayer);
	this->gameSessions.push_back(gameSession);
	return gameSession;			
}

sessions::GameSession* GameSessionManager::createSinglePlayerGameSession() {
	Lock lock(this->mutex);
	TRI_LOG_STR("GameSessionManager: Sesion Single Player Creada.");
	return this->createGameSession(false);
}

sessions::GameSession* GameSessionManager::createMultiPlayerGameSession() {
	Lock lock(this->mutex);
	TRI_LOG_STR("GameSessionManager: Sesion Multi Player Creada.");
	return this->createGameSession(true);
}

sessions::GameSession* GameSessionManager::getGameSessionById(
		int gameSessionId) {
	
	Lock lock(this->mutex);
	list<sessions::GameSession*>::const_iterator i;
	for (i = this->gameSessions.begin(); i != this->gameSessions.end(); ++i) {
		if ((*i)->getSessionId() == gameSessionId) {
			return (*i);
		}
	}
	return NULL;
}

void GameSessionManager::removeIdleAwaitingClients() {
	vector<client::GameClient*> toBeRemoved;
	list<client::GameClient*>::const_iterator i;
	for (i = this->awaitingClients.begin(); i != this->awaitingClients.end(); ++i) {
		if (!(*i)->isAlive()) {
			toBeRemoved.push_back(*i);
		}
	}
	vector<client::GameClient*>::const_iterator it;
	for (it = toBeRemoved.begin(); it != toBeRemoved.end(); ++it) {
		delete (*it);
		this->awaitingClients.remove(*it);
	}
	
}

void GameSessionManager::removeIdleSessions() {
	vector<sessions::GameSession*> toBeRemoved;
	list<sessions::GameSession*>::const_iterator i;
	for (i = this->gameSessions.begin(); i != this->gameSessions.end(); ++i) {
		if ((*i)->removeDisconnectedClients()) {
			toBeRemoved.push_back(*i);
		}
	}
	vector<sessions::GameSession*>::const_iterator it;
	for (it = toBeRemoved.begin(); it != toBeRemoved.end(); ++it) {
		delete (*it);
		this->gameSessions.remove(*it);
	}
}

void GameSessionManager::clearIdleSessionsAndClients() {
	this->removeIdleAwaitingClients();
	this->removeIdleSessions();
}

const list<sessions::GameSession*>& GameSessionManager::getGameSessions() {
	Lock lock(this->mutex);
	this->clearIdleSessionsAndClients();
	return this->gameSessions;
}

void GameSessionManager::addAwaitingClient(client::GameClient* gameClient) {
	Lock lock(this->mutex);
	this->clearIdleSessionsAndClients();
	this->awaitingClients.push_back(gameClient);
}

void GameSessionManager::addClientToGameSession(
		client::GameClient* gameClient, sessions::GameSession* gameSession) {
	
	Lock lock(this->mutex);
	gameSession->addClient(gameClient);
	gameClient->setGameSession(gameSession);
	this->awaitingClients.remove(gameClient);
}

bool GameSessionManager::isNickInUse(const string& nick) const {
	Lock lock(this->mutex);
	list<client::GameClient*>::const_iterator it;
	list<sessions::GameSession*>::const_iterator i;
	for (it = this->awaitingClients.begin(); it != this->awaitingClients.end(); ++it) {		
		if ((*it)->isAlive() && (*it)->getNick() == nick) {
			return true;
		}
	}
	for (i = this->gameSessions.begin(); i != this->gameSessions.end(); ++i) {
		if ((*i)->isNickInUse(nick)) {
			return true;
		}
	}
	return false;
}

void GameSessionManager::disconnectAllGameSessions() {
	Lock lock(this->mutex);
	list<sessions::GameSession*>::const_iterator i;
	for (i = this->gameSessions.begin(); i != this->gameSessions.end(); ++i) {
		delete (*i);
	}
	TRI_LOG_STR("GameSessionManager: Todas las sesiones de Juego Desconectadas.");
}
