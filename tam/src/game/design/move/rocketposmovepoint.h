#ifndef __GAME__DESIGN__MOVE__ROCKETPOSMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__ROCKETPOSMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/rocket.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado en la base
			 * de un rocket. Mover este punto de movimiento
			 * translada tanto a la base del cohete como a
			 * su objetivo, manteniendo asi la direccion del
			 * cohete
			 */
			class RocketPosMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de RocketPosMovePoint
				 * ubicado en la base de un cohete
				 * @param element Rocket en cuya base esta ubicado
				 * el MovePoint
				 */
				RocketPosMovePoint(elements::Rocket &element);

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
