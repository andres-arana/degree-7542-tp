#ifndef __GAME__CORE__AFFECTORS__DAMPINGFORCEAFFECTOR_H_INCLUDED__
#define __GAME__CORE__AFFECTORS__DAMPINGFORCEAFFECTOR_H_INCLUDED__

#include "forceaffector.h"

namespace game {
	namespace core {
		namespace affectors {
			/**
			 * Implementacion de ForceAffector que aplica una fuerza
			 * de arrastre a una particula. Esta fuerza aumenta con la
			 * velocidad de la particula, y es un modelo simple
			 * de la interaccion con medios viscosos.
			 */
			class DampingForceAffector : public ForceAffector {
			public:
				/**
				 * Crea una nueva instancia de DampingForceAffector
				 * @param damping Coeficiente de arrastre.
				 */
				DampingForceAffector(double damping);

				/**
				 * @see ForceAffector#GetAffectingForce
				 */
				virtual Vector2d GetAffectingForce(const Particle& particle);
			private:
				double damping;
			};
		}
	}
}

#endif
