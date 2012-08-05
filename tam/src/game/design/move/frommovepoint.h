#ifndef __GAME__DESIGN__MOVE__FROMMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__FROMMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/fromtoelement.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado en el
			 * origen de un FromToElement
			 */
			class FromMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de FromMovePoint
				 * @param element FromToElement en cuyo
				 * inicio está ubicado el MovePoint
				 */
				FromMovePoint(elements::FromToElement &element);

				/**
				 * @see MovePoint#getPosition
				 */
				virtual core::Vector2d getPosition() const;

				/**
				 * @see MovePoint#move
				 */
				virtual void move(const core::Vector2d &newPosition);
			private:
				elements::FromToElement &element;
			};
		}
	}
}

#endif
