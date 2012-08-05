#ifndef LOGIC_PROPERTIES_WHEELPROPERTIES_H_
#define LOGIC_PROPERTIES_WHEELPROPERTIES_H_

#include "centerradiuselementproperties.h"

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades de los Wheel en el toolbox
			 */
			class WheelProperties : public CenterRadiusElementProperties {
				private:
					int torqueMagnitude;
					int decayTime;

				public:
					/**
					 * Crea una nueva instancia de WheelProperties
					 */
					WheelProperties();
					/**
					 * Crea una nueva instancia de WheelProperties
					 * @param number Cantidad maxima de elementos de
					 * un tipo disponibles
					 * @param price Precio por unidad
					 * @param minRadius Radio minimo
					 * @param maxRadius Radio maximo
					 * @param torqueMagnitude Torque inicial de la rueda
					 * @param decayTime Tiempo que tarda la rueda en detenerse
					 */
					WheelProperties(int number, int price, int minRadius,
							int maxRadius, int torqueMagnitude, int decayTime);

					/**
					 * Obtiene el torque inicial de la rueda
					 */
					int getTorqueMagnitude() const;
					/**
					 * Establece el torque inicial de la rueda
					 */
					void setTorqueMagnitude(int torqueMagnitude);

					/**
					 * Obtiene el tiempo que tarda la rueda en detenerse
					 */
					int getDecayTime() const;
					/**
					 * Establece el tiempo que tarda la rueda en detenerse
					 */
					void setDecayTime(int decayTime);
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_WHEELPROPERTIES_H_*/
