#include "gamesession.h"
#include "threads/locks/lock.h"
#include "../client/gameclient.h"
#include "logger/tri_logger.h"
#include <algorithm>

#define MAX_PLAYERS 2
#define MSG_CMD "/msg "

using namespace server::game;
using namespace server::game::sessions;
using namespace server::game::levels;
using namespace common::sockets;
using namespace common::threads::locks;
using namespace std;

GameSession::GameSession(int sessionId, bool isMultiplayer) : 
	id(sessionId), 
	multiplayer(isMultiplayer),
	full(false) {
	
}

GameSession::~GameSession() {
	vector<client::GameClient*>::iterator i;
	for (i = this->gameClients.begin(); i != this->gameClients.end(); ++i) {		
		delete (*i);			
	}
}

int GameSession::getSessionId() const {
	return this->id;
}

LevelManager& GameSession::getLevelManager() {
	return this->levelManager;
}

void GameSession::addClient(client::GameClient* gameClient) {
	Lock lock(this->mutex);
	this->gameClients.push_back(gameClient);
	if (this->gameClients.size() == MAX_PLAYERS) {
		full = true;
	}
}

bool GameSession::isEmpty() const {
	return this->gameClients.empty();
}

bool GameSession::isMultiplayer() const {
	return this->multiplayer;
}

bool GameSession::isFull() const {
	return this->full;
}

const vector<client::GameClient*>& GameSession::getGameClients() const {
	return this->gameClients;
}

bool GameSession::removeDisconnectedClients() {
	vector<client::GameClient*> toBeRemoved;
	vector<client::GameClient*>::const_iterator i;
	for (i = this->gameClients.begin(); i != this->gameClients.end(); ++i) {
		if (!(*i)->isAlive()) {
			toBeRemoved.push_back(*i);
		}
	}
	GameSession::disconnectAndRemoveClients(toBeRemoved);
	return this->isEmpty();
}

void GameSession::disconnectAndRemoveClients(
		const vector<client::GameClient*>& toBeRemoved) {
	
	vector<client::GameClient*>::const_iterator i;
	for (i = toBeRemoved.begin(); i != toBeRemoved.end(); ++i) {
		(*i)->disconnect();
		this->gameClients.erase(std::find(
				this->gameClients.begin(), this->gameClients.end(), *i));
		delete *i;
	}	
}

void GameSession::broadcastWithCondition(const string& message, 
		client::GameClient* gameClientToExclude) const {
	
	vector<client::GameClient*>::const_iterator i;
	for (i = this->gameClients.begin(); i != this->gameClients.end(); ++i) {
		if ((*i) != gameClientToExclude && (*i)->isAlive()) {
			(*i)->sendMessage(message);
		}
	}
}

void GameSession::broadcastMessage(const string& message) const {	
	Lock lock(this->mutex);
	this->broadcastWithCondition(message, NULL);
}

void GameSession::broadcastMessage(const string& message, 
		client::GameClient* gameClientToExclude) const {	
	
	Lock lock(this->mutex);
	this->broadcastWithCondition(message, gameClientToExclude);
}

bool GameSession::hasLevelToStart() {
	Lock lock(this->mutex);
	unsigned int timesSent = this->levelManager.getLevelTimesSent();
	if (this->isMultiplayer()) {
		this->removeDisconnectedClients();
		if (timesSent >= this->gameClients.size()) {
			// La sesion es multijugador y se le envio el nivel a todos.
			return true;
		}
	} else {		
		if (timesSent == 1) {
			// La sesion es single y se le envio el nivel al jugador.
			return true;
		}
	}
	return false;	
}

bool GameSession::isNickInUse(const string& nick) const {	
	Lock lock(this->mutex);
	vector<client::GameClient*>::const_iterator i;
	for (i = this->gameClients.begin(); i != this->gameClients.end(); ++i) {
		if ((*i)->isAlive() && (*i)->getNick() == nick) {
			return true;
		}
	}
	return false;
}
