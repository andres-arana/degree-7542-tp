#include "massproperties.h"

using namespace game::logic::properties;

MassProperties::MassProperties() : 
	CenterRadiusElementProperties(),
	mass(0) {

}

MassProperties::MassProperties(int number, int price, int minRadius, 
		int maxRadius, int mass) : 
	CenterRadiusElementProperties(number, price, minRadius, maxRadius), 
	mass(mass) {
	
}

int MassProperties::getMass() const {
	return this->mass;
}

void MassProperties::setMass(int mass) {
	this->mass = mass;
}
