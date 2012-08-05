#ifndef __GAME__DESIGN__CONNECT__FROMCONNECTIONPOINT_H_INCLUDED__
#define __GAME__DESIGN__CONNECT__FROMCONNECTIONPOINT_H_INCLUDED__

#include "connectionpoint.h"
#include "../elements/fromtoelement.h"

namespace game {
	namespace design {
		namespace connect {
			/**
			 * Implementacion de ConnectionPoint ubicado en el origen
			 * de un FromToElement
			 */
			class FromConnectionPoint : public ConnectionPoint {
			public:
				/**
				 * Crea una nueva instancia de FromConnectionPoint
				 * @param element FromToElement en cuyo origen se
				 * situa este FromConnectionPoint
				 */
				FromConnectionPoint(elements::FromToElement &element);

				/**
				 * @see ConnectionPoint#getPosition
				 */
				virtual core::Vector2d getPosition() const;

				/**
				 * @see ConnectionPoint#getParentElement
				 */
				virtual elements::Element &getParentElement();
			private:
				elements::FromToElement &element;
			};
		}
	}
}

#endif
