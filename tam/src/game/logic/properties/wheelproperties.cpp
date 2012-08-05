#include "wheelproperties.h"

using namespace game::logic::properties;

WheelProperties::WheelProperties() :
	CenterRadiusElementProperties(),
	torqueMagnitude(0),
	decayTime(0) {
		
}

WheelProperties::WheelProperties(int number, int price, int minRadius, 
		int maxRadius, int torqueMagnitude, int decayTime) : 
	CenterRadiusElementProperties(number, price, minRadius, maxRadius), 
	torqueMagnitude(torqueMagnitude),
	decayTime(decayTime) {
	
}

int WheelProperties::getTorqueMagnitude() const {
	return this->torqueMagnitude;
}

void WheelProperties::setTorqueMagnitude(int torqueMagnitude) {
	this->torqueMagnitude = torqueMagnitude;
}

int WheelProperties::getDecayTime() const {
	return this->decayTime;
}

void WheelProperties::setDecayTime(int decayTime) {
	this->decayTime = decayTime;
}
