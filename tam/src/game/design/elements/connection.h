#ifndef __GAME__DESIGN__ELEMENTS__CONNECTION_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__CONNECTION_H_INCLUDED__

#include "element.h"
#include "../../core/vector2d.h"
#include "../connect/connectionpoint.h"

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Elemento que representa una conexion entre
			 * dos ConnectionPoint
			 */
			class Connection : public Element {
			public:
				/**
				 * Crea una nueva instancia de Connection. Registra
				 * la instancia creada en los dos ConnectionPoint
				 * especificados
				 * @param first Primer ConnectionPoint conectado
				 * @param second Segundo ConnectionPoint conectado
				 * @return
				 */
				Connection(connect::ConnectionPoint &first, connect::ConnectionPoint &second);

				/**
				 * @see Element#containsPoint
				 */
				virtual bool containsPoint(const core::Vector2d &point) const;

				/**
				 * Obtiene la posicion desde la cual
				 * se inicia la conexion, definida como
				 * la posicion del primer ConnectionPoint
				 * conectado
				 */
				core::Vector2d getStartPosition() const;
				/**
				 * Obtiene la posicion hasta la cual
				 * llega la conexion, definida como
				 * la posicion del segundo ConnectionPoint
				 * conectado
				 */
				core::Vector2d getEndPosition() const;

				/**
				 * Obtiene el ancho de la banda de conexion
				 */
				double getConnectionWidth() const;

				/**
				 * Obtiene la particula compartida entre
				 * los elementos conectados, conocida como
				 * la particula de conexion
				 */
				core::Particle *getConnectionParticle();
			protected:
				/**
				 * @see Element#buildParticlesAndSprings
				 */
				virtual void buildParticlesAndSprings();
			private:
				connect::ConnectionPoint &first;
				connect::ConnectionPoint &second;

				void validateConnection();
			};


		}
	}
}

#endif
