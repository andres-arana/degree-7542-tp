#ifndef __GAME__CORE__PARTICLE_H_INCLUDED__
#define __GAME__CORE__PARTICLE_H_INCLUDED__

#include "vector2d.h"
#include "affectors/forceaffector.h"
#include <vector>

namespace game {
	namespace core {
		/**
		 * Clase que representa una masa circular fisica. Contiene informacion de varias
		 * propiedades fisicas de la particula:
		 * <ul>
		 * 		<li>Masa: Magnitud que indica que tan inercial es la particula</li>
		 * 		<li>Radio: Radio de la circunferencia en la que existe la particula</li>
		 *		<li>Coef. de restitucion: Indica como interactua la particula en colisiones.
		 * Sus valores validos van desde 0 a 0.5. Valores mas pequeños hacen tender mas
		 * inelasticas las colisiones</li>
		 * 		<li>Posicion: Vector que indica el lugar fisico que ocupa el centro de la
		 * circunferencia en la que existe la particula</li>
		 *		<li>Velocidad: Derivada de la posicion en funcion del tiempo</li>
		 *		<li>Aceleracion: Derivada de la velocidad en funcion del tiempo</li>
		 * </ul>
		 * Una particula puede ademas ser o no fija. De esta forma, su posicion y velocidad
		 * no pueden ser afectadas. Tambien puede ser o no colisionable. Una particula
		 * colisionable interactua en choques con otras particulas colisionables.
		 * Para controlar la aceleracion que afecta a la particula, es necesario registrar
		 * afectores. @see affectors::ForceAffector
		 */
		class Particle {
		public:
			/**
			 * Crea una nueva instancia de Particle.
			 * @param mass Masa de la nueva particula
			 * @param radius Radio de la nueva particula
			 * @param position Posiciin de la nueva particula
			 * @param collisionElasticRatio Coef. de restitucion.
			 */
			Particle(double mass, double radius, const Vector2d &position = Vector2d(), double collisionElasticRatio = 0.0);

			/**
			 * Obtiene la masa de la particula.
			 * @return Masa de la particula
			 */
			double getMass() const;

			/**
			 * Obtiene el radio de la particula
			 * @return Radio de la particula
			 */
			double getRadius() const;

			/**
			 * Obtiene la posicion de la particula
			 * @return Posicion de la particula
			 */
			const Vector2d &getPosition() const;

			/**
			 * Obtiene una referencia a la posicion de la particula
			 * permitiendo la actualización de la misma sin realizar
			 * copias
			 * @return
			 */
			Vector2d &getUpdateablePosition();

			/**
			 * Establece la posicion de la particula
			 * @param value Nueva posicion a establecer
			 */
			void setPosition(const Vector2d &value);

			/**
			 * Obtiene la velocidad de la particula
			 * @return Velocidad de la particula
			 */
			const Vector2d& getSpeed() const;

			/**
			 * Obtiene una referencia a la velocidad de
			 * la particula, permitiendo actualizar la
			 * misma sin realizar copias.
			 * @return
			 */
			Vector2d &getUpdateableSpeed();

			/**
			 * Establece la velocidad de la particula
			 * @param value Nueva velocidad de la particula
			 */
			void setSpeed(const Vector2d &value);


			/**
			 * Obtiene la aceleracion de la particula
			 * @return Aceleracion de la particula
			 */
			Vector2d getAcceleration() const;

			/**
			 * Obtiene si la particula es o no fija
			 * @return true si la particula es fija, false en caso contrario
			 */
			bool isFixed() const;

			/**
			 * Establece si la particula es o no fija
			 * @param value true si la particula pasa a ser fija, false en caso
			 * de pasar a ser no fija
			 */
			void setFixed(bool value);

			/**
			 * Obtiene si la particula es o no colisionable
			 * @return true si la particula es colisionable, false en caso contrario
			 */
			bool isCollisionable() const;

			/**
			 * Establece si la particula es o no colisionable.
			 * @param value true si la particula pasa a ser colisionable, false
			 * en case de pasar a ser no colisionable
			 */
			void setCollisionable(bool value);

			/**
			 * Obtiene el coeficiente de restitucion
			 * @return Coeficiente de restitucion
			 */
			double getCollisionElasticRatio() const;

			/**
			 * Establece el coeficiente de restitucion
			 * @param value Nuevo coeficiente de restitucion
			 */
			void setCollisionElasticRatio(double value);

			/**
			 * Registra un afector para que este aplique una fuerza sobre
			 * la misma, variando entonces la aceleracion de la particula.
			 * @param affector Afector a registrar.
			 * @see affectors::ForceAffector
			 */
			void registerAffector(affectors::ForceAffector *affector);

			/**
			 * Desregistra un afector registrado, eliminando la fuerza que
			 * este estaba aplicando sobre la misma. Si el afector no estaba
			 * previamente registrado, nada ocurre.
			 * @param affector Afector a desregistrar
			 * @see affectors::ForceAffector
			 */
			void unregisterAffector(affectors::ForceAffector *affector);

			/**
			 * Chequea si una particula se superpone con otra.
			 * @param other Particula contra la cual se desea
			 * chequear la colisiin
			 * @return true si las particulas estan colisionando, false en
			 * caso contrario
			 */
			bool collidesWith(const Particle& other);
		private:
			double mass;
			double radius;
			double collisionElasticRatio;
			Vector2d position;
			Vector2d speed;
			bool fixed;
			bool collisionable;

			typedef std::vector<affectors::ForceAffector *> affectors_list;
			affectors_list affectors;
		};
	}
}

#endif
