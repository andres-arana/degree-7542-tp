#ifndef LOGIC_PROPERTIES_ELEMENTPROPERTIES_H_
#define LOGIC_PROPERTIES_ELEMENTPROPERTIES_H_

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades comunes a todos los elementos
			 * en el toolbox
			 */
			class ElementProperties {
				private:
					int number;
					int price;
					int available;

				public:
					/**
					 * Crea una nueva instancia de ElementProperties
					 */
					ElementProperties();

					/**
					 * Crea una nueva instancia de ElementProperties
					 * @param number Cantidad maxima de elementos de
					 * un tipo disponibles
					 * @param price Precio por unidad
					 */
					ElementProperties(int number, int price);

					/**
					 * Obtiene la cantidad maxima de elementos de un
					 * tipo disponibles
					 */
					int getNumber() const;
					/**
					 * Establece la cantidad maxima de elementos de un
					 * tipo disponibles
					 */
					void setNumber(int number);

					/**
					 * Obtiene el precio por unidad
					 */
					int getPrice() const;
					/**
					 * Establece el precio por unidad
					 */
					void setPrice(int price);

					/**
					 * Obtiene la cantidad disponible de elementos
					 * de un tipo, dada por la cantidad maxima
					 * menos la cantidad de elementos usados
					 */
					int getAvailableNumber() const;

					/**
					 * Decrementa la cantidad de elementos usados,
					 * aumentando asi la cantidad de elementos
					 * disponibles
					 */
					void incrementAvailableNumber();
					/**
					 * Aumenta la cantidad de elementos usados,
					 * disminuyendo asi la cantidad de elementos
					 * disponibles
					 */
					void decrementAvailableNumber();

					/**
					 * Obtiene el total gastado, calculado como
					 * la cantidad de elementos usados por el
					 * precio por unidad
					 */
					int getTotalSpent();
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_FROMTOELEMENTPROPERTIES_H_*/
