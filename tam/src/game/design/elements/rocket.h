#ifndef __GAME__DESIGN__ELEMENTS__ROCKET_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__ROCKET_H_INCLUDED__

#include "element.h"
#include "../../core/vector2d.h"
#include "../../core/affectors/decayingforceaffector.h"
#include "../connect/connectionpoint.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa un cohete
			 */
			class Rocket : public Element {
			public:
				/**
				 * Crea una nueva instancia de Rocket
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param strength Fuerza inicial que aplica
				 * el propulsor del cohete
				 * @param decayTime Tiempo que tarda el propulsor
				 * en quedarse sin combustible
				 * @param startPosition Establece la posicion de inicio
				 * del elemento
				 */
				Rocket(bool isEditable, double strength, double decayTime, const core::Vector2d &startPosition);

				/**
				 * Establece la posicion de la base del cohete
				 */
				void setPosition(const core::Vector2d &value);
				/**
				 * Devuelve la posicion de la base del cohete
				 */
				const core::Vector2d &getPosition() const;

				/**
				 * Establece la ubicacion hacia la que viaja
				 * el cohete
				 */
				void setTarget(const core::Vector2d &value);
				/**
				 * Obtiene la posicion hacia donde viaja el
				 * cohete
				 */
				const core::Vector2d &getTarget() const;

				/**
				 * Devuelve el radio de la base
				 */
				double getBodyRadius() const;

				/**
				 * Devuelve la fuerza que ejerce el
				 * propulsor del cohete
				 */
				double getStrength() const;

				/**
				 * Obtiene el tiempo que tarda
				 * el propulsor en quedarse
				 * sin combustible
				 */
				double getDecayTime() const;

				/**
				 * @see Element#containsPoint
				 */
				virtual bool containsPoint(const core::Vector2d &vector) const;

				~Rocket();
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();

				/**
				 * Obtiene el connection point ubicado en la
				 * base del cohete
				 */
				connect::ConnectionPoint &getBaseConnectionPoint();
			private:
				double strength;
				double decayTime;
				core::Vector2d position;
				core::Vector2d target;
				core::affectors::DecayingForceAffector *affector;

				core::Vector2d getValidTarget(const core::Vector2d &potentialTarget);
			};
		}
	}
}

#endif
