#ifndef __GAME__DESIGN__MOVE__FROMTOMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__FROMTOMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/fromtoelement.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado a mitad
			 * de distancia entre el origen y el final de
			 * un FromToElement
			 */
			class FromToMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de FromToMovePoint
				 * @param element FromToElement en cuya mitad
				 * entre origen y final está ubicado el MovePoint
				 */
				FromToMovePoint(elements::FromToElement &element);

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
