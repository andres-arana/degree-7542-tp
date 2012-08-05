#include "designtoolbox.h"
#include "logger/tri_logger.h"

using namespace game::core;
using namespace game::design;
using namespace game::design::elements;
using namespace game::logic;
using namespace game::logic::properties;
using namespace game::serialization::model;

DesignToolbox::properties_modified_signal_type &DesignToolbox::modified() {
	return propertiesModifiedSignal;
}

void DesignToolbox::loadPropertiesFromStage(Stage& stage) {
	this->stageProperties = stage.getStageProperties();
	this->metalBarProperties = stage.getMetalBarProperties();
	this->metalPlatformProperties = stage.getMetalPlatformProperties();
	this->canvasTapeProperties = stage.getCanvasTapeProperties();
	this->ropeProperties = stage.getRopeProperties();
	this->massProperties = stage.getMassProperties();
	this->wheelProperties = stage.getWheelProperties();
	this->rocketProperties = stage.getRocketProperties();
	this->fixedPointProperties = stage.getFixedPointProperties();
	launchPropertiesModified();
}

StageProperties* DesignToolbox::getStageProperties() {
	return &(this->stageProperties);
}

MetalBar* DesignToolbox::createMetalBar(const Vector2d& startPosition) {
	if (this->metalBarProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableMetalBars();
	double minLength = this->metalBarProperties.getMinLength();
	double maxLength = this->metalBarProperties.getMaxLength();

	MetalBar *bar = new MetalBar(true, minLength, maxLength, startPosition);
	bar->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableMetalBars));
	return bar;
}

FromToElementProperties* DesignToolbox::getMetalBarProperties() {
	return &(this->metalBarProperties);
}

void DesignToolbox::incrementAvailableMetalBars() {
	this->metalBarProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableMetalBars() {
	this->metalBarProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

MetalPlatform* DesignToolbox::createMetalPlatform(const Vector2d& startPosition) {
	if (this->metalPlatformProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableMetalPlatforms();
	double minLength = this->metalPlatformProperties.getMinLength();
	double maxLength = this->metalPlatformProperties.getMaxLength();

	MetalPlatform *platform
			= new MetalPlatform(true, minLength, maxLength, startPosition);
	platform->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableMetalPlatforms));
	return platform;
}

FromToElementProperties* DesignToolbox::getMetalPlatformProperties() {
	return &(this->metalPlatformProperties);
}

void DesignToolbox::incrementAvailableMetalPlatforms() {
	this->metalPlatformProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableMetalPlatforms() {
	this->metalPlatformProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

CanvasTape* DesignToolbox::createCanvasTape(const Vector2d& startPosition) {
	if (this->canvasTapeProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableCanvasTapes();
	double minLength = this->canvasTapeProperties.getMinLength();
	double maxLength = this->canvasTapeProperties.getMaxLength();

	CanvasTape *tape = new CanvasTape(true, minLength, maxLength, startPosition);
	tape->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableCanvasTapes));
	return tape;
}

FromToElementProperties* DesignToolbox::getCanvasTapeProperties() {
	return &(this->canvasTapeProperties);
}

void DesignToolbox::incrementAvailableCanvasTapes() {
	this->canvasTapeProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableCanvasTapes() {
	this->canvasTapeProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

Rope* DesignToolbox::createRope(const Vector2d& startPosition) {
	if (this->ropeProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableRopes();
	double minLength = this->ropeProperties.getMinLength();
	double maxLength = this->ropeProperties.getMaxLength();

	Rope *rope = new Rope(true, minLength, maxLength, startPosition);
	rope->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableRopes));
	return rope;
}

FromToElementProperties* DesignToolbox::getRopeProperties() {
	return &(this->ropeProperties);
}

void DesignToolbox::incrementAvailableRopes() {
	this->ropeProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableRopes() {
	this->ropeProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

Mass* DesignToolbox::createMass() {
	if (this->massProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableMasses();
	double minRadius = this->massProperties.getMinRadius();
	double maxRadius = this->massProperties.getMaxRadius();
	double mass = this->massProperties.getMass();

	Mass *massElement = new Mass(true, minRadius, maxRadius, mass);
	massElement->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableMasses));
	return massElement;
}

MassProperties* DesignToolbox::getMassProperties() {
	return &(this->massProperties);
}

void DesignToolbox::incrementAvailableMasses() {
	this->massProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableMasses() {
	this->massProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

Wheel* DesignToolbox::createWheel() {
	if (this->wheelProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableWheels();
	double minRadius = this->wheelProperties.getMinRadius();
	double maxRadius = this->wheelProperties.getMaxRadius();
	double torqueMagnitude = this->wheelProperties.getTorqueMagnitude();
	double decayTime = this->wheelProperties.getDecayTime();

	Wheel *wheel
			= new Wheel(true, minRadius, maxRadius, torqueMagnitude, decayTime);
	wheel->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableWheels));
	return wheel;
}

WheelProperties* DesignToolbox::getWheelProperties() {
	return &(this->wheelProperties);
}

void DesignToolbox::incrementAvailableWheels() {
	this->wheelProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableWheels() {
	this->wheelProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

Rocket* DesignToolbox::createRocket(const Vector2d& startPosition) {
	if (this->rocketProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableRockets();
	double strength = this->rocketProperties.getStrength();
	double decayTime = this->rocketProperties.getDecayTime();

	Rocket *rocket = new Rocket(true, strength, decayTime, startPosition);
	rocket->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableRockets));
	return rocket;
}


RocketProperties* DesignToolbox::getRocketProperties() {
	return &(this->rocketProperties);
}

void DesignToolbox::incrementAvailableRockets() {
	this->rocketProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableRockets() {
	this->rocketProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

FixedPoint* DesignToolbox::createFixedPoint() {
	if (this->fixedPointProperties.getAvailableNumber() == 0) return NULL;
	this->decrementAvailableFixedPoints();
	double minRadius = this->fixedPointProperties.getMinRadius();
	double maxRadius = this->fixedPointProperties.getMaxRadius();
	FixedPoint *point = new FixedPoint(true, minRadius, maxRadius);
	point->erased().connect(
			sigc::mem_fun(*this, &DesignToolbox::incrementAvailableFixedPoints));
	return point;
}


CenterRadiusElementProperties* DesignToolbox::getFixedPointProperties() {
	return &(this->fixedPointProperties);
}

void DesignToolbox::incrementAvailableFixedPoints() {
	this->fixedPointProperties.incrementAvailableNumber();
	launchPropertiesModified();
}

void DesignToolbox::decrementAvailableFixedPoints() {
	this->fixedPointProperties.decrementAvailableNumber();
	launchPropertiesModified();
}

int DesignToolbox::calculateTotalSpent() {
	return this->metalBarProperties.getTotalSpent() +
				 this->metalPlatformProperties.getTotalSpent() +
				 this->canvasTapeProperties.getTotalSpent() +
				 this->ropeProperties.getTotalSpent() +
				 this->massProperties.getTotalSpent() +
				 this->wheelProperties.getTotalSpent() +
				 this->rocketProperties.getTotalSpent() +
				 this->fixedPointProperties.getTotalSpent();
}

void DesignToolbox::launchPropertiesModified() {
	propertiesModifiedSignal();
}
