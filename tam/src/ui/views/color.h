#ifndef __UI__VIEWS__DESIGN__COLOR_H_INCLUDED__
#define __UI__VIEWS__DESIGN__COLOR_H_INCLUDED__

namespace ui {
	namespace views {
		/**
		 * Representa un color
		 */
		class Color {
			private:
				double red;
				double green;
				double blue;
				double alpha;

			public:
				/**
				 * Construye un color tomando las componentes rojas,
				 * verdes, azules y de transparencia
				 * @param red Componente rojo
				 * @param green Componente verde
				 * @param blue Componente azul
				 * @param alpha Componente de transparencia
				 */
				Color(double red, double green, double blue, double alpha = 1.0);

				/**
				 * Obtiene el componente rojo
				 */
				double getRed() const;
				/**
				 * Obtiene el componente verde
				 */
				double getGreen() const;
				/**
				 * Obtiene el componente azul
				 */
				double getBlue() const;
				/**
				 * Obtiene el componente de transparencia
				 */
				double getAlpha() const;

				/** Color por defect verde oscuro transparente */
				static const Color ALPHA_DARK_GREEN;
				/** Color por defect azul transparente */
				static const Color ALPHA_BLUE;
				/** Color por defect verde transparente */
				static const Color ALPHA_GREEN;
				/** Color por defect gris claro transparente */
				static const Color ALPHA_GREY;
				/** Color por defect azul claro transparente */
				static const Color ALPHA_LIGHT_BLUE;
				/** Color por defect rojo transparente */
				static const Color ALPHA_RED;
				/** Color por defect blanco transparente */
				static const Color ALPHA_WHITE;
				/** Color por defect dorado */
				static const Color GOLD;
				/** Color por defect gris */
				static const Color GREY;
				/** Color por defect naranja */
				static const Color ORANGE;
				/** Color por defect rojo */
				static const Color RED;
				/** Color por defect blanco */
				static const Color WHITE;
		};
	}
}

#endif /*__UI__VIEWS__DESIGN__COLOR_H_INCLUDED__*/
