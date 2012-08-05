#include "tcpsocketconnectionclosedexception.h"

using namespace common::sockets::exceptions;
using namespace std;

TcpSocketConnectionClosedException::TcpSocketConnectionClosedException(
		const string& details) : TcpSocketException(details) {
		
}

TcpSocketConnectionClosedException::~TcpSocketConnectionClosedException() 
		throw() {
	
}
