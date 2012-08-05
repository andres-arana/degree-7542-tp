#include "stringutils.h"
#include <cstring>

using namespace common::utils;
using namespace std;

StringUtils::StringUtils() {
  
}

StringUtils::~StringUtils() {
  
}

char* StringUtils::stringCopy(const char* str, int length, bool appendEOS) {
  char* strAux = new char[length + appendEOS];
  strncpy(strAux, str, length);
  if (appendEOS) {
  	strAux[length] = EOS;
  }
  return strAux;
}

bool StringUtils::isEmptyOrWhitespace(const string& str) { 
	if (str.find_first_not_of(WHITESPACE, 0) == string::npos) {
		return true;  
	}
	return false;
}
