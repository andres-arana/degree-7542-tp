#ifndef __GAME__CORE__AFFECTORS__CONSTANTFORCEEFFECTOR_H_INCLUDED__
#define __GAME__CORE__AFFECTORS__CONSTANTFORCEEFFECTOR_H_INCLUDED__

#include "forceaffector.h"

namespace game {
	namespace core {
		namespace affectors {
			/**
			 * Implementacion de ForceAffector que aplica una fuerza
			 * constante e igual a todas las particulas.
			 */
			class ConstantForceAffector : public ForceAffector {
			public:
				/**
				 * Crea una nueva instancia de ConstantForceAffector
				 * @param force Fuerza a aplicar a todas las particulas
				 */
				ConstantForceAffector(const Vector2d& force);

				/**
				 * @see ForceAffector#GetAffectingForce
				 */
				virtual Vector2d GetAffectingForce(const Particle &particle);
			private:
				Vector2d force;
			};
		}
	}
}

#endif
