#ifndef __GAME__LOGIC__GAMEENGINE_H_INCLUDED__
#define __GAME__LOGIC__GAMEENGINE_H_INCLUDED__

#include "designtoolbox.h"
#include "../design/elementcontainer.h"
#include "../core/physicsengine.h"
#include "../core/timedelta.h"
#include <vector>

namespace game {
	namespace logic {
		/**
		 * Clase principal del juego. Contiene toda la logica del mismo,
		 * incluyendo el manejo de los elemntos, el cambio entro los
		 * modos de simulacion y diseño, las condiciones de finalizacion
		 * de niveles y el calculo de puntaje
		 */
		class GameEngine : public design::ElementContainer {
		public:
			enum Modes {
				designMode,
				runtimeMode
			};

			/**
			 * Crea una nueva instancia de GameEngine
			 */
			GameEngine();

			/**
			 * Realiza un paso de tiempo en la simulacion
			 * fisica del juego. Solo se puede llamar
			 * estando en modo de ejecucion.
			 */
			void doTimeStep();

			/**
			 * Cambia el modo actual a modo de diseño
			 */
			void swapToDesignMode();
			/**
			 * Cambia el modo actual a modo de ejecucion
			 */
			void swapToRuntimeMode();

			/**
			 * Obtiene el modo actual
			 */
			Modes getCurrentMode() const;

			/**
			 * Devuelve verdadero si se supero
			 * el tiempo maximo para pasar el nivel
			 * y el mismo no ha sido resuelto
			 */
			bool isLevelFailed() const;
			/**
			 * Devuelve verdadero se se resolvio
			 * el nivel
			 */
			bool isLevelCompleted() const;

			/**
			 * Devuelve la cantidad en segundos
			 * de tiempo disponible, calculado como
			 * el tiempo maximo determinado para
			 * resolver el nivel menos el tiempo
			 * transcurrido hasta el momento
			 */
			int getRemainingTime();

			/**
			 * Devuelve el tiempo disponible
			 * como un porcentual del tiempo maximo
			 * determinado para resolver el nivel
			 */
			double getElapsedTimePercentage();

			/**
			 * Calcula el puntaje obtenido
			 * por la resolucion del nivel
			 */
			int calculateScore();

			/**
			 * Obtiene el objeto que encapsula al toolbox
			 */
			logic::DesignToolbox& getDesignToolbox();

			typedef sigc::signal<void> runtime_modified_signal_type;
			/**
			 * Señal elevada cuando se realiza un paso de tiempo
			 * en modo de ejecucion
			 */
			runtime_modified_signal_type &runtimeModified();

			typedef sigc::signal<void> state_modified_signal_type;
			/**
			 * Señal elevada cuando se modifica el estado del GameEngine
			 * sin modificar necesariamente a los elementos contenidos por
			 * el
			 */
			state_modified_signal_type &stateModified();

			typedef sigc::signal<void> end_of_level_signal_type;
			/**
			 * Señal elevada cuando terminal el nivel, ya sea
			 * porque se termino el tiempo disponible o
			 * porque se resolvio el mismo
			 */
			end_of_level_signal_type &endOfLevel();

			/**
			 * Limpia los elementos y las variables
			 * de tiempos transcurridos, dejando el
			 * engine listo para cargar un nuevo
			 * nivel
			 */
			void clearEngine();

			~GameEngine();
		private:
			logic::DesignToolbox toolbox;
			core::PhysicsEngine *physicsEngine;
			bool levelCompleted;
			bool levelFailed;
			core::TimeDelta timeDelta;
			double designTime;
			double simulationTime;

			bool isTimeOver();

			void launchRuntimeModifiedSignal();
			runtime_modified_signal_type runtimeModifiedSignal;

			void launchStateModifiedSignal();
			state_modified_signal_type stateModifiedSignal;

			void launchEndOfLevelSignal(bool completed);
			end_of_level_signal_type endOfLevelSignal;

			void buildPhysicsEngine();
			void scrapPhysicsEngine();
		};
	}
}

#endif
