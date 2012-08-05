#include "connectionpoint.h"
#include "../elements/connection.h"

using namespace game::core;
using namespace game::design::connect;
using namespace game::design::elements;

namespace {
	const double stdRadius = 10;
}

ConnectionPoint::ConnectionPoint() {

}

double ConnectionPoint::getRadius() const {
	return stdRadius;
}

bool ConnectionPoint::containsPoint(const Vector2d &point) const {
	return point.distanceTo(getPosition()) <= getRadius();
}

void ConnectionPoint::addConnection(Connection *connection) {
	connections.push_back(connection);
}

bool ConnectionPoint::isConnected() const {
	typedef std::vector<Connection *>::const_iterator iterator;
	for (iterator it = connections.begin(); it != connections.end(); ++it) {
		if (!(*it)->isErased()) {
			return true;
		}
	}
	return false;
}

ConnectionPoint::particle_list ConnectionPoint::getConnectionParticles() {
	particle_list result;

	typedef std::vector<Connection *>::const_iterator iterator;
	for (iterator it = connections.begin(); it != connections.end(); ++it) {
		if (!(*it)->isErased()) {
			result.push_back((*it)->getConnectionParticle());
		}
	}
	return result;
}

ConnectionPointContainsPointPredicate::ConnectionPointContainsPointPredicate(const Vector2d &point) :
	point(point) {

}

bool ConnectionPointContainsPointPredicate::operator()(const ConnectionPoint *connectionPoint) const {
	return connectionPoint->containsPoint(point);
}
