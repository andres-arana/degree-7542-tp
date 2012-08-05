#ifndef LOGIC_PROPERTIES_CENTERRADIUSELEMENTPROPERTIES_H_
#define LOGIC_PROPERTIES_CENTERRADIUSELEMENTPROPERTIES_H_

#include "elementproperties.h"

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades de un CenterRadiusElement
			 * en el toolbox
			 */
			class CenterRadiusElementProperties : public ElementProperties {
				private:
					int minRadius;
					int maxRadius;

				public:
					/**
					 * Crea una nueva instancia de CenterRadiusElementProperties
					 */
					CenterRadiusElementProperties();
					/**
					 * Crea una nueva instancia de CenterRadiusElementProperties
					 * @param number Cantidad maxima de elementos de
					 * un tipo disponibles
					 * @param price Precio por unidad
					 * @param minRadius Radio minimo
					 * @param maxRadius Radio maximo
					 */
					CenterRadiusElementProperties(
							int number, int price, int minRadius, int maxRadius);

					/**
					 * Obtiene el radio minimo
					 */
					int getMinRadius() const;
					/**
					 * Establece el radio minimo
					 */
					void setMinRadius(int minRadius);

					/**
					 * Obtiene el radio maximo
					 */
					int getMaxRadius() const;
					/**
					 * Establece el radio maximo
					 */
					void setMaxRadius(int maxRadius);
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_CENTERRADIUSELEMENTPROPERTIES_H_*/
