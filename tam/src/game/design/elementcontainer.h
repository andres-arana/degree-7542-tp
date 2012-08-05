#ifndef __GAME__DESIGN__ELEMENTCONTAINER_H_INCLUDED__
#define __GAME__DESIGN__ELEMENTCONTAINER_H_INCLUDED__

#include "elements/ball.h"
#include "elements/canvastape.h"
#include "elements/connection.h"
#include "elements/connection.h"
#include "elements/exitarea.h"
#include "elements/fixedpoint.h"
#include "elements/mass.h"
#include "elements/metalbar.h"
#include "elements/metalplatform.h"
#include "elements/obstacle.h"
#include "elements/rocket.h"
#include "elements/rope.h"
#include "elements/wheel.h"

namespace game {
	namespace design {
		/**
		 * Contenedor especializado de elementos
		 */
		class ElementContainer {
		public:
			/** Tipo utilizado para colecciones de punteros a CanvasTape */
			typedef std::vector<elements::CanvasTape*> CanvasTapeCollection;
			/** Tipo utilizado para colecciones de punteros a Connection */
			typedef std::vector<elements::Connection*> ConnectionCollection;
			/** Tipo utilizado para colecciones de punteros a ExitArea */
			typedef std::vector<elements::ExitArea*> ExitAreaCollection;
			/** Tipo utilizado para colecciones de punteros a FixedPoint */
			typedef std::vector<elements::FixedPoint*> FixedPointCollection;
			/** Tipo utilizado para colecciones de punteros a Mass */
			typedef std::vector<elements::Mass*> MassCollection;
			/** Tipo utilizado para colecciones de punteros a MetalBar */
			typedef std::vector<elements::MetalBar*> MetalBarCollection;
			/** Tipo utilizado para colecciones de punteros a MetalPlatform */
			typedef std::vector<elements::MetalPlatform*> MetalPlatformCollection;
			/** Tipo utilizado para colecciones de punteros a Obstacle */
			typedef std::vector<elements::Obstacle*> ObstacleCollection;
			/** Tipo utilizado para colecciones de punteros a Rope */
			typedef std::vector<elements::Rope*> RopeCollection;
			/** Tipo utilizado para colecciones de punteros a Rocket */
			typedef std::vector<elements::Rocket*> RocketCollection;
			/** Tipo utilizado para colecciones de punteros a Wheel */
			typedef std::vector<elements::Wheel*> WheelCollection;
			/** Tipo utilizado para colecciones de punteros a Element */
			typedef std::vector<elements::Element*> ElementCollection;

			/** Tipo utilizado como iterador para colecciones de punteros a CanvasTape */
			typedef CanvasTapeCollection::const_iterator CanvasTapeIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Connection */
			typedef ConnectionCollection::const_iterator ConnectionIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a ExitArea */
			typedef ExitAreaCollection::const_iterator ExitAreaIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a FixedPoint */
			typedef FixedPointCollection::const_iterator FixedPointIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Mass */
			typedef MassCollection::const_iterator MassIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a MetalBar */
			typedef MetalBarCollection::const_iterator MetalBarIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a MetalPlatform */
			typedef MetalPlatformCollection::const_iterator MetalPlatformIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Obstacle */
			typedef ObstacleCollection::const_iterator ObstacleIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Rope */
			typedef RopeCollection::const_iterator RopeIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Rocket */
			typedef RocketCollection::const_iterator RocketIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Wheel */
			typedef WheelCollection::const_iterator WheelIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Element */
			typedef ElementCollection::iterator ElementIterator;
			/** Tipo utilizado como iterador para colecciones de punteros a Element constantes*/
			typedef ElementCollection::const_iterator ElementConstIterator;

			/**
			 * Crea una nueva instancia de ElementContainer
			 */
			ElementContainer();

			/**
			 * Establece la unica pelota
			 * @param ball Pelota a establecer
			 */
			virtual void setBall(elements::Ball *ball);
			/**
			 * Añade un CanvasTape
			 * @param canvasTape Elemento a añadir
			 */
			virtual void addCanvasTape(elements::CanvasTape *canvasTape);
			/**
			 * Añade un Connection
			 * @param connection Elemento a añadir
			 */
			virtual void addConnection(elements::Connection *connection);
			/**
			 * Añade un ExitArea
			 * @param exitArea Elemento a añadir
			 */
			virtual void addExitArea(elements::ExitArea *exitArea);
			/**
			 * Añade un FixedPoint
			 * @param fixedPoint Elemento a añadir
			 */
			virtual void addFixedPoint(elements::FixedPoint *fixedPoint);
			/**
			 * Añade un Mass
			 * @param mass Elemento a añadir
			 */
			virtual void addMass(elements::Mass *mass);
			/**
			 * Añade un MetalBar
			 * @param bar Elemento a añadir
			 */
			virtual void addMetalBar(elements::MetalBar *bar);
			/**
			 * Añade un MetalPlatform
			 * @param platform Elemento a añadir
			 */
			virtual void addMetalPlatform(elements::MetalPlatform *platform);
			/**
			 * Añade un Obstacle
			 * @param obstacle Elemento a añadir
			 */
			virtual void addObstacle(elements::Obstacle *obstacle);
			/**
			 * Añade un Rocket
			 * @param rocket Elemento a añadir
			 */
			virtual void addRocket(elements::Rocket *rocket);
			/**
			 * Añade un Rope
			 * @param rope Elemento a añadir
			 */
			virtual void addRope(elements::Rope *rope);
			/**
			 * Añade un Wheel
			 * @param wheel Elemento a añadir
			 */
			virtual void addWheel(elements::Wheel *wheel);

