#include "elementfactoryimpl.h"

using game::serialization::model::ElementFactoryImpl;
using game::design::elements::Ball;
using game::design::elements::ExitArea;
using game::design::elements::FixedPoint;
using game::design::elements::Obstacle;


ElementFactoryImpl::ElementFactoryImpl(bool editableMode): ballCreated(false), editableMode(editableMode) {}


ElementFactoryImpl::~ElementFactoryImpl() {
}


Ball* ElementFactoryImpl::createBall() {
	if (!ballCreated) {
		ballCreated = true;
		Ball* ball = new Ball(editableMode);
		ball->erased().connect(sigc::mem_fun(*this, &ElementFactoryImpl::restoreBall));
		return ball;
	}
	return NULL;
}


void ElementFactoryImpl::restoreBall() {
	ballCreated = false;
}


void ElementFactoryImpl::restore() {
	restoreBall();
}


void ElementFactoryImpl::setEditableMode(bool editableMode) {
	this->editableMode = editableMode;
}


ExitArea* ElementFactoryImpl::createExitArea() {
	return new ExitArea(editableMode);
}


FixedPoint* ElementFactoryImpl::createFixedPoint() {
	return new FixedPoint(editableMode);
}


Obstacle* ElementFactoryImpl::createObstacle(const core::Vector2d &startPosition) {
	return new Obstacle(editableMode, startPosition);
}

