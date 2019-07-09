/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include <cstdlib>

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private: 

	double *vector3D_;

   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

	//! \name 

	/*! 
		\brief     Constructor con parámetros
		\note      Los parámetros por defecto hacen que el constructor pueda actuar como constructor por defecto
		\param     x, y, z: valores double que son las componentes del vector, todas con valor por defecto 0.0
		\post      Las componentes del nuevo vector deben ser iguales que los parámetros de entrada
		\sa        Vector3D(Vector3D), ~Vector3D()
	*/
	Vector3D(double const x=0.0, double const y=0.0, double const z=0.0){

		vector3D_ = new double[3];

		this->set1(x);
		this->set2(y);
		this->set3(z);

		#ifndef NDEBUG
		assert((std::abs(this->get1() - x) < COTA_ERROR)
		  and  (std::abs(this->get2() - y) < COTA_ERROR)
		  and  (std::abs(this->get3() - z) < COTA_ERROR) );
		#endif
		}

	/*! 
		\brief     Constructor de copia
		\note      Se crea un nuevo vector que es una copia del vector de entrada
		\param     v: objeto de tipo Vector3D, pasado como referencia constante
		\post      Las componentes del nuevo vector son iguales que las del vector de entrada
		\sa        Vector3D, ~Vector3D
	*/
	Vector3D(Vector3D const &v){

		vector3D_ = new double[3];

		this->set1(v.get1());
		this->set2(v.get2());
		this->set3(v.get3());

		#ifndef NDEBUG
		assert((std::abs(this->get1() - v.get1()) < COTA_ERROR)
		  and  (std::abs(this->get2() - v.get2()) < COTA_ERROR)
		  and  (std::abs(this->get3() - v.get3()) < COTA_ERROR)
			);
		#endif
	}
	/*! 
		\brief     Destructor de la clase
		\note      Se libera la memoria asignada a la clase
		\sa        Vector3D(), Vector3D(Vector3D)
	*/
	~Vector3D(){

		delete vector3D_;
		vector3D_=NULL;
		}

	//! \name Observadores: funciones de consulta de Vector3D

	/*! 
		\brief     Método para consultar el primer valor del vector
		\note      Función inline y const
		\return    Valor double que es la primera componente del vector
		\sa        get2, get3, set1, set2, set3
	*/
	inline double get1() const{

		return vector3D_[0];
		}

	/*! 
		\brief     Método para consultar el segundo valor del vector
		\note      Función inline y const
		\return    Valor double que es la segunda componente del vector
		\sa        get1, get3, set1, set2, set3
	*/
	inline double get2() const{

		return vector3D_[1];
		}

	/*! 
		\brief     Método para consultar el tercer valor del vector
		\note      Función inline y const
		\return    Valor double que es la tercera componente del vector
		\sa        get1, get2, set1, set2, set3
	*/
	inline double get3() const{

		return vector3D_[2];
		}

	/*! 
		\brief     Método para calcular el modulo del vector
		\note      Función inline y const
		\return    Valor double que es el módulo del vector
		\post      El valor devuelto es igual al módulo del vector
	*/
	inline double modulo() const{

		double modulo;

		modulo = sqrt( this->get1()*this->get1() + this->get2()*this->get2() + this->get3()*this->get3());

		#ifndef NDEBUG
		assert(std::abs(sqrt(this->get1()*this->get1() + this->get2()*this->get2() + this->get3()*this->get3()) - modulo) < COTA_ERROR);
		#endif

		return modulo;		
		}

	/*! 
		\brief     Método para calcular el angulo que forman dos vectores
		\note      Función inline y const
		\return    Valor double que es el módulo del vector
		\param     v: Objeto de tipo Vector3D pasado como referencia constante
		\pre       El modulo del vector de entrada y el modulo del vector actual son distintos de cero
		\post      El valor devuelto es igual al angulo que forman los dos vectores
		\sa        alfa, beta, gamma
	*/
	inline double angulo(Vector3D const &v) const{

		#ifndef NDEBUG
		assert((this->modulo()*v.modulo()) > 0);
		#endif

		double angulo;

		angulo = acos( this->dotProduct(v) / (this->modulo()*v.modulo()) );

		#ifndef NDEBUG
		assert( std::abs(angulo - acos(this->dotProduct(v) / (this->modulo()*v.modulo()) ) ) < COTA_ERROR );
		#endif

		return angulo;
		}
	/*! 
		\brief     Método para calcular el ángulo que forma el vector actual con el eje X
		\note      Función inline y const
		\return    Valor double que es el angulo entre el vector actual y el eje X
		\pre       El modulo del vector actual es distinto de cero
		\post      El valor devuelto es igual al angulo que forma el vector actual con el eje X
		\sa        angulo, beta, gamma
	*/
	inline double alfa() const{
		
		#ifndef NDEBUG
		assert(this->modulo() > 0);
		#endif

		double alfa;
		Vector3D v(1,0,0);

		alfa = angulo(v);

		#ifndef NDEBUG
		assert(std::abs(alfa - angulo(v)) < COTA_ERROR);
		#endif

		return alfa;
		}

	/*! 
		\brief     Método para calcular el angulo que forma el vector actual con el eje Y
		\note      Función inline y const
		\return    Valor double que es el angulo entre el vector actual y el eje Y
		\pre       El modulo del vector actual es distinto de cero
		\post      El valor devuelto es igual al angulo que forma el vector actual con el eje Y
		\sa        angulo, alfa, gamma
	*/
	inline double beta() const{
		
		#ifndef NDEBUG
		assert(this->modulo() > 0);
		#endif

		double beta;
		Vector3D v(0,1,0);

		beta = angulo(v);

		#ifndef NDEBUG
		assert(std::abs(beta - angulo(v)) < COTA_ERROR);
		#endif

		return beta;
		}

	/*! 
		\brief     Método para calcular el angulo que forma el vector actual con el eje Z
		\note      Función inline y const
		\return    Valor double que es el angulo entre el vector actual y el eje Z
		\pre       El modulo del vector actual es distinto de cero
		\post      El valor devuelto es igual al angulo que forma el vector actual con el eje Z
		\sa        alfa, beta, gamma
	*/
	inline double gamma() const{
		
		#ifndef NDEBUG
		assert(this->modulo() > 0);
		#endif

		double gamma;
		Vector3D v(0,0,1);

		gamma = angulo(v);

		#ifndef NDEBUG
		assert(std::abs(gamma - angulo(v)) < COTA_ERROR );
		#endif

		return gamma;
		}	

	/*! 
		\brief     Método para calcular el producto escalar de dos vectores
		\note      Función inline y const
		\return    Valor double que es el producto escalar de los vectores
		\param     v: Objeto de tipo Vector3D pasado como referencia constante
		\post      El valor devuelto es igual al producto escalar de los dos vectores
		\sa        crossProduct, productoMixto
	*/
	inline double dotProduct(Vector3D const &v) const{

		double valor;

		valor = this->get1()*v.get1() + this->get2()*v.get2() + this->get3()*v.get3();

		#ifndef NDEBUG
		assert(std::abs(valor - (this->get1()*v.get1() + this->get2()*v.get2() + this->get3()*v.get3())) < COTA_ERROR);
		#endif

		return valor;
		}

	/*! 
		\brief     Método para calcular el producto vectorial de dos vectores
		\note      Función inline y const
		\return    Objeto de tipo Vector3D devuelto como referencia
		\param     v: Objeto de tipo Vector3D pasado como referencia constante
		\pre       El ángulo que forman los dos vectores es mayor que 0
		\post      El vector devuelto es perpendicular al vector actual y a v
		\post      El módulo del vector devuelto es igual al producto entre el modulo de v,
			   el modulo del vector actual y el ángulo que forman
		\sa        dotProduct, productoMixto
	*/
	inline Vector3D& crossProduct(Vector3D const &v) const{

		#ifndef NDEBUG
		assert(this->angulo(v) > 0);
		#endif

		Vector3D *vector = new Vector3D;

		vector->set1(this->get2()*v.get3() - this->get3()*v.get2());
		vector->set2(this->get3()*v.get1() - this->get1()*v.get3());
		vector->set3(this->get1()*v.get2() - this->get2()*v.get1());

		#ifndef NDEBUG
		assert((std::abs(this->dotProduct(*vector) - 0.0) < COTA_ERROR)
		  and  (std::abs(v.dotProduct(*vector) - 0.0) < COTA_ERROR));
		assert(std::abs(vector->modulo() - ((this->modulo()* v.modulo()) * std::abs(sin(this->angulo(v))))) < COTA_ERROR);
		#endif

		return *vector;	
		}

	/*! 
		\brief     Método para calcular el producto mixto de dos vectores
		\note      Función inline y const
		\return    Valor double que es el producto mixto de los vectores
		\param     v, w: Objetos de tipo Vector3D pasados como referencias constantes
		\post      El valor devuelto es igual al producto mixto de los dos vectores
		\sa        dotProduct, crossProduct
	*/
	double productoMixto(Vector3D const &v, Vector3D const &w) const{

		double valor;		

		valor = this->dotProduct(w.crossProduct(v));

		#ifndef NDEBUG
		assert(std::abs(valor - this->dotProduct(w.crossProduct(v))) < COTA_ERROR);
		#endif

		return valor;
		}

	//! \name Modificadores: funciones de modificación de Vector3D

	/*! 
		\brief     Método para modificar el primer valor del vector
		\note      Función inline
		\param     V: valor double pasado como const
		\post      La primera componente del vector es igual al parámetro de entrada
		\sa        get1, get2, get3, set2, set3
	*/
	inline void set1(double const v){

		vector3D_[0] = v;

		#ifndef NDEBUG
		assert(std::abs(this->get1() - v) < COTA_ERROR);
		#endif
		}

	/*! 
		\brief     Método para modificar el segundo valor del vector
		\note      Función inline
		\param     V: valor double pasado como const
		\post      La segunda componente del vector es igual al parámetro de entrada
		\sa        get1, get2, get3, set1, set3
	*/
	inline void set2(double const v){

		vector3D_[1] = v;

		#ifndef NDEBUG
		assert(std::abs(this->get2() - v) < COTA_ERROR);
		#endif
		}

	/*! 
		\brief     Método para modificar el tercer valor del vector
		\note      Función inline
		\param     V: valor double pasado como const
		\post      La tercera componente del vector es igual al parámetro de entrada
		\sa        get1, get2, get3, set1, set2
	*/
	inline void set3(double const v){

		vector3D_[2] = v;

		#ifndef NDEBUG
		assert(std::abs(this->get3() - v) < COTA_ERROR);
		#endif
		}

	/*! 
		\brief     Método para sumar una constante al vector
		\note      Función inline
		\param     k: valor double pasado como const
		\post      El nuevo vector es igual al antiguo sumándole k a cada componente
		\sa        sumVect, multConst, multVect
	*/
	inline void sumConst(double const k){

		Vector3D old(this->get1(), this->get2(), this->get3());

		this->set1(this->get1() + k);
		this->set2(this->get2() + k);
		this->set3(this->get3() + k);

		#ifndef NDEBUG
		assert((std::abs(this->get1() - (old.get1() + k)) < COTA_ERROR)
		  and  (std::abs(this->get2() - (old.get2() + k)) < COTA_ERROR)
		  and  (std::abs(this->get3() - (old.get3() + k)) < COTA_ERROR));
		#endif
		}

	/*! 
		\brief     Método para sumar dos vectores
		\note      Función inline
		\param     v: objeto de tipo Vector3D, pasado como referencia constante
		\post      El nuevo vector es igual al antiguo sumándole a cada componente las componentes correspondientes de v
		\sa        sumConst, multConst, multVect
	*/	
	inline void sumVect(Vector3D const &v){

		Vector3D old(this->get1(), this->get2(), this->get3());

		this->set1(this->get1() + v.get1());
		this->set2(this->get2() + v.get2());
		this->set3(this->get3() + v.get3());

		#ifndef NDEBUG
		assert((std::abs(this->get1() - (old.get1() + v.get1())) < COTA_ERROR)
		   and (std::abs(this->get2() - (old.get2() + v.get2())) < COTA_ERROR)
		   and (std::abs(this->get3() - (old.get3() + v.get3())) < COTA_ERROR));
		#endif
		}

	/*! 
		\brief     Método para multiplicar una constante al vector
		\note      Función inline
		\param     k: valor double pasado como const
		\post      El nuevo vector es igual al antiguo multiplicando k a cada componente
		\sa        sumConst, sumVect, multVect
	*/
	inline void multConst(double const k){

		Vector3D old(this->get1(), this->get2(), this->get3());

		this->set1(this->get1() * k);
		this->set2(this->get2() * k);
		this->set3(this->get3() * k);

		#ifndef NDEBUG
		assert((std::abs(this->get1() - old.get1() * k) < COTA_ERROR)
		 and   (std::abs(this->get2() - old.get2() * k) < COTA_ERROR)
		 and   (std::abs(this->get3() - old.get3() * k) < COTA_ERROR));
		#endif
		}

	/*! 
		\brief     Método para multiplicar dos vectores
		\note      Función inline
		\param     v: objeto de tipo Vector3D pasado como referencia constante
		\post      El nuevo vector es igual al antiguo multiplicado por v
		\sa        sumConst, sumVect, multConst
	*/	
	inline void multVect(Vector3D const &v){

		Vector3D old(this->get1(), this->get2(), this->get3());

		this->set1(this->get1() * v.get1());
		this->set2(this->get2() * v.get2());
		this->set3(this->get3() * v.get3());

		#ifndef NDEBUG
		assert((std::abs(this->get1() - old.get1() * v.get1()) < COTA_ERROR)
		  and  (std::abs(this->get2() - old.get2() * v.get2()) < COTA_ERROR)
		  and  (std::abs(this->get3() - old.get3() * v.get3()) < COTA_ERROR));
		#endif
		}

    //! \name Operadores de la clase
   
	/*! 
		\brief     Operador de sobrecarga para =
		\return    objeto de tipo Vector3D devuelto por referencia
		\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
		\post      El el vector devuelto es igual a objeto
	*/
	Vector3D & operator=(Vector3D const &objeto);

	/*! 
		\brief     Operador de sobrecarga para ==
		\note      El operador es const    
		\return    valor de tipo bool
		\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
	*/
	bool operator == (Vector3D const &objeto) const;

	/*! 
		\brief     Operador de sobrecarga para + binario
		\return    objeto de tipo Vector3D devuelto por referencia
		\param     v: objeto de tipo Vector3D pasado como referencia constante
		\post      Las componentes del vector devuelto son iguales a las sumas de las componentes del vector actual y v
	*/
	Vector3D & operator + (Vector3D const &v) const;

	/*! 
		\brief     Operador de sobrecarga para + unario
		\note      El operador es const
		\note      Aquí el operador se sobrecarga sólo para el vector actual
		\return    objeto de tipo Vector3D devuelto por referencia
	*/
	Vector3D & operator + () const;

	/*! 
		\brief     Operador de sobrecarga para - binario
		\note      El operador es const
		\return    Objeto de tipo Vector3D devuelto por referencia
		\param     v: Objeto de tipo Vector3D pasaco como referencia constante
		\post      El vector devuelto es igual a la resta del vector actual y el vector v
	*/
	Vector3D & operator - (Vector3D const &v) const;

	/*! 
		\brief     Operador de sobrecarga para - unario
		\note      El operador es const
		\note      El operador se sobrecarga sólo para el vector actual
		\return    Objeto de tipo Vector3D devuelto por referencia
		\post      El vector devuelto es el opuesto del vector actual
	*/
	Vector3D & operator - () const;

	/*! 
		\brief     Operador de sobrecarga para *
		\note      Operador postfijo para multiplicar las componentes de un vector por una constante
		\return    Objeto de tipo Vector3D devuelto por referencia
		\param     k: valor de tipo double pasado como const
		\post      El vector devuelto es igual al vector actual con sus componentes multiplicadas por k
	*/
	Vector3D & operator * (double const k) const;

	/*! 
		\brief     Operador de sobrecarga para *
		\note      Para hallar el producto escalar de dos vectores
		\return    objeto de tipo Vector3D devuelto por referencia
		\param     v: Objeto de tipo Vector3D pasado como referencia constante
		\post      El el valor devuelto es igual al producto escalar del vector actual y v
	*/
	double operator * (Vector3D const &v) const;

	/*! 
		\brief     Operador de sobrecarga para ^
		\note      Para hallar el producto vectorial de dos vectores
		\return    objeto de tipo Vector3D devuelto por referencia
		\param     v: Objeto de tipo Vector3D pasado como referencia constante
		\post      El vector devuelto es igual al producto vectorial del vector actual y v
	*/
	Vector3D & operator ^ (Vector3D const &v) const;

	//! \name Funciones lectura y escritura de la clase Vector3D

	/*! 
		\brief     Método para leer un vector desde teclado componente a componente
		\note      Se introducen las componentes del vector una por una
	*/
	inline void leerVector3D(){

		double x, y, z;

		std::cout << "Primera componente = ";
		std::cin >> x;
		this->set1(x);

		std::cout << "Segunda componente = ";
		std::cin >> y;
		this->set2(y);

		std::cout << "Tercera componente = ";
		std::cin >> z;
		this->set1(z);
		}

	/*! 
		\brief     Método para mostrar por pantalla las componentes de un vector
		\note      El vector se mostrará por pantalla de la forma (v1, v2, v3)
	*/
	inline void escribirVector3D() const{

		std::cout << "(" << this->get1() << ", " << this->get2() << ", " << this->get3() << ")" << std::endl;
		}

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	/*! 
		\brief     Operador de sobrecarga para *
		\note      Funcion amiga para la clase Vector3D
		\note      Operador para el producto por un escalar prefijo
		\return    objeto de tipo Vector3D devuelto por referencia
		\param     k: valor tipo double
		\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
		\post      El vector devuelto es igual a objeto multiplicadas sus componentes por k
	*/
    Vector3D & operator* (double k, Vector3D const & objeto);


	/*! 
		\brief     Operador de sobrecarga para >>
		\note      Funcion amiga para la clase Vector3D
		\return    flujo de entrada istream
		\param     stream: flujo de entrada tipo istream pasado por referencia
		\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
	*/
    istream &operator>>(istream &stream, Vector3D &objeto);

	/*! 
		\brief     Operador de sobrecarga para <<
		\note      Funcion amiga para la clase Vector3D
		\return    flujo de salida ostream
		\param     stream: flujo de salida tipo ostream pasado por referencia
		\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
	*/
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
