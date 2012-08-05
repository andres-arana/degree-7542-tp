#ifndef __GAME__COREAFFECTORS__GRAVITYFORCEAFFECTOR_H_INCLUDED__
#define __GAME__COREAFFECTORS__GRAVITYFORCEAFFECTOR_H_INCLUDED__

#include "forceaffector.h"

namespace game {
	namespace core {
		namespace affectors {
			/**
			 * Implementacion de ForceAffector que aplica una aceleracion
			 * constante e igual a todas las particulas.
			 */
			class GravityForceAffector : public ForceAffector {
			public:
				/**
				 * Crea una nueva instancia de GravityForceAffector
				 * @param force Aceleracion a aplicar a todas las particulas
				 */
				GravityForceAffector(const Vector2d& gravity);

				/**
				 * @see ForceAffector#GetAffectingForce
				 */
				virtual Vector2d GetAffectingForce(const Particle& particle);
			private:
				Vector2d gravity;
			};
		}
	}
}

#endif
