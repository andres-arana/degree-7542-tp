#ifndef __GAME__DESIGN__ELEMENTS__EXITAREA_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__EXITAREA_H_INCLUDED__

#include "ball.h"
#include "centerradiuselement.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa un area de salida
			 */
			class ExitArea : public CenterRadiusElement {
			public:
				/**
				 * Crea una nueva instancia de ExitArea
				 * @param isEditable Indica si el elemento
				 * puede ser borrado o movido
				 */
				ExitArea(bool isEditable);

				/**
				 * Indica si el area de salida contiene
				 * totalmente a una pelota especificada
				 * @param ball Pelota a checkear
				 */
				bool containsBall(const Ball &ball);
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();
			};
		}
	}
}

#endif
