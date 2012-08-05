#ifndef __GAME__CORE__AFFECTORS__DECAYINGFORCEEFFECTOR_H_INCLUDED__
#define __GAME__CORE__AFFECTORS__DECAYINGFORCEEFFECTOR_H_INCLUDED__

#include "forceaffector.h"
#include "../timedelta.h"

namespace game {
	namespace core {
		namespace affectors {

			/**
			 * Implementacion de ForceAffector que aplica una fuerza
			 * que disminuye linealmente con el tiempo hasta llegar a cero
			 */
			class DecayingForceAffector : public ForceAffector {
			public:
				DecayingForceAffector(double initialForceMagnitude, double decayTime, const Particle &axisDestination);

				/**
				 * @see ForceAffector#GetAffectingForce
				 */
				virtual Vector2d GetAffectingForce(const Particle &particle);
			private:
				TimeDelta timeDelta;
				const Particle &axisDestination;
				double initialForceMagnitude;
				double decayTime;
				bool active;
			};
		}
	}
}

#endif
