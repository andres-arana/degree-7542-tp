#include "gameclient.h"
#include "exceptions/connectionexception.h"
#include "utils/stringutils.h"
#include "logger/tri_logger.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "threads/locks/lock.h"
#include "utils/collections.h"

#define JOIN_CMD "/join "
#define MSG_CMD "/msg "
#define REC_SEPARATOR '\30'

using namespace client::game::model;
using namespace client::game::model::exceptions;
using namespace common::protocol;
using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::threads::locks;
using namespace common::utils;
using namespace std;

unsigned short GameClient::DEFAULT_PORT = 8888;

GameClient::GameClient() :
	tcpSocket(NULL),
	serverListener(NULL),
	requestSender(NULL),
	responseReceived(false),
	loginSuccess(false),
	joinSuccess(false),
	sessionList(NULL),
	opponentConnected(false),
	moreLevels(false),
	levelHasToStart(false),
	totalScore(0) {
}

GameClient::~GameClient() {
	this->clearSessionList();
	this->disconnect();
}

void GameClient::init() {
	this->serverListener = new ServerListener(this);
	this->serverListener->start();
	this->requestSender = new RequestSender(this->tcpSocket);
	this->requestSender->start();
}

void GameClient::setResponseReceived(bool received) {
	this->responseReceived = received;
}

bool GameClient::wasResponseReceived() const {
	return this->responseReceived;
}

void GameClient::clearSessionList() {
	if (this->sessionList) {
		common::utils::DeleteAndClearElements(*(this->sessionList));
		delete this->sessionList;
		this->sessionList = NULL;
	}
}

void GameClient::setAvailableSessions(list<Session*>* sessionList) {
	Lock lock(this->mutex);
	this->clearSessionList();
	this->sessionList = sessionList;
}

list<Session*>* GameClient::getAvailableSessions() const {
	Lock lock(this->mutex);
	return this->sessionList;
}

void GameClient::setLoginSuccess(bool success) {
	this->loginSuccess = success;
}

bool GameClient::isLogged() const {
	return this->loginSuccess;
}

void GameClient::setJoinSuccess(bool success) {
	this->joinSuccess = success;
}

bool GameClient::isJoined() const {
	return this->joinSuccess;
}

void GameClient::setOpponentConnected(bool connected) {
	this->opponentConnected = connected;
}

bool GameClient::isOpponentConnected() const {
	return this->opponentConnected;
}

void GameClient::setMoreLevels(bool moreLevels) {
	this->moreLevels = moreLevels;
}

bool GameClient::hasMoreLevels() const {
	return this->moreLevels;
}

void GameClient::addScore(int score) {
	this->totalScore += score;
}

int GameClient::getTotalScore() const {
	return this->totalScore;
}

void GameClient::setLevelStart(bool start) {
	this->levelHasToStart = start;
}

bool GameClient::hasLevelToStart() const {
	return this->levelHasToStart;
}

void GameClient::setFeedbackStr(const string& feedbackStr) {
	this->feedbackStr = feedbackStr;
}

const string& GameClient::getFeedbackStr() const {
	return this->feedbackStr;
}

void GameClient::connectToGameServer(const string& ip, unsigned short port) {
	try {
		this->tcpSocket = new TcpSocket();
		this->tcpSocket->connectToHost(ip, port);
		this->init();
	} catch(const TcpSocketException& e) {
		if (this->tcpSocket) delete this->tcpSocket;
		this->tcpSocket = NULL;
		throw ConnectionException();
	}
}

TcpSocket* GameClient::getSocket() const {
	return this->tcpSocket;
}

void GameClient::resetStatus() {
	this->responseReceived = false;
	this->loginSuccess = false;
	this->joinSuccess = false;
	this->opponentConnected = false;
	this->moreLevels = false;
	this->levelHasToStart = false;
	this->feedbackStr.clear();
	this->clearSessionList();
}

bool GameClient::isConnected() const {
	return (this->tcpSocket && !this->serverListener->isStopped());
}

void GameClient::disconnect() {
	if (this->tcpSocket) {
		try {
			this->tcpSocket->shutdownSocket(TcpSocket::DISABLE_ALL);
			this->tcpSocket->closeSocket();
		} catch (const TcpSocketException& e) {
			TRI_LOG_STR("GameClient: El Servidor cerro el Socket.");
		}
		delete this->tcpSocket;
  	this->tcpSocket = NULL;
  }
  if (this->requestSender) {
		this->requestSender->stop();
		this->requestSender->join();
		delete this->requestSender;
		this->requestSender = NULL;
	}
  if (this->serverListener) {
		this->serverListener->stop();
		this->serverListener->join();
		delete this->serverListener;
		this->serverListener = NULL;
		TRI_LOG_STR("GameClient: Cliente Desconectado.");
	}
}
