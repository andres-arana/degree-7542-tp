#ifndef __GAME__CORE__AFFECTORS__TORQUEFORCEEFFECTOR_H_INCLUDED__
#define __GAME__CORE__AFFECTORS__TORQUEFORCEEFFECTOR_H_INCLUDED__

#include "forceaffector.h"
#include "../particle.h"
#include "../timedelta.h"

namespace game {
	namespace core {
		namespace affectors {
			/**
			 * Implementación de ForceAffector que aplica un torque a una
			 * partícula con respecto a una partícula que hace de centro. El torque ejercido
			 * disminuye linealmente con el tiempo hasta llegar a cero.
			 */
			class TorqueForceAffector : public ForceAffector {
			public:
				/**
				 * Crea una nueva instancia de TorqueForceAffector
				 * @param initialTorqueMagnitude Torque inicial aplicado
				 * @param decayTime Tiempo que tarda en anularse el torque
				 * @param centerParticle Partícula que hace de centro
				 * @return
				 */
				TorqueForceAffector(double initialTorqueMagnitude, double decayTime, const Particle &centerParticle);

				/**
				 * @see ForceAffector#GetAffectingForce
				 */
				virtual Vector2d GetAffectingForce(const Particle &particle);
			private:
				TimeDelta timeDelta;
				const Particle &centerParticle;
				double initialTorqueMagnitude;
				double decayTime;
				bool active;

			};
		}
	}
}

#endif /*__GAME__CORE__AFFECTORS__TORQUEFORCEEFFECTOR_H_INCLUDED__*/
