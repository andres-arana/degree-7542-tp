#include "level.h"
#include "utils/fileutils.h"
#include "constants/gameconstants.h"
#include <fstream>

using namespace server::game::levels;
using namespace common::constants;
using namespace common::utils;
using namespace std;


Level::Level(const string& levelFolder, int number) : 
	levelFilePath(levelFolder + GameConstants::LEVEL_FILENAME),
	backgroundFilePath(levelFolder + GameConstants::BACKGROUND_IMAGE_NAME),
	number(number) {	
}

int Level::getLevelNumber() const {
	return this->number;
}

long Level::getLevelFileSize() const {
	return FileUtils::getFileSize(this->levelFilePath);
}

const string& Level::getLevelFilePath() const {
	return this->levelFilePath;
} 

long Level::getLevelBackgroundSize() const {
	return FileUtils::getFileSize(this->backgroundFilePath);
}

const string& Level::getLevelBackgroundPath() const {
	return this->backgroundFilePath;
}	
