#ifndef __GAME__CORE__SPRING_H_INCLUDED__
#define __GAME__CORE__SPRING_H_INCLUDED__

#include "particle.h"
#include "affectors/springforceaffector.h"

namespace game {
	namespace core {
		/**
		 * Clase que representa un resorte que vincula dos particulas.
		 * Registra los afectores correspondientes sobre ambas particulas.
		 * @see Particle
		 * @see affectors::ForceAffector
		 * @see affectors::SpringForceAffector
		 */
		class Spring {
		public:
			/**
			 * Crea una nueva instancia de Spring
			 * @param first Primer particula vinculada
			 * @param second Segunda particula vinculada
			 * @param k Coeficiente de elasticidad
			 */
			Spring(Particle &first, Particle &second, double k);

			/**
			 * Obtiene la primer particula vinculada
			 * @return Primer particula vinculada
			 */
			const Particle& getFirst() const;

			/**
			 * Obtiene la segunda particula vinculada
			 * @return Segunda particula vinculada
			 */
			const Particle& getSecond() const;

		private:
			Particle &first;
			affectors::SpringForceAffector firstAffector;
			Particle &second;
			affectors::SpringForceAffector secondAffector;
			double k;
			double relaxedDistance;
		};
	}
}

#endif
