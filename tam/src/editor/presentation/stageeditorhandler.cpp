#include "stageeditorhandler.h"

using editor::presentation::StageEditorHandler;
using game::serialization::model::Stage;
using game::design::ElementContainer;
using game::serialization::model::ElementFactoryImpl;


bool StageEditorHandler::saveStage(const std::string& stageName) {
	stage.getStageProperties().setA(m_StageEditorGui.getA());
	stage.getStageProperties().setB(m_StageEditorGui.getB());
	stage.getStageProperties().setC(m_StageEditorGui.getC());
	stage.getStageProperties().setD(m_StageEditorGui.getD());
	stage.getStageProperties().setGravity(m_StageEditorGui.getGravity());
	stage.getStageProperties().setTimeToSolve(m_StageEditorGui.getMaxTime());

	stage.getMetalBarProperties().setMaxLength(m_StageEditorGui.getMetalBarMaxSize());
	stage.getMetalBarProperties().setMinLength(m_StageEditorGui.getMetalBarMinSize());
	stage.getMetalBarProperties().setNumber(m_StageEditorGui.getMetalBarCount());
	stage.getMetalBarProperties().setPrice(m_StageEditorGui.getMetalBarPrice());

	stage.getMetalPlatformProperties().setMaxLength(m_StageEditorGui.getPlataformMaxSize());
	stage.getMetalPlatformProperties().setMinLength(m_StageEditorGui.getPlataformMinSize());
	stage.getMetalPlatformProperties().setNumber(m_StageEditorGui.getPlataformCount());
	stage.getMetalPlatformProperties().setPrice(m_StageEditorGui.getPlataformPrice());

	stage.getRopeProperties().setMaxLength(m_StageEditorGui.getRopeMaxSize());
	stage.getRopeProperties().setMinLength(m_StageEditorGui.getRopeMinSize());
	stage.getRopeProperties().setNumber(m_StageEditorGui.getRopeCount());
	stage.getRopeProperties().setPrice(m_StageEditorGui.getRopePrice());

	stage.getCanvasTapeProperties().setMaxLength(m_StageEditorGui.getCanvasTapeMaxSize());
	stage.getCanvasTapeProperties().setMinLength(m_StageEditorGui.getCanvasTapeMinSize());
	stage.getCanvasTapeProperties().setNumber(m_StageEditorGui.getCanvasTapeCount());
	stage.getCanvasTapeProperties().setPrice(m_StageEditorGui.getCanvasTapePrice());

	stage.getWheelProperties().setDecayTime(m_StageEditorGui.getWheelDecayTime());
	stage.getWheelProperties().setMaxRadius(m_StageEditorGui.getWheelMaxSize());
	stage.getWheelProperties().setMinRadius(m_StageEditorGui.getWheelMinSize());
	stage.getWheelProperties().setNumber(m_StageEditorGui.getWheelCount());
	stage.getWheelProperties().setPrice(m_StageEditorGui.getWheelPrice());
	stage.getWheelProperties().setTorqueMagnitude(m_StageEditorGui.getWheelTorke());

	stage.getMassProperties().setMass(m_StageEditorGui.getMass());
	stage.getMassProperties().setMaxRadius(m_StageEditorGui.getMassMaxSize());
	stage.getMassProperties().setMinRadius(m_StageEditorGui.getMassMinSize());
	stage.getMassProperties().setNumber(m_StageEditorGui.getMassCount());
	stage.getMassProperties().setPrice(m_StageEditorGui.getMassPrice());

	stage.getRocketProperties().setDecayTime(m_StageEditorGui.getRocketDecayTime());
	stage.getRocketProperties().setNumber(m_StageEditorGui.getRocketCount());
	stage.getRocketProperties().setPrice(m_StageEditorGui.getRocketPrice());
	stage.getRocketProperties().setStrength(m_StageEditorGui.getRocketStrength());

	stage.getFixedPointProperties().setMaxRadius(m_StageEditorGui.getFixedPointMaxSize());
	stage.getFixedPointProperties().setMinRadius(m_StageEditorGui.getFixedPointMinSize());
	stage.getFixedPointProperties().setNumber(m_StageEditorGui.getFixedPointCount());
	stage.getFixedPointProperties().setPrice(m_StageEditorGui.getFixedPointPrice());

	m_BusinessDelegate.saveStage(stageName, stage, m_StageEditorGui.getBackground());
	m_StageEditorGui.showStageName(stageName);

	return true;
}


void StageEditorHandler::saveStage() {
	if (m_StageName.empty()) saveAsStage();
	else if (m_StageEditorGui.validate()) saveStage(m_StageName);
}


void StageEditorHandler::saveAsStage() {
	if (m_StageEditorGui.validate()) {
		std::string folder;
		if (m_StageEditorGui.showFolderChooserDialog(folder, true) && saveStage(folder)) m_StageName = folder;
	}
}


