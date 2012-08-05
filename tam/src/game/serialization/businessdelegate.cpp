#include "businessdelegate.h"
#include "service/servicelocator.h"

using game::serialization::BusinessDelegate;
using game::serialization::service::ServiceLocator;
using game::design::ElementContainer;


void BusinessDelegate::saveStage(const std::string& folder,
		const Stage& stage, const std::string& background) {
	m_ServiceLocator.getStageService().saveStage(folder, stage, background);
}


bool BusinessDelegate::loadStage(const std::string& folder,
		Stage& stage, std::string& background) {
	return m_ServiceLocator.getStageService().loadStage(folder, stage, background);
}


std::string BusinessDelegate::serialize(const ElementContainer& elementContainer) {
	return m_ServiceLocator.getStageService().serialize(elementContainer);
}


void BusinessDelegate::unserialize(const std::string& stageStr, ElementContainer& elementContainer) {
	m_ServiceLocator.getStageService().unserialize(stageStr, elementContainer);
}

