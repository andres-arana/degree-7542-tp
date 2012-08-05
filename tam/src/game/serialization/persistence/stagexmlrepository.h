#ifndef EDITOR_PERSISTENCE_STAGEXMLREPOSITORY_H_
#define EDITOR_PERSISTENCE_STAGEXMLREPOSITORY_H_

#include <string>
#include "../model/stage.h"
#include "../../design/elementcontainer.h"

#define STAGE_TAG "Stage"
#define STAGE_GRAVITY_ATTR "gravity"
#define STAGE_MAXTIME_ATTR "maxtime"
#define STAGE_A_ATTR "a"
#define STAGE_B_ATTR "b"
#define STAGE_C_ATTR "c"
#define STAGE_D_ATTR "d"
#define BALL_TAG "Ball"
#define POSX_ATTR "posx"
#define POSY_ATTR "posy"
#define RADIUSPOSX_ATTR "radiusposx"
#define RADIUSPOSY_ATTR "radiusposy"
#define STARTPOSX_ATTR "startposx"
#define STARTPOSY_ATTR "startposy"
#define ENDPOSX_ATTR "endposx"
#define ENDPOSY_ATTR "endposy"
#define RADIUS_ATTR "radius"
#define EXIT_AREA_COLLECTION_TAG "ExitAreaCollection"
#define EXIT_AREA_TAG "ExitArea"
#define FIXED_POINT_COLLECTION_TAG "FixedPointCollection"
#define FIXED_POINT_TAG "FixedPoint"
#define OBSTACLE_COLLECTION_TAG "ObstacleCollection"
#define OBSTACLE_TAG "Obstacle"
#define NUMBER_ATTR "number"
#define PRICE_ATTR "price"
#define MAXLENGTH_ATTR "maxlength"
#define MINLENGTH_ATTR "minlength"
#define MAXRADIUS_ATTR "maxradius"
#define MINRADIUS_ATTR "minradius"
#define MASS_ATTR "mass"
#define TORQUE_ATTR "torque"
#define DECAYTIME_ATTR "decaytime"
#define STRENGTH_ATTR "strength"
#define MASS_TAG "Mass"
#define MASS_COLLECTION_TAG "MassCollection"
#define METALBAR_TAG "MetalBar"
#define METALBAR_COLLECTION_TAG "MetalBarCollection"
#define ROPE_TAG "Rope"
#define ROPE_COLLECTION_TAG "RopeCollection"
#define WHEEL_TAG "Wheel"
#define WHEEL_COLLECTION_TAG "WheelCollection"
#define METALPLATAFORM_TAG "MetalPlataform"
#define METALPLATAFORM_COLLECTION_TAG "MetalPlataformCollection"
#define CANVASTAPE_TAG "CanvasTape"
#define CANVASTAPE_COLLECTION_TAG "CanvasTapeCollection"
#define ROCKET_TAG "Rocket"
#define ROCKET_COLLECTION_TAG "RocketCollection"
#define MASS_PROPERTIES_TAG "MassProperties"
#define METALBAR_PROPERTIES_TAG "MetalBarProperties"
#define ROPE_PROPERTIES_TAG "RopeProperties"
#define WHEEL_PROPERTIES_TAG "WheelProperties"
#define METALPLATFORM_PROPERTIES_TAG "MetalPlatformProperties"
#define CANVASTAPE_PROPERTIES_TAG "CanvasTapeProperties"
#define ROCKET_PROPERTIES_TAG "RocketProperties"
#define FIXEDPOINT_PROPERTIES_TAG "FixedPointProperties"
#define ELEMENTCONTAINER_TAG "ElementContainer"

namespace game {
	namespace serialization {
		namespace persistence {
			/**
			 * Esta clase se encarga de las operaciones de persistencia para los escenarios.
			 * @version 1.0
			 * @created 23-Oct-2008 04:40:46 a.m.
			 */
			class StageXmlRepository {
			public:
				/**
				 * Graba un escenario en un archivo xml
				 * @param xml    Nombre y ruta del archivo xml en que se quiere persistir el
				 * escenario
				 * @param stage    Escenario que se quiere persistir
				 */
				virtual void saveStage(const std::string& xml, const game::serialization::model::Stage& stage) =0;
				/**
				 * Recupera un escenario a partir de un xml
				 * @param xml    Path del xml
				 * @param stage    Escenario recuperado
				 * @param background    Path de la imagen de fondo
				 * @return true si el escenario pudo cargarse con exito y false en otro caso
				 */
				virtual bool loadStage(const std::string& xml, game::serialization::model::Stage& stage) =0;

				/** @return Un string con la informacion de todos los elementos del elementContainer */
				virtual std::string serialize(const game::design::ElementContainer& elementContainer) =0;
				/**
				 * Llena el elementContainer con los elementos generados a partir del stageStr,
				 * generado previamente por el metodo serialize
				 */
				virtual void unserialize(const std::string& stageStr, game::design::ElementContainer& elementContainer) =0;

				virtual ~StageXmlRepository() {};
			};
		}
	}
}
#endif // EDITOR_PERSISTENCE_STAGEXMLREPOSITORY_H_
