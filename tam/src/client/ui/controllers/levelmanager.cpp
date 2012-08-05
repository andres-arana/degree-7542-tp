#include "levelmanager.h"
#include "logic/designtoolbox.h"
#include "views/blueprintrenderer.h"
#include "views/backgroundrenderer.h"
#include "views/design/elementcontainerdesignrenderer.h"
#include "views/runtime/elementcontainerruntimerenderer.h"
#include "views/connect/connectionpointsrenderer.h"
#include "views/move/movepointsrenderer.h"
#include "constants/gameconstants.h"
#include "serialization/model/stage.h"
#include <string>

using namespace client::ui::controllers;
using namespace common::constants;
using namespace game::core;
using namespace game::design::elements;
using namespace game::logic;
using namespace game::logic::properties;
using namespace game::serialization;
using namespace game::serialization::model;
using namespace ui::views;
using namespace ui::views::design;
using namespace ui::views::runtime;
using namespace ui::views::connect;
using namespace ui::views::move;
using namespace std;

LevelManager::LevelManager(GameEngine& gameEngine, GameRenderArea& gameRenderArea) :
	gameEngine(gameEngine),
	gameRenderArea(gameRenderArea) {

}

void LevelManager::loadLevel() {
	this->loadDesignRenderer();	
	this->loadRuntimeRenderer();
	this->loadConnectionRenderer();
	this->loadMoveRenderer();
	this->loadBackgroundRenderer();
	this->loadStage();
}

void LevelManager::loadDesignRenderer() {
	ElementContainerDesignRenderer *designRenderer = new ElementContainerDesignRenderer(gameEngine);
	this->gameRenderArea.addRendererToLayer(GameRenderArea::ElementDesignLayer, designRenderer);
}

void LevelManager::loadRuntimeRenderer() {
	ElementContainerRuntimeRenderer *runtimeRenderer = new ElementContainerRuntimeRenderer(gameEngine);
	this->gameRenderArea.addRendererToLayer(GameRenderArea::ElementRuntimeLayer, runtimeRenderer);
}

void LevelManager::loadConnectionRenderer() {
	ConnectionPointsRenderer *connectionPointsRenderer = new ConnectionPointsRenderer(gameEngine);
	this->gameRenderArea.addRendererToLayer(GameRenderArea::ConnectPointLayer, connectionPointsRenderer);
}

void LevelManager::loadMoveRenderer() {
	MovePointsRenderer *movePointsRenderer = new MovePointsRenderer(gameEngine);
	this->gameRenderArea.addRendererToLayer(GameRenderArea::MovePointLayer, movePointsRenderer);
}

void LevelManager::loadBackgroundRenderer() {
	try {
		string pathToBackgroundImg
				= GameConstants::TEMP_FOLDER_PATH + GameConstants::BACKGROUND_IMAGE_NAME;

		BackgroundRenderer* backgroundRenderer
				= new BackgroundRenderer(pathToBackgroundImg);
		this->gameRenderArea.addRendererToLayer(GameRenderArea::BackgroundLayer,
				backgroundRenderer);
	} catch (const Glib::Error& e) {
		// No hay imagen de fondo para este nivel.
		this->gameRenderArea.addRendererToLayer(GameRenderArea::BackgroundLayer,
				new BlueprintRenderer());
	}
}

void LevelManager::loadStage() {
	DesignToolbox& designToolbox = this->gameEngine.getDesignToolbox();
	Stage* stage = new Stage(this->gameEngine);
	string background;
	this->serializationDelegate.loadStage(
			GameConstants::TEMP_FOLDER_NAME, *stage, background);
	designToolbox.loadPropertiesFromStage(*stage);
	delete stage;
}
