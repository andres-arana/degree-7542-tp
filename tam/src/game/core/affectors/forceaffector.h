#ifndef __GAME__CORE__AFFECTORS__FORCEAFFECTOR_H_INCLUDED__
#define __GAME__CORE__AFFECTORS__FORCEAFFECTOR_H_INCLUDED__

#include "../vector2d.h"


namespace game {
	namespace core {
		// Forward declaration para poder declarar objetos Particle
		class Particle;

		namespace affectors {

			/**
			 * Clase que representa una entidad que aplica una fuerza
			 * sobre una particula.
			 */
			class ForceAffector {
			public:
				/**
				 * Obtiene la fuerza que afecta a una particula especifica
				 * @param particle Particula a la que se esta afectando
				 */
				virtual Vector2d GetAffectingForce(const Particle& particle) = 0;

				/**
				 * Destruye esta instancia de ForceAffector
				 */
				virtual ~ForceAffector() {};
			};
		}
	}
}

#endif
