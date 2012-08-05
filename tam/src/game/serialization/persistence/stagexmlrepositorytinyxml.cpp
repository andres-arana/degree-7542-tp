#include "stagexmlrepositorytinyxml.h"
#include "../../core/vector2d.h"
#include "../model/elementfactoryimpl.h"
#include "stdio.h"

using namespace game::serialization::model;
using game::serialization::persistence::StageXmlRepositoryTinyXml;
using game::logic::properties::FromToElementProperties;
using game::logic::properties::MassProperties;
using game::logic::properties::WheelProperties;
using game::logic::properties::RocketProperties;
using game::logic::properties::CenterRadiusElementProperties;
using game::design::ElementContainer;
using game::design::elements::Element;
using game::design::elements::CenterRadiusElement;
using game::design::elements::Ball;
using game::design::elements::ExitArea;
using game::design::elements::FixedPoint;
using game::design::elements::Obstacle;
using game::design::elements::CanvasTape;
using namespace game::design::elements;
using game::core::Vector2d;

std::string StageXmlRepositoryTinyXml::serialize(const ElementContainer& elementContainer) {
	std::string str;
	TiXmlDocument doc;
	doc.LinkEndChild(createElementContainerTag(elementContainer));
	::FILE* tmp = ::tmpfile();	// Si.. ya se... pero es una limitacion dada por tinyxml.
	doc.SaveFile(tmp);
	::rewind(tmp);
	const ::size_t buffersize = 1024;
	char buffer[buffersize+1];
	buffer[buffersize] = '\0';
	::size_t aux;
	do {
		aux = ::fread(buffer, sizeof(char), buffersize, tmp);
		buffer[aux] = '\0';
		str += buffer;
	} while (aux == buffersize);
	::fclose(tmp);
	return str;
}


void StageXmlRepositoryTinyXml::unserialize(const std::string& stageStr, ElementContainer& elementContainer) {
	::FILE* tmp = ::tmpfile();	// Si.. ya se... pero es una limitacion dada por tinyxml.
	::rewind(tmp);
	::fwrite(stageStr.c_str(), sizeof(char), stageStr.length(), tmp);
	TiXmlDocument doc;
	bool aux = doc.LoadFile(tmp);
	if (aux) {
		TiXmlHandle hDoc(&doc);
		loadElementContainer(hDoc.FirstChildElement().Element(), elementContainer);
	}
	::fclose(tmp);
}


TiXmlElement* StageXmlRepositoryTinyXml::createElementContainerTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(ELEMENTCONTAINER_TAG);
	tag->LinkEndChild(createBallTag(*elementContainer.getBall()));
	tag->LinkEndChild(createExitAreaCollectionTag(elementContainer));
	tag->LinkEndChild(createFixedPointCollectionTag(elementContainer));
	tag->LinkEndChild(createObstacleCollectionTag(elementContainer));
	tag->LinkEndChild(createCanvasTapeCollectionTag(elementContainer));
	tag->LinkEndChild(createMassCollectionTag(elementContainer));
	tag->LinkEndChild(createMetalBarCollectionTag(elementContainer));
	tag->LinkEndChild(createMetalPlatformCollectionTag(elementContainer));
	tag->LinkEndChild(createRopeCollectionTag(elementContainer));
	tag->LinkEndChild(createWheelCollectionTag(elementContainer));
	tag->LinkEndChild(createRocketCollectionTag(elementContainer));
	return tag;
}


void StageXmlRepositoryTinyXml::loadElementContainer(TiXmlElement* elementContainerTag, ElementContainer& elementContainer) {
	Ball* ball = new Ball(false);
	if (ball) {
		loadCenterRadiusElement(elementContainerTag->FirstChildElement(BALL_TAG), *ball);
		elementContainer.setBall(ball);
	}
	loadExitAreaCollection(elementContainerTag->FirstChildElement(EXIT_AREA_COLLECTION_TAG), elementContainer);
	loadFixedPointCollection(elementContainerTag->FirstChildElement(FIXED_POINT_COLLECTION_TAG), elementContainer);
	loadObstacleCollection(elementContainerTag->FirstChildElement(OBSTACLE_COLLECTION_TAG), elementContainer);
	loadCanvasTapeCollection(elementContainerTag->FirstChildElement(CANVASTAPE_COLLECTION_TAG), elementContainer);
	loadRocketCollection(elementContainerTag->FirstChildElement(ROCKET_COLLECTION_TAG), elementContainer);
	loadMassCollection(elementContainerTag->FirstChildElement(MASS_COLLECTION_TAG), elementContainer);
	loadMetalBarCollection(elementContainerTag->FirstChildElement(METALBAR_COLLECTION_TAG), elementContainer);
	loadMetalPlatformCollection(elementContainerTag->FirstChildElement(METALPLATAFORM_COLLECTION_TAG), elementContainer);
	loadRopeCollection(elementContainerTag->FirstChildElement(ROPE_COLLECTION_TAG), elementContainer);
	loadWheelCollection(elementContainerTag->FirstChildElement(WHEEL_COLLECTION_TAG), elementContainer);
}


