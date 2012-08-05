#ifndef __GAME__DESIGN__MOVE__MOVEPOINT_H_INCLUDED__
#define __GAME__DESIGN__MOVE__MOVEPOINT_H_INCLUDED__

#include "../../core/vector2d.h"

namespace game {
	namespace design {
		namespace move {
			/**
			 * Clase abstracta base de todos los puntos de movimiento.
			 * Contiene la logica base de movimiento, como el manejo de
			 * deteccion de movimiento.
			 */
			class MovePoint {
			public:
				/**
				 * Obtiene la posicion donde esta ubicado el
				 * punto de movimiento
				 */
				virtual core::Vector2d getPosition() const = 0;

				/**
				 * Obtiene el radio del area ocupada por el
				 * punto de movimiento
				 */
				double getRadius() const;

				/**
				 * Devuelve true si el punto especificado esta
				 * contenida por el area donde esta ubicado el
				 * punto de movimiento
				 * @param point Punto especificado
				 * @return
				 */
				bool containsPoint(const core::Vector2d &point) const;

				/**
				 * Mueve la posicion asociada a este punto de
				 * movimiento a una nueva posicion
				 * @param newPosition Nueva posicion
				 */
				virtual void move(const core::Vector2d &newPosition) = 0;

				virtual ~MovePoint() {};
			};

			/**
			 * Clase predicado para buscar puntos de movimiento
			 * que contengan a un punto especificado
			 */
			class MovePointContainsPointPredicate {
			public:
				/**
				 * Crea una nueva instancia de MovePointContainsPointPredicate
				 * para buscar puntos de movimiento que contengan al punto
				 * especificado
				 * @param point Punto especificado
				 */
				MovePointContainsPointPredicate(const core::Vector2d &point);

				/**
				 * Evalua si el punto de movimiento especificado contiene
				 * al punto con el que se creo el predicado
				 * @param point Punto de movimiento a evaluar
				 */
				bool operator()(const MovePoint *point) const;
			private:
				core::Vector2d point;
			};
		}
	}
}

#endif
