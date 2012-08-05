#include "rocketproperties.h"

using namespace game::logic::properties;

RocketProperties::RocketProperties() :
	ElementProperties(),
	strength(0),
	decayTime(0) {
		
}

RocketProperties::RocketProperties(int number, int price, 
		int strength, int decayTime) : 
	ElementProperties(number, price), 
	strength(strength),
	decayTime(decayTime) {
	
}

int RocketProperties::getStrength() const {
	return this->strength;
}

void RocketProperties::setStrength(int strength) {
	this->strength = strength;
}

int RocketProperties::getDecayTime() const {
	return this->decayTime;
}

void RocketProperties::setDecayTime(int decayTime) {
	this->decayTime = decayTime;
}
