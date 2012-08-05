#include "elementproperties.h"

using namespace game::logic::properties;

ElementProperties::ElementProperties() :
	number(0),
	price(0),
	available(0) {

}

ElementProperties::ElementProperties(int number, int price) :
	number(number),
	price(price),
	available(number) {

}

int ElementProperties::getNumber() const {
	return this->number;
}

void ElementProperties::setNumber(int number) {
	this->number = number;
	this->available = number;
}

int ElementProperties::getPrice() const {
	return this->price;
}

void ElementProperties::setPrice(int price) {
	this->price = price;
}

int ElementProperties::getAvailableNumber() const {
	return this->available;
}

void ElementProperties::incrementAvailableNumber() {
	if (this->available < this->number) this->available++;
}

void ElementProperties::decrementAvailableNumber() {
	if (this->available > 0) this->available--;
}

int ElementProperties::getTotalSpent() {
	return (this->number - this->available) * this->price;
}
