#ifndef __GAME__DESIGN__CONNECT__ROCKETCONNECTIONPOINT_H_INCLUDED__
#define __GAME__DESIGN__CONNECT__ROCKETCONNECTIONPOINT_H_INCLUDED__

#include "connectionpoint.h"
#include "../elements/rocket.h"

namespace game {
	namespace design {
		namespace connect {
			/**
			 * Implementacion de ConnectionPoint ubicado en la base
			 * de un Rocket
			 */
			class RocketPosConnectionPoint : public ConnectionPoint {
				public:
					/**
					 * Crea una nueva instancia de RocketPosConnectionPoint
					 * @param rocket Rocket en cuya base está ubicado
					 * este ConnectionPoint
					 */
					RocketPosConnectionPoint(elements::Rocket& rocket);

					/**
					 * @see ConnectionPoint#getPosition
					 */
					virtual core::Vector2d getPosition() const;

					/**
					 * @see ConnectionPoint#getParentElement
					 */
					virtual elements::Element& getParentElement();
				private:
					elements::Rocket& rocket;
			};
		}
	}
}

#endif /*__GAME__DESIGN__CONNECT__ROCKETCONNECTIONPOINT_H_INCLUDED__*/
