#include "centerradiuselementproperties.h"

using namespace game::logic::properties;

CenterRadiusElementProperties::CenterRadiusElementProperties() : 
	ElementProperties(),
	minRadius(0),
	maxRadius(0) {

}

CenterRadiusElementProperties::CenterRadiusElementProperties(
		int number, int price, int minRadius, int maxRadius) : 
	ElementProperties(number, price),
	minRadius(minRadius),
	maxRadius(maxRadius) {
	
}

int CenterRadiusElementProperties::getMinRadius() const {
	return this->minRadius;
}

void CenterRadiusElementProperties::setMinRadius(int minRadius) {
	this->minRadius = minRadius;
} 

int CenterRadiusElementProperties::getMaxRadius() const {
	return this->maxRadius;
}

void CenterRadiusElementProperties::setMaxRadius(int maxRadius) {
	this->maxRadius = maxRadius;
}
