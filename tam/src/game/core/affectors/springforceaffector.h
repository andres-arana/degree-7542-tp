#ifndef __GAME__CORE__AFFECTORS__SPRINGFORCEAFFECTOR_H_INCLUDED__
#define __GAME__CORE__AFFECTORS__SPRINGFORCEAFFECTOR_H_INCLUDED__

#include "forceaffector.h"

namespace game {
	namespace core {
		namespace affectors {
			/**
			 * Implementacion de ForceAffector que aplica una fuerza
			 * elastica de un resorte
			 */
			class SpringForceAffector : public ForceAffector {
			public:
				/**
				 * Crea una nueva instancia de SpringForceAffector
				 * @param force Fuerza a aplicar a todas las particulas
				 */
				SpringForceAffector(Particle &springEnd, double k, double relaxedDistance);

				/**
				 * @see ForceAffector#GetAffectingForce
				 */
				virtual Vector2d GetAffectingForce(const Particle& particle);
			private:
				Particle &springEnd;
				double k;
				double relaxedDistance;
			};
		}
	}
}

#endif
