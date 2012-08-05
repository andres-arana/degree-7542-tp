#ifndef __GAME__DESIGN__ELEMENTS__BALL_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__BALL_H_INCLUDED__

#include "centerradiuselement.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa la pelota del juego
			 */
			class Ball : public CenterRadiusElement {
			public:
				/**
				 * Crea una nueva instancia de Ball
				 * @param isEditable Indica si el elemento puede ser
				 * movido y / o borrado
				 * @param mass Indica la masa de la pelota
				 * @param minRadius Indica el radio minimo que puede
				 * tener la pelota si es editable
				 * @param maxRadius Indica el radio maximo que puede
				 * tener la pelota si es editable
				 */
				Ball(bool isEditable, double mass = 5, double minRadius = 15, double maxRadius = 15);

				/**
				 * Devuelve la masa con la que se construyo la pelota
				 */
				double getMass() const;

				/**
				 * Devuelve la posicion de la pelota actualizada
				 * momento a momento por el integrador fisico
				 */
				const core::Vector2d &getDynamicPosition() const;
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();
			private:
				double mass;
			};
		}
	}
}

#endif
