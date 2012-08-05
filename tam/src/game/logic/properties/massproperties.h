#ifndef LOGIC_PROPERTIES_MASSPROPERTIES_H_
#define LOGIC_PROPERTIES_MASSPROPERTIES_H_

#include "centerradiuselementproperties.h"

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades de un Mass en el toolbox
			 */
			class MassProperties : public CenterRadiusElementProperties {
				private:
					int mass;

				public:
					/**
					 * Crea una nueva instancia de MassProperties
					 * @return
					 */
					MassProperties();

					/**
					 * Crea una nueva instancia de MassProperties
					  * @param number Cantidad maxima de elementos de
					 * un tipo disponibles
					 * @param price Precio por unidad
					 * @param minRadius Radio minimo
					 * @param maxRadius Radio maximo
					 * @param mass Masa
					 */
					MassProperties(int number, int price, int minRadius,
							int maxRadius, int mass);

					/**
					 * Devuelve la masa
					 */
					int getMass() const;
					/**
					 * Establece la masa
					 */
					void setMass(int mass);
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_MASSPROPERTIES_H_*/
