#include "connection.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::connect;

namespace {
	const double stdMinimumDistance = 5;
	const double stdMaximumDistance = 50;
	const double stdThckness = 4;

	const double stdMassValue = 0.5;
	const double stdMassRadius = 5;
}

Connection::Connection(ConnectionPoint &first, ConnectionPoint &second) :
	Element(true),
	first(first),
	second(second) {

	validateConnection();
	first.getParentElement().modified().connect(sigc::mem_fun(*this, &Connection::validateConnection));
	first.getParentElement().erased().connect(sigc::mem_fun(*this, &Connection::validateConnection));
	second.getParentElement().modified().connect(sigc::mem_fun(*this, &Connection::validateConnection));
	second.getParentElement().erased().connect(sigc::mem_fun(*this, &Connection::validateConnection));
	first.addConnection(this);
	second.addConnection(this);
}

Vector2d Connection::getStartPosition() const {
	return first.getPosition();
}

Vector2d Connection::getEndPosition() const {
	return second.getPosition();
}

double Connection::getConnectionWidth() const {
	return stdThckness;
}

Particle *Connection::getConnectionParticle() {
	if (particles.size() == 0) {
		Vector2d axis = getEndPosition() - getStartPosition();
		double distance = axis.norm();
		axis.normalize();

		Vector2d massPosition = getStartPosition() + (axis * (distance / 2.0));
		Particle* particle = new Particle(stdMassValue, stdMassRadius, massPosition);
		particle->setCollisionable(false);
		particles.push_back(particle);
	}
	return particles[0];
}

bool Connection::containsPoint(const core::Vector2d &point) const {
	if (this->isErased()) return false;

	Vector2d axis = getEndPosition() - getStartPosition();
	Vector2d translation = -getStartPosition();
	double angle = -(Vector2d(1, 0).angleTo(axis));

	Vector2d translatedPoint = translation + point;
	double transformedX = cos(angle) * translatedPoint.getX() - sin(angle) * translatedPoint.getY();
	double transformedY = sin(angle) * translatedPoint.getX() + cos(angle) * translatedPoint.getY();

	return transformedX >= 0 && transformedX <= axis.norm() && fabs(transformedY) <= (getConnectionWidth() / 2);
}

void Connection::buildParticlesAndSprings() {

}

void Connection::validateConnection() {
	if (first.getParentElement().isErased() || second.getParentElement().isErased()) {
		erase();
	}

	double distance = first.getPosition().distanceTo(second.getPosition());
	if (distance > stdMaximumDistance || distance < stdMinimumDistance) {
		erase();
	}


}
