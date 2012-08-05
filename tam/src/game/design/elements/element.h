#ifndef __GAME__DESIGN__ELEMENTS__ELEMENT_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTS__ELEMENT_H_INCLUDED__

#include "../../core/physicsengine.h"
#include "../../core/particle.h"
#include "../../core/spring.h"
#include "../move/movepoint.h"
#include "../connect/connectionpoint.h"
#include <sigc++-2.0/sigc++/sigc++.h>
#include <vector>

namespace game {
	namespace design {
		namespace elements {
			/**
			 * Clase que representa un elemento con el que se
			 * construye una maquina. Puede configurarse sobre
			 * un engine fisico. Maneja servicios comunes a todos
			 * los elementos, como la administracion de memoria
			 * para las particulas, resortes, puntos de movimiento
			 * y puntos de conexion, la logica de registracion en
			 * un engine fisico y la logica basica de manejo
			 * de señales
			 */
			class Element {
			public:
				/**
				 * Tipo utilizado para manejar una lista de punteros a particulas
				 */
				typedef std::vector<core::Particle *> particle_list;
				/**
				 * Tipo utilizado para manejar una lista de punteros a resortes
				 */
				typedef std::vector<core::Spring *> spring_list;
				/**
				 * Tipo utilizado para manejar una lista de punteros a puntos
				 * de movimiento
				 */
				typedef std::vector<game::design::move::MovePoint *>mpoint_list;
				/**
				 * Tipo utilizado para manejar una lista de punteros a puntos
				 * de conexion
				 */
				typedef std::vector<game::design::connect::ConnectionPoint *>cpoint_list;


				/**
				 * Construye este Widget en el engine. Esto registra
				 * en el engine todas las particulas que componen al
				 * Widget. No pueden realizarse modificaciones sobre
				 * el Widget una vez construido.
				 * @param engine Engine fisico sobre el que se contruye
				 * el Widget
				 */
				void build(core::PhysicsEngine &engine);

				/**
				 * Limpia las particulas y resortes del elemento. Este
				 * metodo debe llamarse siempre antes de reconstruir
				 * al elemento en un engine.
				 */
				void scrap();

				/**
				 * Devuelve una lista con todas las particulas que
				 * componene el widget. Solamente puede llamarse a este
				 * metodo luego de haber construido el widget a traves de
				 * la funcion build
				 * @return Particulas que componen al widget
				 * @see Widget#build
				 */
				const particle_list &getParticles() const;

				/**
				 * Devuelve una lista con todos los resortes que
				 * componen el widget. Solamente puede llamarse
				 * a este metodo luego de haber construido el widget
				 * @return Resortes que componen al widget
				 * @see Widget#build
				 */
				const spring_list &getSprings() const;

				/**
				 * Devuelve una lista con todos los puntos de movimiento
				 * que posee el widget. Un punto de movimiento permite
				 * mover alguna de las posiciones que definen al elemento.
				 * Los puntos de movimiento se agregan a la lista de puntos
				 * de movimiento protegida durante la construccion del elemento,
				 * solamente si el elemento es editable
				 */
				const mpoint_list &getMovePoints() const;

				/**
				 * Devuelve una lista con todos los puntos de conexion que
				 * posee el widget. Un punto de conexion permite conectar
				 * dos widgets entre si, de manera que el movimiento
				 * de cada uno de ellos esté restringido por el otro.
				 * Los puntos de conexion se agregan a la lista de
				 * puntos de coinexion protegida durante la construccion del
				 * elemento
				 */
				const cpoint_list &getConnectionPoints() const;

				/**
				 * Construye una nueva instancia de Element
				 * @param isEditable Indica si el elemento puede
				 * ser movido o eliminado
				 */
				Element(bool isEditable);

				/**
				 * Destruye esta instancia de Widget
				 */
				virtual ~Element();

				/**
				 * Elimina el elemento.
				 */
				virtual void erase();
				/**
				 * Retorna si el elemento ha sido borrado.
				 */
				bool isErased() const;

				/**
				 * Devuelve true si el punto especificado esta contenido
				 * dentro del area que ocupa el elemento
				 */
				virtual bool containsPoint(const core::Vector2d &vector) const = 0;

				/**
				 * Indica si el elemento puede ser movido o eliminado
				 * @return
				 */
				bool isEditable() const;

				typedef sigc::signal<void> modified_signal_type;
				/**
				 * Señal lanzada cuando el elemento es modificado
				 */
				modified_signal_type &modified();

				typedef sigc::signal<void> erased_signal_type;
				/**
				 * Señal lanzada cuando el elemento es eliminado
				 */
				erased_signal_type &erased();

			protected:
				/**
				 * Llena la lista de particulas con las particulas
				 * que componen a este widget.
				 */
				virtual void buildParticlesAndSprings() = 0;

				/**
				 * Lista de particulas
				 */
				particle_list particles;
				/**
				 * Lista de resortes
				 */
				spring_list springs;
				/**
				 * Lista de puntos de movimiento
				 */
				mpoint_list movePoints;
				/**
				 * Lista de puntos de conexion
				 */
				cpoint_list connectionPoints;

				/**
				 * Señal de modificacion
				 */
				modified_signal_type modifiedSignal;
				/**
				 * Señal de eliminacion
				 */
				erased_signal_type erasedSignal;
			private:
				bool hasBeenErased;
				bool editable;
			};

			/**
			 * Clase predicado para la busqueda de elementos
			 * que contengan un punto especifico
			 */
			class ElementContainsPointPredicate {
			public:
				/**
				 * Crea una nueva instancia de ElementContainsPointPredicate
				 * para buscar elementos que contengan un punto especificado
				 * @param point Punto especificado
				 */
				ElementContainsPointPredicate(const core::Vector2d &point);

				/**
				 * Evalua si el elemento especificado contiene al punto
				 * con el que se construyo el predicado
				 */
				bool operator()(const Element *element) const;
			private:
				core::Vector2d point;
			};
		}
	}
}

#endif