void StageEditorHandler::loadStage() {
	newStage();
	std::string folder;
	if (m_StageEditorGui.showFolderChooserDialog(folder, false)) {
		std::string background;

		if (!m_BusinessDelegate.loadStage(folder, stage, background)) {
			m_StageEditorGui.showMessageError("La carpeta seleccionada no contiene ningun escenario.");
		} else {
			m_StageName = folder;
			m_StageEditorGui.setBackground(background);
			m_StageEditorGui.showStageName(folder);

			unsigned i = stage.getStageProperties().getA();
			if (i) m_StageEditorGui.setA(i);
			i = stage.getStageProperties().getB();
			if (i) m_StageEditorGui.setB(i);
			i = stage.getStageProperties().getC();
			if (i) m_StageEditorGui.setC(i);
			i = stage.getStageProperties().getD();
			if (i) m_StageEditorGui.setD(i);
			i = stage.getStageProperties().getGravity();
			if (i) m_StageEditorGui.setGravity(i);
			i = stage.getStageProperties().getTimeToSolve();
			if (i) m_StageEditorGui.setMaxTime(i);

			i = stage.getMetalBarProperties().getNumber();
			if (i) m_StageEditorGui.setMetalBarCount(i);
			i = stage.getMetalBarProperties().getMaxLength();
			if (i) m_StageEditorGui.setMetalBarMaxSize(i);
			i = stage.getMetalBarProperties().getMinLength();
			if (i) m_StageEditorGui.setMetalBarMinSize(i);
			i = stage.getMetalBarProperties().getPrice();
			if (i) m_StageEditorGui.setMetalBarPrice(i);

			i = stage.getMetalPlatformProperties().getNumber();
			if (i) m_StageEditorGui.setPlataformCount(i);
			i = stage.getMetalPlatformProperties().getMaxLength();
			if (i) m_StageEditorGui.setPlataformMaxSize(i);
			i = stage.getMetalPlatformProperties().getMinLength();
			if (i) m_StageEditorGui.setPlataformMinSize(i);
			i = stage.getMetalPlatformProperties().getPrice();
			if (i) m_StageEditorGui.setPlataformPrice(i);

			i = stage.getRopeProperties().getNumber();
			if (i) m_StageEditorGui.setRopeCount(i);
			i = stage.getRopeProperties().getMaxLength();
			if (i) m_StageEditorGui.setRopeMaxSize(i);
			i = stage.getRopeProperties().getMinLength();
			if (i) m_StageEditorGui.setRopeMinSize(i);
			i = stage.getRopeProperties().getPrice();
			if (i) m_StageEditorGui.setRopePrice(i);

			i = stage.getCanvasTapeProperties().getNumber();
			if (i) m_StageEditorGui.setCanvasTapeCount(i);
			i = stage.getCanvasTapeProperties().getMaxLength();
			if (i) m_StageEditorGui.setCanvasTapeMaxSize(i);
			i = stage.getCanvasTapeProperties().getMinLength();
			if (i) m_StageEditorGui.setCanvasTapeMinSize(i);
			i = stage.getCanvasTapeProperties().getPrice();
			if (i) m_StageEditorGui.setCanvasTapePrice(i);

			i = stage.getWheelProperties().getNumber();
			if (i) m_StageEditorGui.setWheelCount(i);
			i = stage.getWheelProperties().getDecayTime();
			if (i) m_StageEditorGui.setWheelDecayTime(i);
			i = stage.getWheelProperties().getMaxRadius();
			if (i) m_StageEditorGui.setWheelMaxSize(i);
			i = stage.getWheelProperties().getMinRadius();
			if (i) m_StageEditorGui.setWheelMinSize(i);
			i = stage.getWheelProperties().getPrice();
			if (i) m_StageEditorGui.setWheelPrice(i);
			i = stage.getWheelProperties().getTorqueMagnitude();
			if (i) m_StageEditorGui.setWheelTorke(i);

			i = stage.getMassProperties().getMass();
			if (i) m_StageEditorGui.setMass(i);
			i = stage.getMassProperties().getNumber();
			if (i) m_StageEditorGui.setMassCount(i);
			i = stage.getMassProperties().getPrice();
			if (i) m_StageEditorGui.setMassPrice(i);
			i = stage.getMassProperties().getMaxRadius();
			if (i) m_StageEditorGui.setMassMaxSize(i);
			i = stage.getMassProperties().getMinRadius();
			if (i) m_StageEditorGui.setMassMinSize(i);

			i = stage.getRocketProperties().getNumber();
			if (i) m_StageEditorGui.setRocketCount(i);
			i = stage.getRocketProperties().getDecayTime();
			if (i) m_StageEditorGui.setRocketDecayTime(i);
			i = stage.getRocketProperties().getPrice();
			if (i) m_StageEditorGui.setRocketPrice(i);
			i = stage.getRocketProperties().getStrength();
			if (i) m_StageEditorGui.setRocketStrength(i);

			i = stage.getFixedPointProperties().getNumber();
			if (i) m_StageEditorGui.setFixedPointCount(i);
			i = stage.getFixedPointProperties().getPrice();
			if (i) m_StageEditorGui.setFixedPointPrice(i);
			i = stage.getFixedPointProperties().getMaxRadius();
			if (i) m_StageEditorGui.setFixedPointMaxSize(i);
			i = stage.getFixedPointProperties().getMinRadius();
			if (i) m_StageEditorGui.setFixedPointMinSize(i);
		}
	}
}


void StageEditorHandler::newStage() {
	m_StageName.clear();
	m_StageEditorGui.clear();
	stage.clean();
}


ElementContainer& StageEditorHandler::getElementContainer() {
	return stage.getFixedElementsContainer();
}


ElementFactoryImpl& StageEditorHandler::getElementFactory() {
	return stage.getFixedElementsFactory();
}


