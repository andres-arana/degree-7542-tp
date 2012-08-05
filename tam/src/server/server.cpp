#include "server.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "logger/tri_logger.h"

using namespace server;
using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::threads;
using namespace std;

Server::Server() : 
	hasToShutdown(false), 
	acceptorSocket(NULL) {
	
}

Server::~Server() {

}

void Server::initSocket(const string& ip, unsigned short port) { 
	this->acceptorSocket = new TcpSocket();
	if (ip.length()) {
		this->acceptorSocket->bindSocket(ip, port);
	} else {
		this->acceptorSocket->bindSocket(port);
	}
	this->acceptorSocket->listenSocket();
	TRI_LOG_STR("Server Init --> OK.");
}

void Server::startServer(const string& ip, unsigned short port) {	
	this->initSocket(ip, port);
	this->start();
}
			
void Server::startServer(unsigned short port) {
	this->initSocket("", port);
	this->start();
}

void Server::shutdownServer() {
	if (this->acceptorSocket) {
		this->hasToShutdown = true; 
	  this->acceptorSocket->shutdownSocket(TcpSocket::DISABLE_ALL);
	  this->acceptorSocket->closeSocket();
	  this->join();
	  delete this->acceptorSocket;
	  this->acceptorSocket = NULL;
	  TRI_LOG_STR("Server Shutdown --> OK.");
	}
}
