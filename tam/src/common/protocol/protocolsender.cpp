#include "protocolsender.h"
#include "../utils/math.h"
#include <sstream>

using namespace common::protocol;
using namespace common::sockets;
using namespace common::utils;
using namespace std;

ProtocolSender::ProtocolSender() {
	
}

ProtocolSender::~ProtocolSender() {
	
}

void ProtocolSender::sendPackage(const TcpSocket& tcpSocket, const string& str) 
		const {
	Data data(str);
	return this->sendPackage(tcpSocket, data);
}

void ProtocolSender::sendPackage(const TcpSocket& tcpSocket, const Data& data) 
		const {
	int dataLength = data.getLength();
	char digits = Math::countDigits(dataLength); 
	// Primero envio los digitos de la longitud.
	Data digitsData(&digits, 1);
	tcpSocket.sendData(digitsData);
	// Ahora la longitud en si misma convirtiendo esta a char*.
	stringstream ss;
	ss << dataLength;
	Data length(ss.str().c_str(), (int)digits); // No se envia el '\0'
	tcpSocket.sendData(length);
	// Finalmente, los datos.
	tcpSocket.sendData(data);
}

void ProtocolSender::sendToSocket(
		const TcpSocket& tcpSocket, const string& message) const { 
  
  this->sendPackage(tcpSocket, message);
}

void ProtocolSender::sendToSocket(
		const TcpSocket& tcpSocket, const Data& data) const { 

	this->sendPackage(tcpSocket, data);
}
