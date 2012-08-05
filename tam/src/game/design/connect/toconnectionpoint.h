#ifndef __GAME__DESIGN__CONNECT__TOCONNECTIONPOINT_H_INCLUDED__
#define __GAME__DESIGN__CONNECT__TOCONNECTIONPOINT_H_INCLUDED__

#include "connectionpoint.h"
#include "../elements/fromtoelement.h"

namespace game {
	namespace design {
		namespace connect {
			/**
			 * Implementacion de ConnectionPoint ubicado en el
			 * destino de un FromToElement
			 */
			class ToConnectionPoint : public ConnectionPoint {
			public:
				/**
				 * Crea una nueva instancia de ToConnectionPoint
				 * @param element FromToElement en cuyo destino
				 * esta ubicado este ConnectionPoint
				 */
				ToConnectionPoint(elements::FromToElement &element);

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
