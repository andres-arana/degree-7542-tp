#ifndef EDITOR_PERSISTENCE_STAGEXMLREPOSITORYTINYXML_H_
#define EDITOR_PERSISTENCE_STAGEXMLREPOSITORYTINYXML_H_

#include "stagexmlrepository.h"
#include <string>
#include "tinyxml.h"
#include "../../logic/properties/stageproperties.h"
#include "../../logic/properties/fromtoelementproperties.h"
#include "../../logic/properties/wheelproperties.h"
#include "../../logic/properties/massproperties.h"
#include "../../logic/properties/rocketproperties.h"
#include "../../logic/properties/centerradiuselementproperties.h"
#include "../../design/elements/centerradiuselement.h"
#include "../../design/elements/ball.h"
#include "../../design/elements/exitarea.h"
#include "../../design/elements/fixedpoint.h"
#include "../../design/elements/obstacle.h"
#include "../../design/elementcontainer.h"

namespace game {
	namespace serialization {
		namespace persistence {
			/**
			 * Implementacion del repositorio de escenarios utilizando TinyXml como framework
			 * de persistencia.
			 * @version 1.0
			 * @created 23-Oct-2008 04:40:47 a.m.
			 */
			class StageXmlRepositoryTinyXml: virtual public StageXmlRepository {
				/**
				 * @param tagname Nombre que tendra el tag
				 * @param centerRadiusElement Objeto desde el que se extraeran los datos
				 * @return El tag correspontiente al CenterRadiusElement
				 */
				TiXmlElement* createCenterRadiusElementTag(const std::string& tagname, const game::design::elements::CenterRadiusElement& centerRadiusElement);
				/** @return El tag correspontiente a la pelota */
				TiXmlElement* createBallTag(const game::design::elements::Ball& ball);
				/** Carga los datos de un CenterRadiusElement a partir del tag de la pelota */
				void loadCenterRadiusElement(TiXmlElement* tag, game::design::elements::CenterRadiusElement& element);
				/** @return El tag correspontiente al area de salida */
				TiXmlElement* createExitAreaTag(const game::design::elements::ExitArea& exitArea);
				/** @return Todos los tags correspondientes a todas las areas de salida del escenario */
				TiXmlElement* createExitAreaCollectionTag(const game::design::ElementContainer& elementContainer);
				/** Carga todas las areas de salida en el escenario a partir del tag correspondiente */
				void loadExitAreaCollection(TiXmlElement* exitAreaCollectionTag, game::design::ElementContainer& elementContainer, game::serialization::model::ElementFactoryImpl& elementFactory);
				void loadExitAreaCollection(TiXmlElement* exitAreaCollectionTag, game::design::ElementContainer& elementContainer);
				/** @return Un tag para un punto fijo */
				TiXmlElement* createFixedPointTag(const game::design::elements::FixedPoint& fixedPoint);
				/** @return Un tag con todos los puntos fijos del escenario */
				TiXmlElement* createFixedPointCollectionTag(const game::design::ElementContainer& elementContainer);
				/** Carga todos los puntos fijos de un tag en el escenario */
				void loadFixedPointCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer, game::serialization::model::ElementFactoryImpl& elementFactory);
				void loadFixedPointCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				/** @return Un tag para un obstaculo */
				TiXmlElement* createObstacleTag(const game::design::elements::Obstacle& obstacle);
				/** @return Un tag con todos los obstaculos del escenario */
				TiXmlElement* createObstacleCollectionTag(const game::design::ElementContainer& elementContainer);
				/** @return Un obstaculo a partir de su correspondiente tag */
				game::design::elements::Obstacle* loadObstacle(TiXmlElement* tag, game::serialization::model::ElementFactoryImpl& elementFactory);
				game::design::elements::Obstacle* loadObstacle(TiXmlElement* tag);
				/** Carga todos los obstaculos en el escenario a partir de un tag */
				void loadObstacleCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer, game::serialization::model::ElementFactoryImpl& elementFactory);
				void loadObstacleCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				TiXmlElement* createCenterRadiusElementPropertiesTag(const std::string& tagname, const game::logic::properties::CenterRadiusElementProperties& centerRadiusElementProperties);
				/** Crea el tag correspondiente a las propiedades de los cohetes */
				TiXmlElement* createRocketPropertiesTag(const game::logic::properties::RocketProperties& rocketProperties);
				/** Crea el tag correspondiente a las propiedades de las ruedas */
				TiXmlElement* createWheelPropertiesTag(const game::logic::properties::WheelProperties& wheelProperties);
				/** Crea el tag correspondiente a las propiedades de las masas */
				TiXmlElement* createMassPropertiesTag(const game::logic::properties::MassProperties& massProperties);
				TiXmlElement* createFromToElementPropertiesTag(const std::string& tagname, const game::logic::properties::FromToElementProperties& metalBarProperties);
				/** @return El elemento stage del xml */
				TiXmlElement* createStageTag(const game::serialization::model::Stage& stage);
				/** Crea un escenario a partir de un tag xml */
				void loadStage(TiXmlElement* stageTag, game::serialization::model::Stage& stage);
				void loadFromToElementPropertiesTag(TiXmlElement* fromToElementPropertiesTag, game::logic::properties::FromToElementProperties& fromToElementProperties);
				/** Crea las propiedades de las masas a partir del tag xml */
				void loadMassPropertiesTag(TiXmlElement* massPropertiesTag, game::logic::properties::MassProperties& massProperties);
				/** Crea las propiedades de las ruedas a partir del tag xml */
				void loadWheelPropertiesTag(TiXmlElement* wheelPropertiesTag, game::logic::properties::WheelProperties& wheelProperties);
				/** Crea las propiedades de los cohetes a partir del tag xml */
				void loadRocketPropertiesTag(TiXmlElement* rocketPropertiesTag, game::logic::properties::RocketProperties& rocketProperties);
				void loadCenterRadiusElementPropertiesTag(TiXmlElement* centerRadiusElementPropertiesTag, game::logic::properties::CenterRadiusElementProperties& centerRadiusElementProperties);
				TiXmlElement* createCanvasTapeCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createRocketCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createMassCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createMetalBarCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createMetalPlatformCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createRopeCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createWheelCollectionTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createCanvasTapeTag(const game::design::elements::CanvasTape& canvasTape);
				TiXmlElement* createRocketTag(const game::design::elements::Rocket& rocket);
				TiXmlElement* createMassTag(const game::design::elements::Mass& mass);
				TiXmlElement* createMetalBarTag(const game::design::elements::MetalBar& metalBar);
				TiXmlElement* createMetalPlatformTag(const game::design::elements::MetalPlatform& metalPlatform);
				TiXmlElement* createRopeTag(const game::design::elements::Rope& rope);
				TiXmlElement* createWheelTag(const game::design::elements::Wheel& wheel);
				TiXmlElement* createElementContainerTag(const game::design::ElementContainer& elementContainer);
				TiXmlElement* createFromToElementTag(const std::string& tagname, const game::design::elements::FromToElement& fromToElement);
				void loadElementContainer(TiXmlElement* elementContainerTag, game::design::ElementContainer& elementContainer);
				void loadCanvasTapeCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				void loadRocketCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				void loadMassCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				void loadMetalBarCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				void loadMetalPlatformCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				void loadRopeCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				void loadWheelCollection(TiXmlElement* tag, game::design::ElementContainer& elementContainer);
				game::design::elements::CanvasTape* loadCanvasTape(TiXmlElement* tag);
				game::design::elements::Rocket* loadRocket(TiXmlElement* tag);
				game::design::elements::Mass* loadMass(TiXmlElement* tag);
				game::design::elements::MetalBar* loadMetalBar(TiXmlElement* tag);
				game::design::elements::MetalPlatform* loadMetalPlatform(TiXmlElement* tag);
				game::design::elements::Rope* loadRope(TiXmlElement* tag);
				game::design::elements::Wheel* loadWheel(TiXmlElement* tag);
			public:
				virtual ~StageXmlRepositoryTinyXml() {}
				/**
				 * Graba un escenario en un archivo xml
				 * @param xml    Nombre y ruta del archivo xml en que se quiere persistir el
				 * escenario
				 * @param stage    Escenario que se quiere persistir
				 */
				virtual void saveStage(const std::string& xml, const game::serialization::model::Stage& stage);
				/**
				 * Recupera un escenario a partir de un xml
				 * @param xml    Path del xml
				 * @param stage    Escenario recuperado
				 * @return true si el escenario pudo cargarse con exito y false en otro caso
				 */
				virtual bool loadStage(const std::string& xml, game::serialization::model::Stage& stage);
				/** @return Un string con la informacion de todos los elementos del elementContainer */
				virtual std::string serialize(const game::design::ElementContainer& elementContainer);
				/**
				 * Llena el elementContainer con los elementos generados a partir del stageStr,
				 * generado previamente por el metodo serialize
				 */
				virtual void unserialize(const std::string& stageStr, game::design::ElementContainer& elementContainer);
			};
		}
	}
}
#endif // EDITOR_PERSISTENCE_STAGEXMLREPOSITORYTINYXML_H_

