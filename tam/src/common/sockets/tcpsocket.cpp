#include "tcpsocket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdlib>
#include <cstring>
#include "exceptions/tcpsocketexception.h"
#include "exceptions/tcpsocketconnectionclosedexception.h"

using namespace common::sockets; 
using namespace common::sockets::exceptions;
using namespace std;

const int TcpSocket::DEFAULT_BACKLOG = 10;

TcpSocket::TcpSocket() {
	if ((this->socketFD = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		throw TcpSocketException("TcpSocket()");
	}
}

TcpSocket::TcpSocket(int socketFD) : socketFD(socketFD) {
	
}

TcpSocket::~TcpSocket() {
  
}

void TcpSocket::initSocketAddressIn(unsigned short port, 
		SocketAddressIn* socketAddress) const {

	socketAddress->sin_family = AF_INET;
	socketAddress->sin_port = htons(port);
	std::memset(&(socketAddress->sin_zero), '\0', 8);	
}

void TcpSocket::assignSocketAddressIn(unsigned long ip, unsigned short port, 
		SocketAddressIn* socketAddress) const {
	
	this->initSocketAddressIn(port, socketAddress);
	socketAddress->sin_addr.s_addr = htonl(ip);	  	
}

void TcpSocket::assignSocketAddressIn(Address& address, unsigned short port, 
		SocketAddressIn* socketAddress) const {
	
	this->initSocketAddressIn(port, socketAddress);
	socketAddress->sin_addr = address;		
}

void TcpSocket::bindSocket(const string& ip, unsigned short port) const {
	SocketAddressIn socketAddress;
	this->assignSocketAddressIn(inet_addr(ip.c_str()), port, &socketAddress);
	if (bind(this->socketFD, (SocketAddress*) &(socketAddress), 
			sizeof(SocketAddress)) == -1) {
    throw TcpSocketException("bindSocket()");
  }
}

void TcpSocket::bindSocket(unsigned short port) const { 			
	SocketAddressIn socketAddress;
	this->assignSocketAddressIn(INADDR_ANY, port, &socketAddress);
	if (bind(this->socketFD, (SocketAddress*) &(socketAddress), 
			sizeof(SocketAddress)) == -1) {
    throw TcpSocketException("bindSocket()");
  }
}

void TcpSocket::listenSocket(int backlog) const { 
	if (listen(this->socketFD, backlog) == -1) {
    throw TcpSocketException("listenSocket()");
  }		
}

void TcpSocket::connectToHost(const string& ip, unsigned short port) const { 	
	SocketAddressIn socketAddress;
	HostInfo* hostInfo = NULL;
	if ((hostInfo = gethostbyname(ip.c_str())) == NULL) {
		throw TcpSocketException("gethostbyname()");
	}
	this->assignSocketAddressIn(*(Address*)(hostInfo->h_addr), port, &socketAddress);  
	int size = sizeof(SocketAddress);
	if (connect(this->socketFD, 
			(SocketAddress*) &(socketAddress), size) == -1) {
		throw TcpSocketException("connectToHost()");
	}		
}

TcpSocket* TcpSocket::acceptConnection() const {
  int newFD;
  SocketAddressIn remoteAddress;
  unsigned int size = sizeof(SocketAddressIn);
  if ((newFD = accept(this->socketFD, (SocketAddress*) &remoteAddress, 
       &size)) == -1) {
    throw TcpSocketException("acceptConnection:accept");
  }
  return new TcpSocket(newFD);
}

void TcpSocket::sendData(const Data& data) const {
	const char* buffer = data.getData();
	int totalBytes = data.getLength();
	int bytesSent;
	int totalBytesSent = 0;
	while (totalBytesSent < totalBytes) {
		bytesSent = send(this->socketFD, buffer + totalBytesSent, 
				totalBytes - totalBytesSent, 0);
		if (bytesSent == -1) {
			throw TcpSocketException("sendData()");
		}
		totalBytesSent += bytesSent;
	}
}

const Data* TcpSocket::receiveData(int length) const {   	
	int bytesReceived = 0;
  int totalReceived = 0;
  char* buffer = new char[length];
  while (totalReceived < length) {
  	bytesReceived = recv(this->socketFD, &buffer[totalReceived], 
  			length - totalReceived, 0);
  	if (bytesReceived <= 0) {
  		delete[] buffer;
	  	if (bytesReceived == 0) {	  		
				throw TcpSocketConnectionClosedException("receiveData()");
			}
	  	if (bytesReceived == -1) {    
	    	throw TcpSocketException("receiveData()");
	  	}
  	}
  	totalReceived += bytesReceived;  	
  }
  return new Data(buffer, totalReceived, false); 
}

void TcpSocket::shutdownSocket(ShutdownType type) const {
  if (shutdown(this->socketFD, type) == -1) {
    throw TcpSocketException("shutdownSocket()");
  }
}

void TcpSocket::closeSocket() const {
	if (close(this->socketFD) == -1) {
		throw TcpSocketException("closeSocket()");
	}
}
