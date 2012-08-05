#include "tcpsocketexception.h"

using namespace common::sockets::exceptions;
using namespace std;

TcpSocketException::TcpSocketException(const string& details) 
		: details(ERR_PREFIX + details) {
  
}

TcpSocketException::~TcpSocketException() throw() {
  
}

const char* TcpSocketException::what() const throw() {
	return details.c_str();
}
