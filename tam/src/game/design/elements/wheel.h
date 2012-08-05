#ifndef __GAME__DESIGN__ELEMENTS__WHEEL_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__WHEEL_H_INCLUDED__

#include "centerradiuselement.h"
#include "../../core/affectors/torqueforceaffector.h"
#include "../connect/connectionpoint.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que represnta una rueda
			 */
			class Wheel : public CenterRadiusElement {
			public:
				/**
				 * Crea una nueva instancia de Wheel
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minRadius Indica el radio minimo que puede
				 * tener el elemento si es editable
				 * @param maxRadius Indica el radio maximo que puede
				 * tener el elemento si es editable
				 * @param torqueMagnitude Torque inicial que aplica
				 * el motor a la rueda
				 * @param decayTime Tiempo que tarda el motor en
				 * quedarse sin combustible
				 */
				Wheel(bool isEditable, double minRadius, double maxRadius, double torqueMagnitude, double decayTime);

				/**
				 * Obtiene el torque inicial que aplica el motor
				 * a la rueda
				 */
				double getTorqueMagnitude() const;

				/**
				 * Obtiene el tiempo que tarda el motor en
				 * quedarse sin combustible
				 */
				double getDecayTime() const;

				~Wheel();
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();

				/**
				 * Obtiene el ConnectionPoint ubicado en el
				 * radio de la rueda
				 */
				connect::ConnectionPoint  &getRadiusConnectionPoint();
				/**
				 * Obtiene el ConnectionPoint ubicado en el
				 * centro de la rueda
				 */
				connect::ConnectionPoint  &getCenterConnectionPoint();
			private:
				double torqueMagnitude;
				double decayTime;
				core::affectors::TorqueForceAffector *affector;
			};
		}
	}
}

#endif
