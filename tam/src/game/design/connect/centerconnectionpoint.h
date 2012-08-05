#ifndef __GAME__DESIGN__CONNECT__CENTERCONNECTIONPOINT_H_INCLUDED__
#define __GAME__DESIGN__CONNECT__CENTERCONNECTIONPOINT_H_INCLUDED__

#include "connectionpoint.h"
#include "../elements/centerradiuselement.h"

namespace game {
	namespace design {
		namespace connect {
			/**
			 * Implementacion de ConnectionPoint ubicado en el centro de
			 * un CenterRadiusElement
			 */
			class CenterConnectionPoint : public ConnectionPoint {
				public:
					/**
					 * Crea una nueva instancia de CenterConnectionPoint
					 * @param element CenterRadiusElement en cuyo centro se ubica
					 * este connection point
					 */
					CenterConnectionPoint(elements::CenterRadiusElement &element);

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

#endif /*__GAME__DESIGN__CONNECT__CENTERCONNECTIONPOINT_H_INCLUDED__*/
