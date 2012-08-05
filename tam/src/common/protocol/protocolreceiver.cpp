#include "protocolreceiver.h"
#include "../utils/stringutils.h"
#include <iostream>
using namespace common::sockets;
using namespace common::utils;
using namespace common::protocol;
using namespace std;

ProtocolReceiver::ProtocolReceiver() {
	
}

ProtocolReceiver::~ProtocolReceiver() {
	
}

const Data* ProtocolReceiver::receiveFromSocket(const TcpSocket& tcpSocket) 
		const {
	// Recibo la cantidad de Digitos que tendra la longitud de los Datos.
	const Data* digitsLengthData = tcpSocket.receiveData(1);
	// La longitud viene dada por un char que convierto a int.
	int digitLength = *(digitsLengthData->getData()); 
	// Recibo la longitud de los datos.
	const Data* dataLengthData = tcpSocket.receiveData(digitLength);
	// Como lo que recibo son numeros pero en un char*, debo hacer que la cadena
	// finalice en '\0' para poder convertirlo a un numero entero.
	string dataLengthStr;
	dataLengthStr.append(dataLengthData->getData(), dataLengthData->getLength());	
	int dataLength = StringUtils::stringToNumber<int>(dataLengthStr);
	delete digitsLengthData;
	delete dataLengthData;
	// Recibo los datos.
	return tcpSocket.receiveData(dataLength);
}

const string ProtocolReceiver::receiveStrFromSocket(const TcpSocket& tcpSocket) 
		const {

	const Data* data = this->receiveFromSocket(tcpSocket);
	string strAux(data->getData(), data->getLength());
	delete data;		
	return strAux;			
}
