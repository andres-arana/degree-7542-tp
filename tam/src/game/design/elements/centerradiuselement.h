#ifndef __GAME__DESIGN__ELEMENTS__CENTERRADIUSELEMENT_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__CENTERRADIUSELEMENT_H_INCLUDED__

#include "element.h"
#include "../../core/vector2d.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento abstracto que puede ser definido por una posicion
			 * central y un radio dado por una posicion radial.
			 */
			class CenterRadiusElement : public Element {
			public:
				/**
				 * Crea una nueva instancia de CenterRadiusElement
				 * @param isEditable Indica si el elemento puede ser
				 * movido y / o borrado
				 * @param minRadius Indica el radio minimo que puede
				 * tener el elemento si es editable
				 * @param maxRadius Indica el radio maximo que puede
				 * tener el elemento si es editable
				 */
				CenterRadiusElement(bool isEditable, double minRadius, double maxRadius);

				/**
				 * Establece el radio del elemento. Modifica ademas
				 * la posicion radial para mantener el radio establecido
				 */
				void setRadius(double value);
				/**
				 * Devuelve el radio del elemento, definido como
				 * la distancia entre el centro y la posicion
				 * radial
				 */
				double getRadius() const;

				/**
				 * Obtiene el radio minimo del elemento
				 */
				double getMinRadius() const;
				/**
				 * Obtiene el radio maximo del elemento
				 */
				double getMaxRadius() const;

				/**
				 * Obtiene la posicion radial
				 */
				const core::Vector2d getRadiusPosition() const;
				/**
				 * Establece la posicion radial
				 */
				void setRadiusPosition(const core::Vector2d &value);

				/**
				 * Obtiene la posicion central
				 */
				const core::Vector2d getPosition() const;
				/**
				 * Establece la posicion central. Modifica
				 * implicitamente la posicion radial, para
				 * mantener el radio constante.
				 */
				void setPosition(const core::Vector2d &value);

				/**
				 * @see Element#containsPoint
				 */
				virtual bool containsPoint(const core::Vector2d& point) const;
			private:
				double minRadius;
				double maxRadius;
				core::Vector2d radiusPosition;
				core::Vector2d position;

				double getValidRadius(double potentialRadius);
			};
		}
	}
}

#endif
