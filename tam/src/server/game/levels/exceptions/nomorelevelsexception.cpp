#include "nomorelevelsexception.h"

using namespace server::game::levels::exceptions;
using namespace std;

NoMoreLevelsException::NoMoreLevelsException(const string& details) 
    : details(details) {
  
}

NoMoreLevelsException::~NoMoreLevelsException() throw() {
  
}

const char* NoMoreLevelsException::what() const throw() {
  return details.c_str();
}
