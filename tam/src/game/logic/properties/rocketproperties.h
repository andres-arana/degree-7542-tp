#ifndef LOGIC_PROPERTIES_ROCKETPROPERTIES_H_
#define LOGIC_PROPERTIES_ROCKETPROPERTIES_H_

#include "elementproperties.h"

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades de los Rocket en el toolbox
			 */
			class RocketProperties : public ElementProperties {
				private:
					int strength;
					int decayTime;

				public:
					/**
					 * Crea una nueva instancia de RocketProperties
					 */
					RocketProperties();
					/**
					 * Crea una nueva instancia de RocketProperties
					 * @param number Cantidad maxima de elementos de
					 * un tipo disponibles
					 * @param price Precio por unidad
					 * @param strength Fuerza inicial del propulsor
					 * del Rocket
					 * @param decayTime Tiempo que tarda el propulsor
					 * en quedarse sin combustible
					 * @return
					 */
					RocketProperties(
							int number, int price, int strength, int decayTime);

					/**
					 * Obtiene la fuerza inicial del propulsor
					 * del Rocket
					 */
					int getStrength() const;
					/**
					 * Establece la fuerza inicial del propulsor
					 * del Rocket
					 */
					void setStrength(int strength);

					/**
					 * Obtiene el tiempo que tarda el propulsor
					 * en quedarse sin combustible
					 */
					int getDecayTime() const;
					/**
					 * Establece el tiempo que tarda el propulsor
					 * en quedarse sin combustible
					 */
					void setDecayTime(int decayTime);
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_ROCKETPROPERTIES_H_*/
