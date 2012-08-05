#include "gameengine.h"
#include "utils/collections.h"
#include "../core/affectors/dampingforceaffector.h"
#include "../core/affectors/gravityforceaffector.h"
#include <algorithm>

using namespace game::core;
using namespace game::core::affectors;
using namespace game::design;
using namespace game::design::elements;
using namespace game::design::move;
using namespace game::design::connect;
using namespace game::logic;
using namespace std;

namespace {
	class ContainsBallPredicate {
	public:
		ContainsBallPredicate(const Ball &ball)
			: ball(ball) {

		}

		bool operator()(ExitArea *exitArea) {
			return exitArea->containsBall(ball);
		}
	private:
		const Ball &ball;
	};
}

GameEngine::GameEngine() :
	physicsEngine(NULL),
	levelCompleted(false), levelFailed(false),
	designTime(0), simulationTime(0) {

}

void GameEngine::doTimeStep() {
	physicsEngine->doTimeStep();
	launchRuntimeModifiedSignal();
	if (getBall()) {
		const ElementContainer::ExitAreaCollection &exitAreas = getExitAreaCollection();
		if (exitAreas.end() != find_if(exitAreas.begin(), exitAreas.end(), ContainsBallPredicate(*getBall()))) {
			double delta = this->timeDelta.getDeltaFromTimeMilestone();
			designTime += delta;
			simulationTime = delta;
			timeDelta.updateTimeMilestone();
			launchEndOfLevelSignal(true);
			return;
		}
	}
	if (isTimeOver()) launchEndOfLevelSignal(false);
}

void GameEngine::swapToDesignMode() {
	scrapPhysicsEngine();
	launchStateModifiedSignal();
	designTime += timeDelta.getDeltaFromTimeMilestone();
	timeDelta.updateTimeMilestone();
}

void GameEngine::swapToRuntimeMode() {
	buildPhysicsEngine();
	launchStateModifiedSignal();
	designTime += timeDelta.getDeltaFromTimeMilestone();
	simulationTime = 0;
	timeDelta.updateTimeMilestone();
}

GameEngine::Modes GameEngine::getCurrentMode() const {
	if (physicsEngine) {
		return GameEngine::runtimeMode;
	} else {
		return GameEngine::designMode;
	}
}

bool GameEngine::isLevelFailed() const {
	return levelFailed;
}

bool GameEngine::isLevelCompleted() const {
	return levelCompleted;
}

int GameEngine::getRemainingTime() {
	int time = static_cast<int>(toolbox.getStageProperties()->getTimeToSolve() -
			(designTime + timeDelta.getDeltaFromTimeMilestone()));
	return time < 0 ? 0 : time;
}

double GameEngine::getElapsedTimePercentage() {
	if (isTimeOver()) this->launchEndOfLevelSignal(false);
	double percentage
			= (this->designTime + this->timeDelta.getDeltaFromTimeMilestone()) /
					this->toolbox.getStageProperties()->getTimeToSolve();
	return percentage > 1 ? 1 : percentage;
}

int GameEngine::calculateScore() {
	int A = toolbox.getStageProperties()->getA();
	int B = toolbox.getStageProperties()->getB();
	int C = toolbox.getStageProperties()->getC();
	int D = toolbox.getStageProperties()->getD();
	int spent = toolbox.calculateTotalSpent();
	int firstAddend = static_cast<int>(A / (designTime + B));
	int secondAddend = static_cast<int>(C / (simulationTime + D));
	int result = firstAddend + secondAddend - spent;
	return result < 0 ? 0 : result;
}

DesignToolbox& GameEngine::getDesignToolbox() {
	return this->toolbox;
}

GameEngine::runtime_modified_signal_type &GameEngine::runtimeModified() {
	return runtimeModifiedSignal;
}

GameEngine::state_modified_signal_type &GameEngine::stateModified() {
	return stateModifiedSignal;
}

GameEngine::end_of_level_signal_type &GameEngine::endOfLevel() {
	return endOfLevelSignal;
}

void GameEngine::clearEngine() {
	levelCompleted = false;
	levelFailed = false;
	designTime = 0;
	simulationTime = 0;
	timeDelta.updateTimeMilestone();
	scrapPhysicsEngine();
	clearElements();
}

GameEngine::~GameEngine() {
	if (physicsEngine) {
		scrapPhysicsEngine();
	}
}

bool GameEngine::isTimeOver() {
	return designTime + timeDelta.getDeltaFromTimeMilestone() > toolbox.getStageProperties()->getTimeToSolve();
}

void GameEngine::launchEndOfLevelSignal(bool completed) {
	// La siguiente linea evita que la senial se envie mas de una vez.
	// Esto podria darse si se esta haciendo el doTimeStep y por otro lado se
	// controla el porcentaje del tiempo total.
	if (this->levelCompleted || this->levelFailed) return;
	this->levelCompleted = completed;
	this->levelFailed = !completed;
	endOfLevelSignal();
}

void GameEngine::launchRuntimeModifiedSignal() {
	runtimeModifiedSignal();
}

void GameEngine::launchStateModifiedSignal() {
	stateModifiedSignal();
}

void GameEngine::buildPhysicsEngine() {
	physicsEngine = new PhysicsEngine();

	ElementContainer::ElementCollection &elements = getElementCollection();
	for (ElementContainer::ElementIterator it = elements.begin(); it != elements.end(); ++it) {
		(*it)->build(*physicsEngine);
	}

	physicsEngine->addSystemWideAffector(new DampingForceAffector(0.05));
	physicsEngine->addSystemWideAffector(new GravityForceAffector(Vector2d(0, toolbox.getStageProperties()->getGravity())));
}

void GameEngine::scrapPhysicsEngine() {
	ElementContainer::ElementCollection &elements = getElementCollection();
	for (ElementIterator it = elements.begin(); it != elements.end(); ++it) {
		(*it)->scrap();
	}

	delete physicsEngine;
	physicsEngine = NULL;
}
