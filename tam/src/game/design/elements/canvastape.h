#ifndef __GAME__DESIGN__ELEMENTS__CANVASTAPE_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__CANVASTAPE_H_INCLUDED__

#include "stringelement.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa una cinta de lona
			 */
			class CanvasTape : public StringElement {
			public:
				/**
				 * Crea una nueva instancia de CanvasTape
				 * @param isEditable Indica si el elemento puede ser
				 * movido y / o borrado
				 * @param minLength Indica la longitud minima que puede
				 * tener la cinta de lona si es editable
				 * @param maxLength Indica la longitud maxima que puede
				 * tener la cinta de lona si es editable
				 * @param startPosition Establece la posicion de inicio
				 * de la cinta de lona
				 */
				CanvasTape(bool isEditable, double minLength, double maxLength, const core::Vector2d &startPosition);
			protected:
				/**
				 * @see StringElement#createParticle
				 */
				virtual core::Particle *createParticle(double mass, double radius, const core::Vector2d &position) const;
			};
		}
	}
}

#endif
