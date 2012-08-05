#ifndef __GAME__DESIGN__CONNECT__RADIUSCONNECTIONPOINT_H_INCLUDED__
#define __GAME__DESIGN__CONNECT__RADIUSCONNECTIONPOINT_H_INCLUDED__

#include "connectionpoint.h"
#include "../elements/centerradiuselement.h"

namespace game {
	namespace design {
		namespace connect {
			/**
			 * Implementacion de ConnectionPoint ubicado en la
			 * posicion de radio de un RadiusElement
			 */
			class RadiusConnectionPoint : public ConnectionPoint {
			public:
				/**
				 * Crea una nueva instancia de RadiusConnectionPoint
				 * @param element CenterRadiusElement en cuya posicion
				 * de radio esta ubicado este ConnectionPoint
				 */
				RadiusConnectionPoint(elements::CenterRadiusElement &element);

				/**
				 * @see ConnectionPoint#getPosition
				 */
				virtual core::Vector2d getPosition() const;

				/**
				 * @see ConnectionPoint#getParentElement
				 */
				virtual elements::Element &getParentElement();
			private:
				elements::CenterRadiusElement &element;
			};
		}
	}
}

#endif
