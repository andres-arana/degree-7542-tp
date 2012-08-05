#ifndef __GAME__LOGIC__DESIGNTOOLBOX_H_INCLUDED__
#define __GAME__LOGIC__DESIGNTOOLBOX_H_INCLUDED__

#include "properties/stageproperties.h"
#include "properties/centerradiuselementproperties.h"
#include "properties/fromtoelementproperties.h"
#include "properties/massproperties.h"
#include "properties/wheelproperties.h"
#include "properties/rocketproperties.h"
#include "../design/elementfactory.h"
#include "../serialization/model/stage.h"
#include <sigc++-2.0/sigc++/sigc++.h>

namespace game {
	namespace logic {
		/**
		 * Representa el cuadro de herramientas del juego. Contiene
		 * las propiedades de todos los elementos. Además es la clase
		 * encargada de crear nuevas instancias de ellos en funcion
		 * de las propiedades cargadas para cada uno
		 */
		class DesignToolbox : public design::ElementFactory {
			public:
				typedef sigc::signal<void> properties_modified_signal_type;
				/**
				 * Señal elevada cuando se modifica cualquier propiedad
				 * de cualquier elemento
				 */
				properties_modified_signal_type &modified();

				/**
				 * Carga las propiedades desde el modelo de persistencia
				 * @param stage Modelo de persistencia
				 */
				void loadPropertiesFromStage(serialization::model::Stage& stage);

				/** @see ElementFactory#createMetalBar */
				virtual design::elements::MetalBar* createMetalBar(
						const core::Vector2d& startPosition);
				/** @see ElementFactory#createMetalPlatform */
				virtual design::elements::MetalPlatform* createMetalPlatform(
						const core::Vector2d& startPosition);
				/** @see ElementFactory#createCanvasTape */
				virtual design::elements::CanvasTape* createCanvasTape(
						const core::Vector2d& startPosition);
				/** @see ElementFactory#createRope */
				virtual design::elements::Rope* createRope(
						const core::Vector2d& startPosition);
				/** @see ElementFactory#createMass */
				virtual design::elements::Mass* createMass();
				/** @see ElementFactory#createWheel */
				virtual design::elements::Wheel* createWheel();
				/** @see ElementFactory#createRocket */
				virtual design::elements::Rocket* createRocket(
						const core::Vector2d& startPosition);
				/** @see ElementFactory#createFixedPoint */
				virtual design::elements::FixedPoint* createFixedPoint();

				/**
				 * Obtiene las propiedades generales del nivel
				 */
				properties::StageProperties* getStageProperties();
				/**
				 * Obtiene las propiedades de los MetalBar
				 */
				properties::FromToElementProperties* getMetalBarProperties();
				/**
				 * Obtiene las propiedades de los MetalPlatform
				 */
				properties::FromToElementProperties* getMetalPlatformProperties();
				/**
				 * Obtiene las propiedades de los CanvasTape
				 */
				properties::FromToElementProperties* getCanvasTapeProperties();
				/**
				 * Obtiene las propiedades de los Rope
				 */
				properties::FromToElementProperties* getRopeProperties();
				/**
				 * Obtiene las propiedades de los Mass
				 */
				properties::MassProperties* getMassProperties();
				/**
				 * Obtiene las propiedades de los Wheel
				 */
				properties::WheelProperties* getWheelProperties();
				/**
				 * Obtiene las propiedades de los Rocket
				 */
				properties::RocketProperties* getRocketProperties();
				/**
				 * Obtiene las propiedades de los FixedPoint
				 */
				properties::CenterRadiusElementProperties* getFixedPointProperties();

				/**
				 * Devuelve el total gastado en todos los elementos creados
				 */
				int calculateTotalSpent();
			private:
				properties::StageProperties stageProperties;
				properties::FromToElementProperties metalBarProperties;
				properties::FromToElementProperties metalPlatformProperties;
				properties::FromToElementProperties canvasTapeProperties;
				properties::FromToElementProperties ropeProperties;
				properties::MassProperties massProperties;
				properties::WheelProperties wheelProperties;
				properties::RocketProperties rocketProperties;
				properties::CenterRadiusElementProperties fixedPointProperties;

				void launchPropertiesModified();
				properties_modified_signal_type propertiesModifiedSignal;

				void incrementAvailableMetalBars();
				void decrementAvailableMetalBars();
				void incrementAvailableMetalPlatforms();
				void decrementAvailableMetalPlatforms();
				void incrementAvailableCanvasTapes();
				void decrementAvailableCanvasTapes();
				void incrementAvailableRopes();
				void decrementAvailableRopes();
				void incrementAvailableMasses();
				void decrementAvailableMasses();
				void incrementAvailableWheels();
				void decrementAvailableWheels();
				void incrementAvailableRockets();
				void decrementAvailableRockets();
				void incrementAvailableFixedPoints();
				void decrementAvailableFixedPoints();
		};
	}
}

#endif
