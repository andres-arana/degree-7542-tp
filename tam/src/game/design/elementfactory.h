#ifndef __GAME__DESIGN__ELEMENTFACTORY_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTFACTORY_H_INCLUDED__

#include "elements/metalbar.h"
#include "elements/metalplatform.h"
#include "elements/canvastape.h"
#include "elements/mass.h"
#include "elements/rope.h"
#include "elements/wheel.h"
#include "elements/obstacle.h"
#include "elements/rocket.h"
#include "elements/fixedpoint.h"
#include "elements/ball.h"
#include "elements/exitarea.h"

namespace game {
	namespace design {
		/**
		 * Factory de elementos. Contiene metodos para la creación
		 * de todos los elementos. Además contiene una implementación
		 * default de todos los métodos de construcción que devuelve
		 * cero, lo que indica que ese elemento no está disponible
		 * en esta fabrica
		 */
		class ElementFactory {
		public:
			/** Construye un Ball */
			virtual elements::Ball *createBall() {return NULL;}
			/** Construye un ExitArea */
			virtual elements::ExitArea *createExitArea() {return NULL;}
			/** Construye un MetalBar */
			virtual elements::MetalBar *createMetalBar(const core::Vector2d& startPosition) {return NULL;}
			/** Construye un MetalPlatform */
			virtual elements::MetalPlatform *createMetalPlatform(const core::Vector2d& startPosition) {return NULL;}
			/** Construye un CanvasTape */
			virtual elements::CanvasTape *createCanvasTape(const core::Vector2d& startPosition) {return NULL;}
			/** Construye un Rope */
			virtual elements::Rope *createRope(const core::Vector2d& startPosition) {return NULL;}
			/** Construye un Mass */
			virtual elements::Mass *createMass() {return NULL;}
			/** Construye un Wheel */
			virtual elements::Wheel *createWheel() {return NULL;}
			/** Construye un Rocket */
			virtual elements::Rocket *createRocket(const core::Vector2d& startPosition) {return NULL;}
			/** Construye un FixedPoint */
			virtual elements::FixedPoint *createFixedPoint() {return NULL;}
			/** Construye un Obstacle */
			virtual elements::Obstacle *createObstacle(const core::Vector2d &startPosition) {return NULL;}

			virtual ~ElementFactory() {};
		};
	}
}

#endif
