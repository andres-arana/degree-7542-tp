#include "spring.h"

using namespace game::core;
using namespace game::core::affectors;

Spring::Spring(Particle &first, Particle &second, double k)
	: first(first), firstAffector(second, k, (second.getPosition() - first.getPosition()).norm()),
	second(second), secondAffector(first, k, (second.getPosition() - first.getPosition()).norm()),
	k(k), relaxedDistance(relaxedDistance)  {

	first.registerAffector(&firstAffector);
	second.registerAffector(&secondAffector);
}

const Particle& Spring::getFirst() const {
	return first;
}

const Particle& Spring::getSecond() const {
	return second;
}
