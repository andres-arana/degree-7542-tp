#ifndef EDITOR_DOMAIN_MODEL_STAGE_H_
#define EDITOR_DOMAIN_MODEL_STAGE_H_

#include <vector>

#include "../../logic/properties/stageproperties.h"
#include "../../logic/properties/fromtoelementproperties.h"
#include "../../logic/properties/wheelproperties.h"
#include "../../logic/properties/massproperties.h"
#include "../../logic/properties/rocketproperties.h"
#include "../../logic/properties/centerradiuselementproperties.h"
#include "../../design/elementcontainer.h"
#include "elementfactoryimpl.h"


namespace game {
	namespace serialization {
		namespace model {
			/**
			 * Representacion de un escenario
			 * @version 1.0
			 * @created 23-Oct-2008 04:36:42 a.m.
			 */
			class Stage {
				// Propiedades del escenario
				game::logic::properties::StageProperties m_StageProperties;
				// Propiedades de las barras metalicas
				game::logic::properties::FromToElementProperties m_MetalBarProperties;
				// Propiedades de las plataformas
				game::logic::properties::FromToElementProperties m_PlatformProperties;
				// Propiedades de las sogas
				game::logic::properties::FromToElementProperties m_RopeProperties;
				// Propiedades de las cintas de lona
				game::logic::properties::FromToElementProperties m_CanvasTapeProperties;
				// Propiedades de las ruedas
				game::logic::properties::WheelProperties m_WheelProperties;
				// Propiedades de las masas
				game::logic::properties::MassProperties m_MassProperties;
				// Propiedades de los cohetes
				game::logic::properties::RocketProperties m_RocketProperties;
				// Propiedades de los puntos fijos
				game::logic::properties::CenterRadiusElementProperties m_FixedPointProperties;
				// Elementos del escenario
				game::design::ElementContainer& m_ElementContainer;
				// Fabrica de los elementos del escenario
				game::serialization::model::ElementFactoryImpl m_ElementFactoryImpl;
			public:
				Stage(game::design::ElementContainer& elementContainer, bool editableMode = false) : m_ElementContainer(elementContainer), m_ElementFactoryImpl(editableMode) {}
				/** @return El contenedor de los elementos del escenario */
				game::design::ElementContainer& getFixedElementsContainer() {return m_ElementContainer;}
				/** @return La fabrica de los elementos del escenario */
				game::serialization::model::ElementFactoryImpl& getFixedElementsFactory() {return m_ElementFactoryImpl;}
				/** @return El contenedor de los elementos del escenario */
				const game::design::ElementContainer& getFixedElementsContainer() const {return m_ElementContainer;}
				/** @return Las propiedades del escenario */
				game::logic::properties::StageProperties& getStageProperties() {return m_StageProperties;}
				/** @return Las propiedades del escenario */
				const game::logic::properties::StageProperties& getStageProperties() const {return m_StageProperties;}
				/** Asigna las propiedades del escenario */
				void setStageProperties(game::logic::properties::StageProperties stageProperties) {m_StageProperties = stageProperties;}
				/** @return Las propiedades de las barras metalicas */
				game::logic::properties::FromToElementProperties& getMetalBarProperties() {return m_MetalBarProperties;}
				/** @return Las propiedades de las barras metalicas */
				const game::logic::properties::FromToElementProperties& getMetalBarProperties() const {return m_MetalBarProperties;}
				/** Asigna las propiedades de las barras metalicas */
				void setMetalBarProperties(const game::logic::properties::FromToElementProperties& metalBarProperties) {m_MetalBarProperties = metalBarProperties;}
				/** @return las propiedades de las plataformas */
				game::logic::properties::FromToElementProperties& getMetalPlatformProperties() {return m_PlatformProperties;}
				/** @return las propiedades de las plataformas */
				const game::logic::properties::FromToElementProperties& getMetalPlatformProperties() const {return m_PlatformProperties;}
				/** Asigna las propiedades de las plataformas */
				void setMetalPlatformProperties(const game::logic::properties::FromToElementProperties& platformProperties) {m_PlatformProperties = platformProperties;}
				/** @return Las propiedades se las sogas */
				game::logic::properties::FromToElementProperties& getRopeProperties() {return m_RopeProperties;}
				/** @return Las propiedades se las sogas */
				const game::logic::properties::FromToElementProperties& getRopeProperties() const {return m_RopeProperties;}
				/** Asigna las propiedades se las sogas */
				void setRopeProperties(const game::logic::properties::FromToElementProperties& ropeProperties) {m_RopeProperties = ropeProperties;}
				/** @return Las propiedades se las cintas de lona */
				game::logic::properties::FromToElementProperties& getCanvasTapeProperties() {return m_CanvasTapeProperties;}
				/** @return Las propiedades se las cintas de lona */
				const game::logic::properties::FromToElementProperties& getCanvasTapeProperties() const {return m_CanvasTapeProperties;}
				/** Asigna las propiedades se las cintas de lona */
				void setCanvasTapeProperties(const game::logic::properties::FromToElementProperties& canvasTapeProperties) {m_CanvasTapeProperties = canvasTapeProperties;}
				/** @return Las propiedades se las ruedas */
				game::logic::properties::WheelProperties& getWheelProperties() {return m_WheelProperties;}
				/** @return Las propiedades se las ruedas */
				const game::logic::properties::WheelProperties& getWheelProperties() const {return m_WheelProperties;}
				/** Asigna las propiedades se las ruedas */
				void setWheelProperties(const game::logic::properties::WheelProperties& wheelProperties) {m_WheelProperties = wheelProperties;}
				/** @return Las propiedades de las masas */
				game::logic::properties::MassProperties& getMassProperties() {return m_MassProperties;}
				/** @return Las propiedades de las masas */
				const game::logic::properties::MassProperties& getMassProperties() const {return m_MassProperties;}
				/** Asigna las propiedades de las masas */
				void setMassProperties(const game::logic::properties::MassProperties& massProperties) {m_MassProperties = massProperties;}
				/** @return Las propiedades se los cohetes */
				game::logic::properties::RocketProperties& getRocketProperties() {return m_RocketProperties;}
				/** @return Las propiedades se los cohetes */
				const game::logic::properties::RocketProperties& getRocketProperties() const {return m_RocketProperties;}
				/** Asigna las propiedades se los cohetes */
				void setRocketProperties(const game::logic::properties::RocketProperties& rocketProperties) {m_RocketProperties = rocketProperties;}
				/** @return Las propiedades se los puntos fijos */
				game::logic::properties::CenterRadiusElementProperties& getFixedPointProperties() {return m_FixedPointProperties;}
				/** @return Las propiedades se los puntos fijos */
				const game::logic::properties::CenterRadiusElementProperties& getFixedPointProperties() const {return m_FixedPointProperties;}
				/** Asigna las propiedades se los puntos fijos */
				void setFixedPointProperties(const game::logic::properties::CenterRadiusElementProperties& fixedPointProperties) {m_FixedPointProperties = fixedPointProperties;}
				/** Elimina la informacion del escenario */
				void clean() {m_ElementContainer.clearElements();}
			};
		}
	}
}
#endif // EDITOR_DOMAIN_MODEL_STAGE_H_
