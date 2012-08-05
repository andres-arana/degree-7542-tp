#ifndef __GAME__CORE__PHYSICSENGINE_H_INCLUDED__
#define __GAME__CORE__PHYSICSENGINE_H_INCLUDED__

#include "particle.h"
#include "affectors/forceaffector.h"
#include "timedelta.h"
#include <vector>

namespace game {
	namespace core {
		/**
		 * Clase que maneja un conjunto de particulas, alterando sus posiciones y
		 * velocidades de acuerdo a las aceleraciones de las mismas. Las particulas
		 * registradas en el engine seran modificadas de acuerdo a estos parametros.
		 * Ademas posee funcionalidad para agregar afectores globales a todas las
		 * particulas registradas.
		 * @see Particle
		 * @see affectors::ForceAffector
		 */
		class PhysicsEngine {
		public:
			/**
			 * Crea una nueva instancia de PhysicsEngine
			 */
			PhysicsEngine();

			/**
			 * Registra una particula para ser manejada por el engine
			 * @param particle Particula a registrar
			 */
			void registerParticle(Particle *particle);

			/**
			 * Registra un afector a aplicar sobre todas las particulas
			 * manejadas.
			 * @param affector Afector a registrar
			 */
			void addSystemWideAffector(affectors::ForceAffector *affector);

			/**
			 * Actualiza las posiciones y velocidades de todas las particulas
			 * manejadas en funcion de sus aceleraciones
			 */
			void doTimeStep();

			~PhysicsEngine();
		private:
			std::vector<Particle *> dynamicParticles;
			std::vector<Particle *> collisionableParticles;
			std::vector<Particle *> noncollisionableParticles;
			std::vector<Particle *> fixedParticles;

			std::vector<affectors::ForceAffector *> affectors;

			TimeDelta timeDelta;
			double remainderStep;
		};
	}
}

#endif
