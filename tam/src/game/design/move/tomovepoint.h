#ifndef __GAME__DESIGN__MOVE__TOMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__TOMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/fromtoelement.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado en el final
			 * de un FromToElement
			 */
			class ToMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de ToMovePoint
				 * ubicado en el final de un FromToElement
				 * @param element FromToElement en cuyo final
				 * esta ubicado el MovePoint
				 * @return
				 */
				ToMovePoint(elements::FromToElement &element);

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
