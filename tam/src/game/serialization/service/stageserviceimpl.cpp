#include "stageserviceimpl.h"
#include "utils/fileutils.h"
#include "constants/gameconstants.h"

using game::serialization::service::StageServiceImpl;
using game::serialization::persistence::RepositoryFactory;
using namespace common::constants;
using namespace common::utils;

void StageServiceImpl::saveStage(const std::string& folder,
		const Stage& stage, const std::string& background) {

	if (!background.empty()) {
		FileUtils::copy(background, folder + "/" + GameConstants::BACKGROUND_IMAGE_NAME);
	}
	m_RepositoryFactory.getStageXmlRepository().saveStage(
			folder + "/" + GameConstants::LEVEL_FILENAME, stage);
}


bool StageServiceImpl::loadStage(const std::string& folder,
		Stage& stage, std::string& background) {

	background = folder + "/" + GameConstants::BACKGROUND_IMAGE_NAME;
	if (!FileUtils::fileExists(background)) background.clear();
	return m_RepositoryFactory.getStageXmlRepository().loadStage(
			folder + "/" + GameConstants::LEVEL_FILENAME, stage);
}


std::string StageServiceImpl::serialize(const game::design::ElementContainer& elementContainer) {
	return m_RepositoryFactory.getStageXmlRepository().serialize(elementContainer);
}


void StageServiceImpl::unserialize(const std::string& stageStr, game::design::ElementContainer& elementContainer) {
	m_RepositoryFactory.getStageXmlRepository().unserialize(stageStr, elementContainer);
}