			/**
			 * Obtiene la unica pelota
			 */
			virtual const elements::Ball* getBall() const;
			/**
			 * Obtiene la coleccion de CanvasTape agregados
			 */
			virtual const CanvasTapeCollection& getCanvasTapeCollection() const;
			/**
			 * Obtiene la coleccion de Connection agregados
			 */
			virtual const ConnectionCollection& getConnectionCollection() const;
			/**
			 * Obtiene la coleccion de ExitArea agregados
			 */
			virtual const ExitAreaCollection& getExitAreaCollection() const;
			/**
			 * Obtiene la coleccion de FixedPoint agregados
			 */
			virtual const FixedPointCollection& getFixedPointCollection() const;
			/**
			 * Obtiene la coleccion de Mass agregados
			 */
			virtual const MassCollection& getMassCollection() const;
			/**
			 * Obtiene la coleccion de MetalBar agregados
			 */
			virtual const MetalBarCollection& getMetalBarCollection() const;
			/**
			 * Obtiene la coleccion de MetalPlatform agregados
			 */
			virtual const MetalPlatformCollection& getMetalPlatformCollection() const;
			/**
			 * Obtiene la coleccion de Obstacle agregados
			 */
			virtual const ObstacleCollection& getObstacleCollection() const;
			/**
			 * Obtiene la coleccion de Rocket agregados
			 */
			virtual const RocketCollection& getRocketCollection() const;
			/**
			 * Obtiene la coleccion de Rope agregados
			 */
			virtual const RopeCollection& getRopeCollection() const;
			/**
			 * Obtiene la coleccion de Wheel agregados
			 */
			virtual const WheelCollection& getWheelCollection() const;
			/**
			 * Obtiene la coleccion de todos los Element agregados
			 */
			virtual const ElementCollection& getElementConstCollection() const;
			/**
			 * Obtiene la coleccion de todos los Element agregados
			 */
			virtual ElementCollection& getElementCollection();

			/**
			 * Obtiene el primer elemento cuya area contenga al
			 * punto especificado, o cero si ningún elemento
			 * lo contiene
			 * @param position Punto especificado
			 */
			virtual elements::Element *getElementAt(const core::Vector2d &position);
			/**
			 * Obtiene el primer MovePoint cuya area contenga al
			 * punto especificado, o cero si ningún elemento
			 * lo contiene
			 * @param point Punto especificado
			 */
			virtual move::MovePoint *getMovePointAt(const core::Vector2d &point);
			/**
			 * Obtiene el primer ConnectionPoint cuya area contenga al
			 * punto especificado, o cero si ningún elemento
			 * lo contiene
			 * @param position Punto especificado
			 */
			virtual connect::ConnectionPoint *getConnectionPointAt(const core::Vector2d &point);

			/**
			 * Elimina todos los elementos contenidos
			 * y limpia las colecciones asociadas
			 */
			void clearElements();

			typedef sigc::signal<void> design_modified_signal_type;
			/**
			 * Señal elevada cuando se modifica el ElementContainer
			 * o cualquiera de los elementos agregados en el
			 */
			design_modified_signal_type &designModified();

			virtual ~ElementContainer();
		private:
			std::vector<elements::Element*> elementCollection;
			elements::Ball* ball;
			CanvasTapeCollection canvasTapeCollection;
			ConnectionCollection connectionCollection;
			ExitAreaCollection exitAreaCollection;
			FixedPointCollection fixedPointCollection;
			MassCollection massCollection;
			MetalBarCollection metalBarCollection;
			MetalPlatformCollection metalPlatformCollection;
			ObstacleCollection obstacleCollection;
			RopeCollection ropeCollection;
			RocketCollection rocketCollection;
			WheelCollection wheelCollection;

			design_modified_signal_type designModifiedSignal;
			void launchDesignModifiedSignal();

			void addGenericElement(elements::Element* element);
		};
	}
}

#endif
