#ifndef __GAME__DESIGN__MOVE__RADIUSMOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__RADIUSMOVEPOINT_H_INCLUDED__

#include "movepoint.h"
#include "../elements/centerradiuselement.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Implementacion de MovePoint ubicado en el radio
			 * de un CenterRadiusElement
			 */
			class RadiusMovePoint : public MovePoint {
			public:
				/**
				 * Crea una nueva instancia de RadiusMovePoint
				 * @param element CenterRadiusElement en cuyo radio
				 * esta ubicado el MovePoint
				 * @return
				 */
				RadiusMovePoint(elements::CenterRadiusElement &element);

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
