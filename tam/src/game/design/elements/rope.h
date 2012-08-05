#ifndef __GAME__DESIGN__ELEMENTS__ROPE_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__ROPE_H_INCLUDED__

#include "stringelement.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa una cuerda
			 */
			class Rope : public StringElement {
			public:
				/**
				 * Crea una nueva instancia de Rope
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minLength Indica la longitud minima que puede
				 * tener el elemento si es editable
				 * @param maxLength Indica la longitud maxima que puede
				 * tener el elemento si es editable
				 * @param startPosition Establece la posicion de inicio
				 * del elemento
				 */
				Rope(bool isEditable, double minLength, double maxLength, const core::Vector2d &startPosition);
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
