#include "fromtoelementproperties.h"

using namespace game::logic::properties;

FromToElementProperties::FromToElementProperties() :
	ElementProperties(),
	minLength(0),
	maxLength(0) {

}

FromToElementProperties::FromToElementProperties(
		int number, int price, int minLength, int maxLength) : 
	ElementProperties(number, price),
	minLength(minLength),
	maxLength(maxLength) {
	
}

int FromToElementProperties::getMinLength() const {
	return this->minLength;
}

void FromToElementProperties::setMinLength(int minLength) {
	this->minLength = minLength;
}

int FromToElementProperties::getMaxLength() const {
	return this->maxLength;
}

void FromToElementProperties::setMaxLength(int maxLength) {
	this->maxLength = maxLength;
}
