#ifndef __GAME__DESIGN__CONNECT_CONNECTIONPOINT_H_INCLUDED__
#define __GAME__DESIGN__CONNECT_CONNECTIONPOINT_H_INCLUDED__

#include "../../core/vector2d.h"
#include "../../core/particle.h"
#include <vector>

namespace game {
	namespace design {
		namespace elements {
			class Element;
			class Connection;
		}

		namespace connect {
			/**
			 * Clase base abstracta de todos los puntos de conexión
			 * de los elementos. Contiene la lógica base de conexión,
			 * como es el manejo de las conexiones aceptadas, el manejo
			 * de las partículas de conexión utilizadas por los elementos
			 * y la logica de deteccion de interacciones
			 */
			class ConnectionPoint {
			public:
				/**
				 * Define el tipo utilizado para almacenar una lista
				 * de punteros a particulas
				 */
				typedef std::vector<core::Particle *> particle_list;

				/**
				 * Crea una nueva instancia de ConnectionPoint
				 */
				ConnectionPoint();

				/**
				 * Obtiene la posicion en donde esta ubicado el punto
				 * de conexion
				 */
				virtual core::Vector2d getPosition() const = 0;

				/**
				 * Obtiene el radio del area ocupada por el punto
				 * de conexion
				 */
				double getRadius() const;

				/**
				 * Devuelve true si el punto especificado
				 * esta contenido dentro del area ocuapada
				 * por el punto de conexion
				 * @param point Punto a testear
				 */
				bool containsPoint(const core::Vector2d &point) const;

				/**
				 * Obtiene el elemento al que pertenece este
				 * punto de conexion
				 */
				virtual elements::Element &getParentElement() = 0;

				/**
				 * Añade una conexion al punto de conexion
				 * @param connection Conexion a añadir
				 */
				void addConnection(elements::Connection *connection);

				/**
				 * Devuelve true si alguna de las conexiones
				 * añadidas al punto de conexion continua viva
				 */
				bool isConnected() const;

				/**
				 * Devuelve una lista con todas las particulas de
				 * conexion de las conexiones asociadas a este
				 * punto de conexion.
				 * @return
				 */
				particle_list getConnectionParticles();

				virtual ~ConnectionPoint() {};

			private:
				std::vector<elements::Connection *> connections;
			};

			/**
			 * Clase predicado para busqueda de puntos de conexion
			 * que contengan un punto dado
			 */
			class ConnectionPointContainsPointPredicate {
			public:
				/**
				 * Crea una nueva instancia de ConnectionPointContainsPointPredicate
				 * para buscar puntos de conexion que contengan un punto especificado
				 * @param point Punto especificado
				 */
				ConnectionPointContainsPointPredicate(const core::Vector2d &point);

				/**
				 * Evaluda si el punto de conexion dado contiene al punto
				 * espacial especificado al construir esta instancia.
				 * @param point Punto de conexion a evaluar
				 */
				bool operator()(const ConnectionPoint *point) const;
			private:
				core::Vector2d point;
			};
		}
	}
}

#endif
