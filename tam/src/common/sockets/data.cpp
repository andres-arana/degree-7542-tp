#include "data.h"
#include "../utils/stringutils.h"

using namespace common::sockets;
using namespace common::utils;
using namespace std;

Data::Data(const char* data, int length, bool copyData) :  
		length(length) {
	if (copyData) { 
		this->data = StringUtils::stringCopy(data, length, false);
	} else {
		this->data = data;
	}
}

Data::Data(const string& str) : 
		data(StringUtils::stringCopy(str.data(), str.length(), false)),
		length(str.length()) {
			
}	 

Data::~Data() {
	delete[] this->data;
}

const char* Data::getData() const {
	return this->data;
}

int Data::getLength() const {
	return this->length;
}
