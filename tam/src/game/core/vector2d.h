#ifndef __GAME__CORE__VECTOR2D_H_INCLUDED__
#define __GAME__CORE__VECTOR2D_H_INCLUDED__

#include <cmath>

namespace game {
	namespace core {

		/**
		 * Clase que representa un vector bidimensional en R^2.
		 */
		class Vector2d {
		public:
			/**
			 * Indica el tipo de dato utilizado para almacenar
			 * el escalar sobre el que existe el vector.
			 */
			typedef double scalar_type;

			/**
			 * Crea una nueva instancia de Vector2d,
			 * como copia del vector nulo.
			 */
			inline Vector2d() : x(0), y(0) {}

			/**
			 * Crea una nueva copia de Vector2d.
			 * @param other Vector que se esta copiando
			 */
			inline Vector2d(const Vector2d& other) : x(other.x), y(other.y) {}

			/**
			 * Crea una nueva instancia de Vector2d.
			 * @param x Coordenada x
			 * @param y Coordenada y
			 */
			inline Vector2d(scalar_type x, scalar_type y) : x(x), y(y) {}

			/**
			 * Obtiene la coordenada x.
			 * @return Coordenada x
			 */
			inline scalar_type getX() const {
				return x;
			}

			/**
			 * Establece la coordenada x.
			 * @param value Nueva coordenada x
			 */
			inline void setX(scalar_type value) {
				x = value;
			}

			/**
			 * Obtiene la coordenada y.
			 * @return Coordenada y
			 */
			inline scalar_type getY() const {
				return y;
			}

			/**
			 * Establece la coordenada y.
			 * @param value Nueva coordenada y
			 */
			inline void setY(scalar_type value) {
				y = value;
			}

			/**
			 * Calcula el cuadrado de la norma del vector.
			 * @return Cuadrado de la norma del vector
			 */
			inline scalar_type squaredNorm() const {
				return Vector2d::innerProduct(*this, *this);
			}

			/**
			 * Calcula la norma del vector.
			 * @return Norma del vector
			 */
			inline scalar_type norm() const {
				return sqrt(squaredNorm());
			}

			/**
			 * Normaliza el vector.
			 */
			inline void normalize()	{
				*this *= 1 / norm();
			}

			/**
			 * Calcula el angulo entre este vector y el vector
			 * especificado
			 * @param other Vector hasta el que se calcula en
			 * angulo
			 * @return Angulo, en radianes, al vector especificado.
			 */
			inline scalar_type angleTo(const Vector2d &other) {
				return atan2(other.y, other.x) - atan2(y, x);
			}

			/**
			 * Calcula la distancia al vector especificado.
			 * @param other Vector hasta el que se calcula la
			 * distancia
			 * @return Distancia al vector especificado.
			 */
			inline scalar_type distanceTo(const Vector2d &other) const {
				return (*this - other).norm();
			}

			/**
			 * Operador de copia.
			 * @param other Vector que se esta copiando.
			 */
			inline void operator=(const Vector2d& other) {
				x = other.x;
				y = other.y;
			}

			/**
			 * Altera este vector para que contenga la suma
			 * de el mismo con otro especificado
			 * @param other Vector a sumar
			 */
			inline void operator+=(const Vector2d& other) {
				x += other.x;
				y += other.y;
			}

			/**
			 * Altera este vector para que contenga la resta
			 * de el mismo con otro especificado
			 * @param other Vector a restar
			 */
			inline void operator-=(const Vector2d& other) {
				x -= other.x;
				y -= other.y;
			}

			/**
			 * Altera este vector para que contenga la multiplicacion
			 * de el mismo con un escalar especificado
			 * @param scalar Escalar multiplicador
			 */
			inline void operator*=(scalar_type scalar) {
				x *= scalar;
				y *= scalar;
			}

			/**
			 * Calcula la suma de este vector con otro especificado
			 * @param other Vector a sumar
			 * @return Suma de este vector con el otro
			 */
			inline Vector2d operator+(const Vector2d& other) const {
				return Vector2d(x + other.x, y + other.y);
			}

			/**
			 * Calcula la resta de este vector con otro especificado
			 * @param other Vector a restar
			 * @return Resta de este vector con el otro
			 */
			inline Vector2d operator-(const Vector2d& other) const {
				return Vector2d(x - other.x, y - other.y);
			}

			/**
			 * Calcula la multiplicacion de este vector con un escalar
			 * especificado
			 * @param scalar Escalar multiplicador
			 * @return Multiplicacion del escalar con este vector
			 */
			inline Vector2d operator*(scalar_type scalar) const {
				return Vector2d(x * scalar, y * scalar);
			}

			inline Vector2d operator-() const {
				return Vector2d(-x, -y);
			}

			/**
			 * Calcula el producto interno entre dos vectores
			 * @param lv Primer vector
			 * @param rv Segundo vector
			 * @return Producto interno entre dos vectores
			 */
			inline static scalar_type innerProduct(const Vector2d& lv, const Vector2d& rv) {
				return lv.x * rv.x + lv.y * rv.y;
			}
		private:
			scalar_type x;
			scalar_type y;
		};

		/**
		 * Calcula la multiplicacion de un vector con un escalar
		 * especificado
		 * @param rv Vector a multiplicar
		 * @param lv Escalar multiplicador
		 * @return Multiplicacion del escalar con este vector
		 */
		inline Vector2d operator*(double lv, const Vector2d& rv) {
			return Vector2d(rv.getX() * lv, rv.getY() * lv);
		}
	}
}

#endif
