#ifndef __GAME__DESIGN__ELEMENTS__STRINGELEMENT_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__STRINGELEMENT_H_INCLUDED__

#include "fromtoelement.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento abstracto base de todas las cuerdas
			 */
			class StringElement : public FromToElement {
			public:
				/**
				 * Crea una nueva instancia de StringElement
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minLength Indica la longitud minima que puede
				 * tener el elemento si es editable
				 * @param maxLength Indica la longitud maxima que puede
				 * tener el elemento si es editable
				 * @param startPosition Establece la posicion de inicio
				 * del elemento
				 */
				StringElement(bool isEditable, double minLength, double maxLength, const core::Vector2d &startPosition);

				/**
				 * Obtiene el ancho de la cuerda
				 */
				double getStringWidth() const;

				/**
				 * @see Element#containsPoint
				 */
				virtual bool containsPoint(const core::Vector2d &point) const;
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();

				/**
				 * Factory method implementado por las clases derivadas
				 * para crear una particula tipica del elemento
				 * @param mass Masa de la particula a crear
				 * @param radius Radio de la particula a crear
				 * @param position Posicoin de la particula a crear
				 */
				virtual core::Particle *createParticle(double mass, double radius, const core::Vector2d &position) const = 0;
			};
		}
	}
}

#endif
