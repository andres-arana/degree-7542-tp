#ifndef __GAME__DESIGN__ELEMENTS__FIXEDPOINT_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__FIXEDPOINT_H_INCLUDED__

#include "centerradiuselement.h"
#include "../connect/connectionpoint.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa un punto fijo
			 */
			class FixedPoint : public CenterRadiusElement {
			public:
				/**
				 * Crea una nueva instancia de FixedPoint
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minRadius Indica el radio minimo que puede
				 * tener el elemento si es editable
				 * @param maxRadius Indica el radio maximo que puede
				 * tener el elemento si es editable
				 */
				FixedPoint(bool isEditable, double minRadius = 15, double maxRadius = 15);
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();

				/**
				 * Devuelve el puntode conexion situado en el
				 * centro del elemento
				 */
				connect::ConnectionPoint &getCenterConnectionPoint();
			};
		}
	}
}

#endif
