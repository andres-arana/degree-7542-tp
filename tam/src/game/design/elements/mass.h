#ifndef __GAME__DESIGN__ELEMENTS__MASS_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__MASS_H_INCLUDED__

#include "centerradiuselement.h"
#include "../connect/connectionpoint.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa una masa de peso
			 * concentrado
			 */
			class Mass : public CenterRadiusElement {
			public:
				/**
				 * Crea una nueva instancia de Mass
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minRadius Indica el radio minimo que puede
				 * tener el elemento si es editable
				 * @param maxRadius Indica el radio maximo que puede
				 * tener el elemento si es editable
				 * @param mass Masa del elemento
				 */
				Mass(bool isEditable, double minRadius, double maxRadius, double mass);

				/**
				 * Obtiene la masa del elemento
				 */
				double getMass() const;

			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();

				/**
				 * Obtiene el punto de conexion ubicado
				 * en el centro del elemento
				 */
				connect::ConnectionPoint &getCenterConnectionPoint();
			private:
				double mass;
			};
		}
	}
}

#endif
