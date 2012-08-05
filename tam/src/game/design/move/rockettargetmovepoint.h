#ifndef __GAME__DESIGN__MOVE__ROCKETTARGETMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__ROCKETTARGETMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/rocket.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado en el
			 * objetivo de un cohete
			 */
			class RocketTargetMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de RocketTargetMovePoint
				 * ubicado en el objetivo del cohete
				 * @param element Rocket en cuyo objetivo
				 * esta ubicado el MovePoint
				 */
				RocketTargetMovePoint(elements::Rocket &element);

				/**
				 * @see MovePoint#getPosition
				 */
				virtual core::Vector2d getPosition() const;

				/**
				 * @see MovePoint#move
				 */
				virtual void move(const core::Vector2d &newPosition);
			private:
				elements::Rocket &element;
			};
		}
	}
}

#endif
