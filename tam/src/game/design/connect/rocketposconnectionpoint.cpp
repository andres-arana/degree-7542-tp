#include "rocketposconnectionpoint.h"

using namespace game::design::elements;
using namespace game::design::connect;
using namespace game::core;

RocketPosConnectionPoint::RocketPosConnectionPoint(Rocket& rocket) :
	rocket(rocket) {

}

Vector2d RocketPosConnectionPoint::getPosition() const {
	return this->rocket.getPosition();
}

Element& RocketPosConnectionPoint::getParentElement() {
	return rocket;
}
