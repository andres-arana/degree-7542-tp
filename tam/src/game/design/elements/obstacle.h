#ifndef __GAME__DESIGN__ELEMENTS__OBSTACLE_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__OBSTACLE_H_INCLUDED__

#include "rectangularelement.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa un obstaculo
			 */
			class Obstacle : public RectangularElement {
			public:
				/**
				 * Crea una nueva instancia de Obstacle
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minLength Indica la longitud minima que puede
				 * tener el elemento si es editable
				 * @param maxLength Indica la longitud maxima que puede
				 * tener el elemento si es editable
				 * @param startPosition Establece la posicion de inicio
				 * del elemento
				 */
				Obstacle(bool isEditable, const core::Vector2d &startPosition, double minLength = 100, double maxLength = 600);
			protected:
				/**
				 * @see RectangularElement#createParticle
				 */
				virtual core::Particle *createParticle(double mass, double radius, const core::Vector2d &position) const;
			};
		}
	}
}

#endif
