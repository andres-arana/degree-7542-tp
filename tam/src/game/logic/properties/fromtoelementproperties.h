#ifndef LOGIC_PROPERTIES_FROMTOELEMENTPROPERTIES_H_
#define LOGIC_PROPERTIES_FROMTOELEMENTPROPERTIES_H_

#include "elementproperties.h"

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades de un FromToElement
			 * en el toolbox
			 */
			class FromToElementProperties : public ElementProperties {
				private:
					int minLength;
					int maxLength;

				public:
					/**
					 * Crea una nueva instancia de FromToElementProperties
					 */
					FromToElementProperties();
					/**
					 * Crea una nueva instancia de FromToElementProperties
					 * @param number Cantidad maxima de elementos de
					 * un tipo disponibles
					 * @param price Precio por unidad
					 * @param minLength Longitud minima
					 * @param maxLength Longitud maxima
					 */
					FromToElementProperties(
							int number, int price, int minLength, int maxLength);

					/**
					 * Obtiene la longitud minima
					 */
					int getMinLength() const;
					/**
					 * Establece la longitud minima
					 */
					void setMinLength(int minLength);

					/**
					 * Obtiene la longitud maxima
					 */
					int getMaxLength() const;
					/**
					 * Establece la longitud maxima
					 */
					void setMaxLength(int maxLength);
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_FROMTOELEMENTPROPERTIES_H_*/