void StageXmlRepositoryTinyXml::saveStage(const std::string& xml, const Stage& stage) {
	TiXmlDocument doc;

	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);

	doc.LinkEndChild(createStageTag(stage));
	doc.SaveFile(xml.c_str());
}


bool StageXmlRepositoryTinyXml::loadStage(const std::string& xml, Stage& stage) {
	TiXmlDocument doc(xml.c_str());
	bool aux = doc.LoadFile();
	if (aux) {
		TiXmlHandle hDoc(&doc);
		loadStage(hDoc.FirstChildElement().Element(), stage);
	}
	return aux;
}


TiXmlElement* StageXmlRepositoryTinyXml::createStageTag(const Stage& stage) {
	TiXmlElement* tag = new TiXmlElement(STAGE_TAG);

	tag->SetAttribute(STAGE_GRAVITY_ATTR, stage.getStageProperties().getGravity());
	tag->SetAttribute(STAGE_MAXTIME_ATTR, stage.getStageProperties().getTimeToSolve());
	tag->SetAttribute(STAGE_A_ATTR, stage.getStageProperties().getA());
	tag->SetAttribute(STAGE_B_ATTR, stage.getStageProperties().getB());
	tag->SetAttribute(STAGE_C_ATTR, stage.getStageProperties().getC());
	tag->SetAttribute(STAGE_D_ATTR, stage.getStageProperties().getD());

	tag->LinkEndChild(createMassPropertiesTag(stage.getMassProperties()));
	tag->LinkEndChild(createFromToElementPropertiesTag(METALBAR_PROPERTIES_TAG, stage.getMetalBarProperties()));
	tag->LinkEndChild(createFromToElementPropertiesTag(ROPE_PROPERTIES_TAG, stage.getRopeProperties()));
	tag->LinkEndChild(createWheelPropertiesTag(stage.getWheelProperties()));
	tag->LinkEndChild(createFromToElementPropertiesTag(METALPLATFORM_PROPERTIES_TAG, stage.getMetalPlatformProperties()));
	tag->LinkEndChild(createFromToElementPropertiesTag(CANVASTAPE_PROPERTIES_TAG, stage.getCanvasTapeProperties()));
	tag->LinkEndChild(createRocketPropertiesTag(stage.getRocketProperties()));
	tag->LinkEndChild(createCenterRadiusElementPropertiesTag(FIXEDPOINT_PROPERTIES_TAG, stage.getFixedPointProperties()));

	tag->LinkEndChild(createBallTag(*stage.getFixedElementsContainer().getBall()));
	tag->LinkEndChild(createExitAreaCollectionTag(stage.getFixedElementsContainer()));
	tag->LinkEndChild(createFixedPointCollectionTag(stage.getFixedElementsContainer()));
	tag->LinkEndChild(createObstacleCollectionTag(stage.getFixedElementsContainer()));

	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createCenterRadiusElementPropertiesTag(const std::string& tagname, const CenterRadiusElementProperties& centerRadiusElementProperties) {
	TiXmlElement* tag = new TiXmlElement(tagname.c_str());
	tag->SetAttribute(MAXRADIUS_ATTR, centerRadiusElementProperties.getMaxRadius());
	tag->SetAttribute(MINRADIUS_ATTR, centerRadiusElementProperties.getMinRadius());
	tag->SetAttribute(NUMBER_ATTR, centerRadiusElementProperties.getNumber());
	tag->SetAttribute(PRICE_ATTR, centerRadiusElementProperties.getPrice());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createFromToElementPropertiesTag(const std::string& tagname, const FromToElementProperties& fromToElementProperties) {
	TiXmlElement* tag = new TiXmlElement(tagname.c_str());
	tag->SetAttribute(MAXLENGTH_ATTR, fromToElementProperties.getMaxLength());
	tag->SetAttribute(MINLENGTH_ATTR, fromToElementProperties.getMinLength());
	tag->SetAttribute(NUMBER_ATTR, fromToElementProperties.getNumber());
	tag->SetAttribute(PRICE_ATTR, fromToElementProperties.getPrice());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createMassPropertiesTag(const MassProperties& massProperties) {
	TiXmlElement* tag = new TiXmlElement(MASS_PROPERTIES_TAG);
	tag->SetAttribute(MASS_ATTR, massProperties.getMass());
	tag->SetAttribute(MAXRADIUS_ATTR, massProperties.getMaxRadius());
	tag->SetAttribute(MINRADIUS_ATTR, massProperties.getMinRadius());
	tag->SetAttribute(NUMBER_ATTR, massProperties.getNumber());
	tag->SetAttribute(PRICE_ATTR, massProperties.getPrice());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createWheelPropertiesTag(const WheelProperties& wheelProperties) {
	TiXmlElement* tag = new TiXmlElement(WHEEL_PROPERTIES_TAG);
	tag->SetAttribute(TORQUE_ATTR, wheelProperties.getTorqueMagnitude());
	tag->SetAttribute(DECAYTIME_ATTR, wheelProperties.getDecayTime());
	tag->SetAttribute(MAXRADIUS_ATTR, wheelProperties.getMaxRadius());
	tag->SetAttribute(MINRADIUS_ATTR, wheelProperties.getMinRadius());
	tag->SetAttribute(NUMBER_ATTR, wheelProperties.getNumber());
	tag->SetAttribute(PRICE_ATTR, wheelProperties.getPrice());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createRocketPropertiesTag(const RocketProperties& rocketProperties) {
	TiXmlElement* tag = new TiXmlElement(ROCKET_PROPERTIES_TAG);
	tag->SetAttribute(DECAYTIME_ATTR, rocketProperties.getDecayTime());
	tag->SetAttribute(STRENGTH_ATTR, rocketProperties.getStrength());
	tag->SetAttribute(NUMBER_ATTR, rocketProperties.getNumber());
	tag->SetAttribute(PRICE_ATTR, rocketProperties.getPrice());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createCenterRadiusElementTag(const std::string& tagname, const CenterRadiusElement& centerRadiusElement) {
	TiXmlElement* tag = new TiXmlElement(tagname.c_str());
	tag->SetAttribute(POSX_ATTR, centerRadiusElement.getPosition().getX());
	tag->SetAttribute(POSY_ATTR, centerRadiusElement.getPosition().getY());
	tag->SetAttribute(RADIUSPOSX_ATTR, centerRadiusElement.getRadiusPosition().getX());
	tag->SetAttribute(RADIUSPOSY_ATTR, centerRadiusElement.getRadiusPosition().getY());
	tag->SetAttribute(RADIUS_ATTR, centerRadiusElement.getRadius());
	tag->SetAttribute(MAXRADIUS_ATTR, centerRadiusElement.getMaxRadius());
	tag->SetAttribute(MINRADIUS_ATTR, centerRadiusElement.getMinRadius());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createBallTag(const Ball& ball) {
	return createCenterRadiusElementTag(BALL_TAG, ball);
}


TiXmlElement* StageXmlRepositoryTinyXml::createExitAreaCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(EXIT_AREA_COLLECTION_TAG);
	const ElementContainer::ExitAreaCollection &exitAreas = elementContainer.getExitAreaCollection();
	for (ElementContainer::ExitAreaIterator it = exitAreas.begin(); it != exitAreas.end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createExitAreaTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createExitAreaTag(const ExitArea& exitArea) {
	return createCenterRadiusElementTag(EXIT_AREA_TAG, exitArea);
}


TiXmlElement* StageXmlRepositoryTinyXml::createFixedPointCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(FIXED_POINT_COLLECTION_TAG);
	const ElementContainer::FixedPointCollection &fixedPoints = elementContainer.getFixedPointCollection();
	for (ElementContainer::FixedPointIterator it = fixedPoints.begin(); it != fixedPoints.end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createFixedPointTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createFixedPointTag(const FixedPoint& fixedPoint) {
	return createCenterRadiusElementTag(FIXED_POINT_TAG, fixedPoint);
}


TiXmlElement* StageXmlRepositoryTinyXml::createObstacleCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(OBSTACLE_COLLECTION_TAG);
	const ElementContainer::ObstacleCollection &obstacles = elementContainer.getObstacleCollection();
	for (ElementContainer::ObstacleIterator it = obstacles.begin(); it != obstacles.end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createObstacleTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createFromToElementTag(const std::string& tagname, const FromToElement& fromToElement) {
	TiXmlElement* tag = new TiXmlElement(tagname.c_str());
	tag->SetAttribute(STARTPOSX_ATTR, fromToElement.getStartPosition().getX());
	tag->SetAttribute(STARTPOSY_ATTR, fromToElement.getStartPosition().getY());
	tag->SetAttribute(ENDPOSX_ATTR, fromToElement.getEndPosition().getX());
	tag->SetAttribute(ENDPOSY_ATTR, fromToElement.getEndPosition().getY());
	tag->SetAttribute(MAXLENGTH_ATTR, fromToElement.getMaximumLength());
	tag->SetAttribute(MINLENGTH_ATTR, fromToElement.getMinimumLength());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createObstacleTag(const Obstacle& obstacle) {
	return createFromToElementTag(OBSTACLE_TAG, obstacle);
}


TiXmlElement* StageXmlRepositoryTinyXml::createCanvasTapeCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(CANVASTAPE_COLLECTION_TAG);
	ElementContainer::CanvasTapeCollection::const_iterator it;
	for (it = elementContainer.getCanvasTapeCollection().begin(); it != elementContainer.getCanvasTapeCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createCanvasTapeTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createRocketCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(ROCKET_COLLECTION_TAG);
	ElementContainer::RocketCollection::const_iterator it;
	for (it = elementContainer.getRocketCollection().begin(); it != elementContainer.getRocketCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createRocketTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createRocketTag(const Rocket& rocket) {
	TiXmlElement* tag = new TiXmlElement(ROCKET_TAG);
	tag->SetAttribute(STARTPOSX_ATTR, rocket.getPosition().getX());
	tag->SetAttribute(STARTPOSY_ATTR, rocket.getPosition().getY());
	tag->SetAttribute(ENDPOSX_ATTR, rocket.getTarget().getX());
	tag->SetAttribute(ENDPOSY_ATTR, rocket.getTarget().getY());
	tag->SetAttribute(STRENGTH_ATTR, rocket.getStrength());
	tag->SetAttribute(DECAYTIME_ATTR, rocket.getDecayTime());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createCanvasTapeTag(const CanvasTape& canvasTape) {
	return createFromToElementTag(CANVASTAPE_TAG, canvasTape);
}


TiXmlElement* StageXmlRepositoryTinyXml::createMassCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(MASS_COLLECTION_TAG);
	ElementContainer::MassCollection::const_iterator it;
	for (it = elementContainer.getMassCollection().begin(); it != elementContainer.getMassCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createMassTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createMassTag(const Mass& mass) {
	TiXmlElement* tag = createCenterRadiusElementTag(MASS_TAG, mass);
	tag->SetAttribute(MASS_ATTR, mass.getMass());
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createMetalBarCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(METALBAR_COLLECTION_TAG);
	ElementContainer::MetalBarCollection::const_iterator it;
	for (it = elementContainer.getMetalBarCollection().begin(); it != elementContainer.getMetalBarCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createMetalBarTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createMetalBarTag(const MetalBar& metalBar) {
	return createFromToElementTag(METALBAR_TAG, metalBar);
}


TiXmlElement* StageXmlRepositoryTinyXml::createMetalPlatformCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(METALPLATAFORM_COLLECTION_TAG);
	ElementContainer::MetalPlatformCollection::const_iterator it;
	for (it = elementContainer.getMetalPlatformCollection().begin(); it != elementContainer.getMetalPlatformCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createMetalPlatformTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createMetalPlatformTag(const MetalPlatform& metalPlatform) {
	return createFromToElementTag(METALPLATAFORM_TAG, metalPlatform);
}


TiXmlElement* StageXmlRepositoryTinyXml::createRopeCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(ROPE_COLLECTION_TAG);
	ElementContainer::RopeCollection::const_iterator it;
	for (it = elementContainer.getRopeCollection().begin(); it != elementContainer.getRopeCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createRopeTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createRopeTag(const Rope& rope) {
	return createFromToElementTag(ROPE_TAG, rope);
}


TiXmlElement* StageXmlRepositoryTinyXml::createWheelCollectionTag(const ElementContainer& elementContainer) {
	TiXmlElement* tag = new TiXmlElement(WHEEL_COLLECTION_TAG);
	ElementContainer::WheelCollection::const_iterator it;
	for (it = elementContainer.getWheelCollection().begin(); it != elementContainer.getWheelCollection().end(); it++) {
		if (!(*it)->isErased()) tag->LinkEndChild(createWheelTag(**it));
	}
	return tag;
}


TiXmlElement* StageXmlRepositoryTinyXml::createWheelTag(const Wheel& wheel) {
	TiXmlElement* tag = createCenterRadiusElementTag(WHEEL_TAG, wheel);
	tag->SetAttribute(TORQUE_ATTR, wheel.getTorqueMagnitude());
	tag->SetAttribute(DECAYTIME_ATTR, wheel.getDecayTime());
	return tag;
}


void StageXmlRepositoryTinyXml::loadStage(TiXmlElement* stageTag, Stage& stage) {
	stage.clean();

	int i = 0;
	stageTag->QueryIntAttribute(STAGE_MAXTIME_ATTR, &i);
	stage.getStageProperties().setTimeToSolve(i);

	i = 0;
	stageTag->QueryIntAttribute(STAGE_GRAVITY_ATTR, &i);
	stage.getStageProperties().setGravity(i);

	i = 0;
	stageTag->QueryIntAttribute(STAGE_A_ATTR, &i);
	stage.getStageProperties().setA(i);

	i = 0;
	stageTag->QueryIntAttribute(STAGE_B_ATTR, &i);
	stage.getStageProperties().setB(i);

	i = 0;
	stageTag->QueryIntAttribute(STAGE_C_ATTR, &i);
	stage.getStageProperties().setC(i);

	i = 0;
	stageTag->QueryIntAttribute(STAGE_D_ATTR, &i);
	stage.getStageProperties().setD(i);

	loadFromToElementPropertiesTag(stageTag->FirstChildElement(METALBAR_PROPERTIES_TAG), stage.getMetalBarProperties());
	loadFromToElementPropertiesTag(stageTag->FirstChildElement(ROPE_PROPERTIES_TAG), stage.getRopeProperties());
	loadFromToElementPropertiesTag(stageTag->FirstChildElement(METALPLATFORM_PROPERTIES_TAG), stage.getMetalPlatformProperties());
	loadFromToElementPropertiesTag(stageTag->FirstChildElement(CANVASTAPE_PROPERTIES_TAG), stage.getCanvasTapeProperties());
	loadMassPropertiesTag(stageTag->FirstChildElement(MASS_PROPERTIES_TAG), stage.getMassProperties());
	loadWheelPropertiesTag(stageTag->FirstChildElement(WHEEL_PROPERTIES_TAG), stage.getWheelProperties());
	loadRocketPropertiesTag(stageTag->FirstChildElement(ROCKET_PROPERTIES_TAG), stage.getRocketProperties());
	loadCenterRadiusElementPropertiesTag(stageTag->FirstChildElement(FIXEDPOINT_PROPERTIES_TAG), stage.getFixedPointProperties());

	Ball* ball = stage.getFixedElementsFactory().createBall();
	if (ball) {
		loadCenterRadiusElement(stageTag->FirstChildElement(BALL_TAG), *ball);
		stage.getFixedElementsContainer().setBall(ball);
	}

	loadExitAreaCollection(stageTag->FirstChildElement(EXIT_AREA_COLLECTION_TAG), stage.getFixedElementsContainer(), stage.getFixedElementsFactory());
	loadFixedPointCollection(stageTag->FirstChildElement(FIXED_POINT_COLLECTION_TAG), stage.getFixedElementsContainer(), stage.getFixedElementsFactory());
	loadObstacleCollection(stageTag->FirstChildElement(OBSTACLE_COLLECTION_TAG), stage.getFixedElementsContainer(), stage.getFixedElementsFactory());
}


void StageXmlRepositoryTinyXml::loadCenterRadiusElementPropertiesTag(TiXmlElement* centerRadiusElementPropertiesTag, CenterRadiusElementProperties& centerRadiusElementProperties) {
	int i = 0;
	centerRadiusElementPropertiesTag->QueryIntAttribute(MAXRADIUS_ATTR, &i);
	centerRadiusElementProperties.setMaxRadius(i);

	i = 0;
	centerRadiusElementPropertiesTag->QueryIntAttribute(MINRADIUS_ATTR, &i);
	centerRadiusElementProperties.setMinRadius(i);

	i = 0;
	centerRadiusElementPropertiesTag->QueryIntAttribute(NUMBER_ATTR, &i);
	centerRadiusElementProperties.setNumber(i);

	i = 0;
	centerRadiusElementPropertiesTag->QueryIntAttribute(PRICE_ATTR, &i);
	centerRadiusElementProperties.setPrice(i);
}


void StageXmlRepositoryTinyXml::loadFromToElementPropertiesTag(TiXmlElement* fromToElementPropertiesTag, FromToElementProperties& fromToElementProperties) {
	int i = 0;
	fromToElementPropertiesTag->QueryIntAttribute(MAXLENGTH_ATTR, &i);
	fromToElementProperties.setMaxLength(i);

	i = 0;
	fromToElementPropertiesTag->QueryIntAttribute(MINLENGTH_ATTR, &i);
	fromToElementProperties.setMinLength(i);

	i = 0;
	fromToElementPropertiesTag->QueryIntAttribute(NUMBER_ATTR, &i);
	fromToElementProperties.setNumber(i);

	i = 0;
	fromToElementPropertiesTag->QueryIntAttribute(PRICE_ATTR, &i);
	fromToElementProperties.setPrice(i);
}


void StageXmlRepositoryTinyXml::loadMassPropertiesTag(TiXmlElement* massPropertiesTag, MassProperties& massProperties) {
	int i = 0;
	massPropertiesTag->QueryIntAttribute(MASS_ATTR, &i);
	massProperties.setMass(i);

	i = 0;
	massPropertiesTag->QueryIntAttribute(MAXRADIUS_ATTR, &i);
	massProperties.setMaxRadius(i);

	i = 0;
	massPropertiesTag->QueryIntAttribute(MINRADIUS_ATTR, &i);
	massProperties.setMinRadius(i);

	i = 0;
	massPropertiesTag->QueryIntAttribute(NUMBER_ATTR, &i);
	massProperties.setNumber(i);

	i = 0;
	massPropertiesTag->QueryIntAttribute(PRICE_ATTR, &i);
	massProperties.setPrice(i);
}


void StageXmlRepositoryTinyXml::loadWheelPropertiesTag(TiXmlElement* wheelPropertiesTag, WheelProperties& wheelProperties) {
	int i = 0;
	wheelPropertiesTag->QueryIntAttribute(TORQUE_ATTR, &i);
	wheelProperties.setTorqueMagnitude(i);

	i = 0;
	wheelPropertiesTag->QueryIntAttribute(DECAYTIME_ATTR, &i);
	wheelProperties.setDecayTime(i);

	i = 0;
	wheelPropertiesTag->QueryIntAttribute(MAXRADIUS_ATTR, &i);
	wheelProperties.setMaxRadius(i);

	i = 0;
	wheelPropertiesTag->QueryIntAttribute(MINRADIUS_ATTR, &i);
	wheelProperties.setMinRadius(i);

	i = 0;
	wheelPropertiesTag->QueryIntAttribute(NUMBER_ATTR, &i);
	wheelProperties.setNumber(i);

	i = 0;
	wheelPropertiesTag->QueryIntAttribute(PRICE_ATTR, &i);
	wheelProperties.setPrice(i);
}


void StageXmlRepositoryTinyXml::loadRocketPropertiesTag(TiXmlElement* rocketPropertiesTag, RocketProperties& rocketProperties) {
	int i = 0;
	rocketPropertiesTag->QueryIntAttribute(STRENGTH_ATTR, &i);
	rocketProperties.setStrength(i);

	i = 0;
	rocketPropertiesTag->QueryIntAttribute(DECAYTIME_ATTR, &i);
	rocketProperties.setDecayTime(i);

	i = 0;
	rocketPropertiesTag->QueryIntAttribute(NUMBER_ATTR, &i);
	rocketProperties.setNumber(i);

	i = 0;
	rocketPropertiesTag->QueryIntAttribute(PRICE_ATTR, &i);
	rocketProperties.setPrice(i);
}


void StageXmlRepositoryTinyXml::loadCenterRadiusElement(TiXmlElement* tag, CenterRadiusElement& element) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	tag->QueryIntAttribute(POSX_ATTR, &x);
	tag->QueryIntAttribute(POSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element.setPosition(vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(RADIUSPOSX_ATTR, &x);
	tag->QueryIntAttribute(RADIUSPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element.setRadiusPosition(vector2d);

	x = 0;
	tag->QueryIntAttribute(RADIUS_ATTR, &x);
	element.setRadius(x);
}


void StageXmlRepositoryTinyXml::loadExitAreaCollection(TiXmlElement* tag, ElementContainer& elementContainer, ElementFactoryImpl& elementFactory) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		ExitArea* exitArea = elementFactory.createExitArea();
		if (exitArea) {
			loadCenterRadiusElement(pElemChild, *exitArea);
			elementContainer.addExitArea(exitArea);
		}
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadExitAreaCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		ExitArea* exitArea = new ExitArea(false);
		if (exitArea) {
			loadCenterRadiusElement(pElemChild, *exitArea);
			elementContainer.addExitArea(exitArea);
		}
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadFixedPointCollection(TiXmlElement* tag, ElementContainer& elementContainer, ElementFactoryImpl& elementFactory) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		FixedPoint* element = elementFactory.createFixedPoint();
		if (element) {
			loadCenterRadiusElement(pElemChild, *element);
			elementContainer.addFixedPoint(element);
		}
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadFixedPointCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		FixedPoint* element = new FixedPoint(false);
		if (element) {
			loadCenterRadiusElement(pElemChild, *element);
			elementContainer.addFixedPoint(element);
		}
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadObstacleCollection(TiXmlElement* tag, ElementContainer& elementContainer, ElementFactoryImpl& elementFactory) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		Obstacle* element = loadObstacle(pElemChild, elementFactory);
		if (element) {
			elementContainer.addObstacle(element);
		}
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadObstacleCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		Obstacle* element = loadObstacle(pElemChild);
		if (element) {
			elementContainer.addObstacle(element);
		}
		pElemChild = pElemChild->NextSiblingElement();
	}
}


Obstacle* StageXmlRepositoryTinyXml::loadObstacle(TiXmlElement* tag, ElementFactoryImpl& elementFactory) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	Obstacle* obstacle = elementFactory.createObstacle(vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	obstacle->setEndPosition(vector2d);

	return obstacle;
}


Obstacle* StageXmlRepositoryTinyXml::loadObstacle(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	Obstacle* obstacle = new Obstacle(false, vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	obstacle->setEndPosition(vector2d);

	return obstacle;
}


CanvasTape* StageXmlRepositoryTinyXml::loadCanvasTape(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int min = 0;
	int max = 0;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	tag->QueryIntAttribute(MINLENGTH_ATTR, &min);
	tag->QueryIntAttribute(MAXLENGTH_ATTR, &max);
	vector2d.setX(x);
	vector2d.setY(y);
	CanvasTape* element = new CanvasTape(false, min, max, vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setEndPosition(vector2d);

	return element;
}


Mass* StageXmlRepositoryTinyXml::loadMass(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int min = 0;
	int max = 0;
	int mass = 0;
	int radius = 0;
	tag->QueryIntAttribute(POSX_ATTR, &x);
	tag->QueryIntAttribute(POSY_ATTR, &y);
	tag->QueryIntAttribute(MINRADIUS_ATTR, &min);
	tag->QueryIntAttribute(MAXRADIUS_ATTR, &max);
	tag->QueryIntAttribute(MASS_ATTR, &mass);
	vector2d.setX(x);
	vector2d.setY(y);
	Mass* element = new Mass(false, min, max, mass);
	element->setPosition(vector2d);
	element->setRadius(radius);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(RADIUSPOSX_ATTR, &x);
	tag->QueryIntAttribute(RADIUSPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setRadiusPosition(vector2d);

	return element;
}


MetalBar* StageXmlRepositoryTinyXml::loadMetalBar(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int min = 0;
	int max = 0;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	tag->QueryIntAttribute(MINLENGTH_ATTR, &min);
	tag->QueryIntAttribute(MAXLENGTH_ATTR, &max);
	vector2d.setX(x);
	vector2d.setY(y);
	MetalBar* element = new MetalBar(false, min, max, vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setEndPosition(vector2d);

	return element;
}


MetalPlatform* StageXmlRepositoryTinyXml::loadMetalPlatform(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int min = 0;
	int max = 0;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	tag->QueryIntAttribute(MINLENGTH_ATTR, &min);
	tag->QueryIntAttribute(MAXLENGTH_ATTR, &max);
	vector2d.setX(x);
	vector2d.setY(y);
	MetalPlatform* element = new MetalPlatform(false, min, max, vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setEndPosition(vector2d);

	return element;
}


Wheel* StageXmlRepositoryTinyXml::loadWheel(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int min = 0;
	int max = 0;
	int torque = 0;
	int time;
	int radius = 0;
	tag->QueryIntAttribute(POSX_ATTR, &x);
	tag->QueryIntAttribute(POSY_ATTR, &y);
	tag->QueryIntAttribute(MINRADIUS_ATTR, &min);
	tag->QueryIntAttribute(MAXRADIUS_ATTR, &max);
	tag->QueryIntAttribute(TORQUE_ATTR, &torque);
	tag->QueryIntAttribute(DECAYTIME_ATTR, &time);
	vector2d.setX(x);
	vector2d.setY(y);
	Wheel* element = new Wheel(false, min, max, torque, time);
	element->setPosition(vector2d);
	element->setRadius(radius);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(RADIUSPOSX_ATTR, &x);
	tag->QueryIntAttribute(RADIUSPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setRadiusPosition(vector2d);

	return element;
}


Rope* StageXmlRepositoryTinyXml::loadRope(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int min = 0;
	int max = 0;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	tag->QueryIntAttribute(MINLENGTH_ATTR, &min);
	tag->QueryIntAttribute(MAXLENGTH_ATTR, &max);
	vector2d.setX(x);
	vector2d.setY(y);
	Rope* element = new Rope(false, min, max, vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setEndPosition(vector2d);

	return element;
}


Rocket* StageXmlRepositoryTinyXml::loadRocket(TiXmlElement* tag) {
	Vector2d vector2d;
	int x = 0;
	int y = 0;
	int strength = 0;
	int time;
	tag->QueryIntAttribute(STARTPOSX_ATTR, &x);
	tag->QueryIntAttribute(STARTPOSY_ATTR, &y);
	tag->QueryIntAttribute(STRENGTH_ATTR, &strength);
	tag->QueryIntAttribute(DECAYTIME_ATTR, &time);
	vector2d.setX(x);
	vector2d.setY(y);
	Rocket* element = new Rocket(false, strength, time, vector2d);
	element->setPosition(vector2d);

	x = 0;
	y = 0;
	tag->QueryIntAttribute(ENDPOSX_ATTR, &x);
	tag->QueryIntAttribute(ENDPOSY_ATTR, &y);
	vector2d.setX(x);
	vector2d.setY(y);
	element->setTarget(vector2d);

	return element;
}


void StageXmlRepositoryTinyXml::loadCanvasTapeCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		CanvasTape* element = loadCanvasTape(pElemChild);
		if (element) elementContainer.addCanvasTape(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadMassCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		Mass* element = loadMass(pElemChild);
		if (element) elementContainer.addMass(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadMetalBarCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		MetalBar* element = loadMetalBar(pElemChild);
		if (element) elementContainer.addMetalBar(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadMetalPlatformCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		MetalPlatform* element = loadMetalPlatform(pElemChild);
		if (element) elementContainer.addMetalPlatform(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadRopeCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		Rope* element = loadRope(pElemChild);
		if (element) elementContainer.addRope(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadWheelCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		Wheel* element = loadWheel(pElemChild);
		if (element) elementContainer.addWheel(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


void StageXmlRepositoryTinyXml::loadRocketCollection(TiXmlElement* tag, ElementContainer& elementContainer) {
	TiXmlElement* pElemChild = tag->FirstChildElement();
	while (pElemChild) {
		Rocket* element = loadRocket(pElemChild);
		if (element) elementContainer.addRocket(element);
		pElemChild = pElemChild->NextSiblingElement();
	}
}


