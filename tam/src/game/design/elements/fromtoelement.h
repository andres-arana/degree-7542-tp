#ifndef __GAME__DESIGN__ELEMENTS__FROMTOELEMENT_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__FROMTOELEMENT_H_INCLUDED__

#include "element.h"
#include "../connect/connectionpoint.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento abstracto que puede ser definido
			 * por una posicion inicial y otra final
			 */
			class FromToElement : public Element {
			public:
				/**
				 * Crea una nueva instancia de FromToElement
				 * @param isEditable Indica si el elemento puede
				 * ser movido o borrado
				 * @param minLength Indica la longitud minima que puede
				 * tener el elemento si es editable
				 * @param maxLength Indica la longitud maxima que puede
				 * tener el elemento si es editable
				 * @param startPosition Establece la posicion de inicio
				 * del elemento
				 */
				FromToElement(bool isEditable, double minLength, double maxLength, const core::Vector2d &startPosition);

				/**
				 * Obtiene la longitud minima
				 */
				double getMinimumLength() const;
				/**
				 * Obtiene la longitud maxima
				 */
				double getMaximumLength() const;

				/**
				 * Establece la posicion inicial del elemento.
				 * Chequea que la misma mantenga el largo
				 * del elemento dentro de los parametros
				 * minimo y maximo establecido. De no ser
				 * asi, la posicion inicial se desplazara de
				 * manera de mantener el largo dentro de los
				 * parametros establecidos
				 */
				void setStartPosition(const core::Vector2d &position);
				/**
				 * Establece la posicion inicial del elemento,
				 * sin chequear que la misma mantenga el largo
				 * del elemento.
				 */
				void setUncheckedStartPosition(const core::Vector2d &position);
				/**
				 * Devuelve la posicion inicial del elemento
				 */
				const core::Vector2d &getStartPosition() const;

				/**
				 * Establece la posicion final del elemento.
				 * Chequea que la misma mantenga el largo
				 * del elemento dentro de los parametros
				 * minimo y maximo establecido. De no ser
				 * asi, la posicion final se desplazara de
				 * manera de mantener el largo dentro de los
				 * parametros establecidos
				 */
				void setEndPosition(const core::Vector2d &position);
				/**
				 * Establece la posicion final del elemento,
				 * sin chequear que la misma mantenga el largo
				 * del elemento
				 */
				void setUncheckedEndPosition(const core::Vector2d &position);
				/**
				 * Devuelve la posicion final del elemento
				 */
				const core::Vector2d &getEndPosition() const;

			protected:
				/**
				 * Obtiene el punto de conexion ubicado
				 * sobre la posicion inicial del elemento
				 */
				connect::ConnectionPoint &getFromConnectionPoint();
				/**
				 * Obtiene el punto de conexion ubicado
				 * sobre la posicion final del elemento
				 */
				connect::ConnectionPoint &getToConnectionPoint();
			private:
				double minLength;
				double maxLength;
				core::Vector2d startPosition;
				core::Vector2d endPosition;
				core::Vector2d getValidPosition(const core::Vector2d &startPos, const core::Vector2d &potentialPos);
			};
		}
	}
}

#endif
