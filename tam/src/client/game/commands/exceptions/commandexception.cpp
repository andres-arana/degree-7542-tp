#include "commandexception.h"

using namespace client::game::commands::exceptions;
using namespace std;

CommandException::CommandException() {
	
}

CommandException::CommandException(const string& details) 
    : details(details) {
  
}

CommandException::~CommandException() throw() {
  
}

const char* CommandException::what() const throw() {
  return details.c_str();
}
