#include "levelmanager.h"
#include "exceptions/nomorelevelsexception.h"
#include "utils/stringutils.h"
#include "utils/fileutils.h"
#include <algorithm>

using namespace server::game::levels;
using namespace server::game::levels::exceptions;
using namespace common::utils;
using namespace std;

string LevelManager::LEVELS_FOLDER = "levels/";

LevelManager::LevelManager() : 
	currentLevelPos(-1),
	timesSent(0) {
	this->setUpLevels();
	this->prepareNextLevel();
}

void LevelManager::setUpLevels() {
	int numberOfLevels = FileUtils::countDirs(LEVELS_FOLDER, true);
	for (int i = 1; i <= numberOfLevels; i++) {
		this->shuffledLevels.push_back(i);
	}
	random_shuffle(this->shuffledLevels.begin(), this->shuffledLevels.end());
}

void LevelManager::prepareNextLevel() {
	this->timesSent = 0;
	this->currentLevelPos++;
}

Level LevelManager::getCurrentLevel() const {
	if (this->currentLevelPos >= this->shuffledLevels.size()) {
		throw NoMoreLevelsException("Se han completado todos los niveles");
	}
	int levelNumber = this->shuffledLevels[this->currentLevelPos];
	string path = LevelManager::LEVELS_FOLDER 
			+ StringUtils::numberToString<int>(levelNumber) + "/";
	return Level(path, levelNumber);
}

void LevelManager::markCurrentLevelAsSent() {
	this->timesSent++;
}

int LevelManager::getLevelTimesSent() const {
	return this->timesSent;
}
