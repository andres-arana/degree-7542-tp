#ifndef LOGIC_PROPERTIES_STAGEPROPERTIES_H_
#define LOGIC_PROPERTIES_STAGEPROPERTIES_H_

namespace game {
	namespace logic {
		namespace properties {
			/**
			 * Representa las propiedades genericas
			 * de un nivel
			 */
			class StageProperties {
				private:
					int A;
					int B;
					int C;
					int D;
					int timeToSolve;
					int gravity;

				public:
					/**
					 * Crea una nueva instancia de StageProperties
					 */
					StageProperties();
					/**
					 * Crea una nueva instancia de StageProperties
					 * @param A Parametro A de la formula de puntaje
					 * @param B Parametro B de la formula de puntaje
					 * @param C Parametro C de la formula de puntaje
					 * @param D Parametro D de la formula de puntaje
					 * @param timeToSolve Tiempo disponible para
					 * resolver el nivel
					 */
					StageProperties(int A, int B, int C, int D, int timeToSolve);

					/**
					 * Obtiene el parametro A de la formula de puntaje
					 */
					int getA() const;
					/**
					 * Establece el parametro A de la formula de puntaje
					 */
					void setA(int A);

					/**
					 * Obtiene el parametro B de la formula de puntaje
					 */
					int getB() const;
					/**
					 * Establece el parametro B de la formula de puntaje
					 */
					void setB(int B);

					/**
					 * Obtiene el parametro C de la formula de puntaje
					 */
					int getC() const;
					/**
					 * Establece el parametro C de la formula de puntaje
					 */
					void setC(int C);

					/**
					 * Obtiene el parametro D de la formula de puntaje
					 */
					int getD() const;
					/**
					 * Establece el parametro D de la formula de puntaje
					 */
					void setD(int D);

					/**
					 * Obtiene el tiempo disponible para resolver el nivel
					 */
					int getTimeToSolve() const;
					/**
					 * Establece el tiempo disponible para resolver el nivel
					 */
					void setTimeToSolve(int timeToSolve);

					/**
					 * Obtiene la gravedad
					 */
					int getGravity() const;
					/**
					 * Establece la gravedad
					 */
					void setGravity(int gravity);
			};
		}
	}
}
#endif /*LOGIC_PROPERTIES_STAGEPROPERTIES_H_*/
