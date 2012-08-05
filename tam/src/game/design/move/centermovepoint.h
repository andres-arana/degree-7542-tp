#ifndef __GAME__DESIGN__MOVE__CENTERMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__CENTERMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/centerradiuselement.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado en el
			 * centro de un CenterRadiusElement
			 */
			class CenterMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de CenterMovePoint
				 * @param element CenterRadiusElement en cuyo
				 * centro está ubicado el MovePoint
				 */
				CenterMovePoint(elements::CenterRadiusElement &element);

				/**
				 * @see MovePoint#getPosition
				 */
				virtual core::Vector2d getPosition() const;

				/**
				 * @see MovePoint#move
				 */
				virtual void move(const core::Vector2d &newPosition);
			private:
				elements::CenterRadiusElement &element;
			};
		}
	}
}

#endif
