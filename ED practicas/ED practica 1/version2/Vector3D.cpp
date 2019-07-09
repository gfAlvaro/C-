/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// Para usar atof y abs
#include <cstdlib>

#include "Vector3D.hpp"


// OPERADORES

ed::Vector3D & ed::Vector3D::operator=(Vector3D const &objeto){

	ed::Vector3D *vector = new Vector3D();

	vector->set1(objeto.get1());
	vector->set2(objeto.get2());
	vector->set3(objeto.get3());

	#ifndef NDEBUG
	assert(((std::abs(vector->get1() - objeto.get1())) < COTA_ERROR)
	  and  ((std::abs(vector->get2() - objeto.get2())) < COTA_ERROR)
	  and  ((std::abs(vector->get3() - objeto.get3())) < COTA_ERROR));
	#endif

	return *vector;
	}

bool ed::Vector3D::operator == (ed::Vector3D const &objeto) const{

	bool igual;

	if( ((std::abs(this->get1() - objeto.get1())) < COTA_ERROR)
	and ((std::abs(this->get2() - objeto.get2())) < COTA_ERROR)
	and ((std::abs(this->get3() - objeto.get3())) < COTA_ERROR))
		igual = true;
	else
		igual = false;

	return igual;
	}

ed::Vector3D & ed::Vector3D::operator + (ed::Vector3D const &v) const{

	ed::Vector3D *vector = new Vector3D();

	vector->set1(this->get1() + v.get1());
	vector->set2(this->get2() + v.get2());
	vector->set3(this->get3() + v.get3());

	#ifndef NDEBUG
	assert((std::abs(vector->get1() - (get1() + v.get1())) < COTA_ERROR) 
	  and  (std::abs(vector->get2() - (get2() + v.get2())) < COTA_ERROR)
	  and  (std::abs(vector->get3() - (get3() + v.get3())) < COTA_ERROR));
	#endif

	return *vector;
	}

ed::Vector3D & ed::Vector3D::operator + () const{

	ed::Vector3D *vector = new Vector3D();

	vector->set1(this->get1());
	vector->set2(this->get2());
	vector->set3(this->get3());

	return *vector;
	}

ed::Vector3D & ed::Vector3D::operator - (ed::Vector3D const &v) const{

	ed::Vector3D *vector = new Vector3D();

	vector->set1(this->get1() - v.get1());
	vector->set2(this->get2() - v.get2());
	vector->set3(this->get3() - v.get3());

	#ifndef NDEBUG
	assert((std::abs(vector->get1() - (this->get1() - v.get1())) < COTA_ERROR)
	  and  (std::abs(vector->get2() - (this->get2() - v.get2())) < COTA_ERROR)
	  and  (std::abs(vector->get3() - (this->get3() - v.get3())) < COTA_ERROR));
	#endif

	return *vector;
	}

ed::Vector3D & ed::Vector3D::operator - () const{

	ed::Vector3D old(this->get1(), this->get2(), this->get3());
	ed::Vector3D *vector = new Vector3D();

	vector->set1(-(this->get1()));
	vector->set2(-(this->get2()));
	vector->set3(-(this->get3()));

	#ifndef NDEBUG
	assert((std::abs(vector->get1() - (-old.get1())) < COTA_ERROR)
	  and  (std::abs(vector->get2() - (-old.get2())) < COTA_ERROR)
	  and  (std::abs(vector->get3() - (-old.get3())) < COTA_ERROR));
	#endif

	return *vector;
	}

ed::Vector3D & ed::Vector3D::operator * (double const k) const{

	ed::Vector3D *vector = new Vector3D();

	vector->set1(this->get1() * k);
	vector->set2(this->get2() * k);
	vector->set3(this->get3() * k);

	#ifndef NDEBUG
	assert((std::abs(vector->get1() - (this->get1() * k)) < COTA_ERROR)
	  and  (std::abs(vector->get2() - (this->get2() * k)) < COTA_ERROR)
	  and  (std::abs(vector->get3() - (this->get3() * k)) < COTA_ERROR));
	#endif

	return *vector;
	}

double ed::Vector3D::operator * (ed::Vector3D const &v)const{

	double valor;

	valor = this->get1() * v.get1() + this->get2() * v.get2() + this->get3() * v.get3();

	#ifndef NDEBUG
	assert(std::abs(valor - (this->get1() * v.get1() + this->get2() * v.get2() + this->get3() * v.get3()) ) < COTA_ERROR);
	#endif

	return valor;
	}

ed::Vector3D & ed::Vector3D::operator ^ (ed::Vector3D const &v) const{

	ed::Vector3D *vector = new Vector3D();

	vector->set1(this->get2() * v.get3() - this->get3() * v.get2());
	vector->set2(this->get3() * v.get1() - this->get1() * v.get3());
	vector->set3(this->get1() * v.get2() - this->get2() * v.get1());

	#ifndef NDEBUG
	assert(std::abs(this->dotProduct(*vector) - 0) < COTA_ERROR);
	assert(std::abs(v.dotProduct(*vector) - 0) < COTA_ERROR);
	assert(std::abs(vector->modulo() - (this->modulo() * v.modulo() * (std::abs(sin(this->angulo(v)))))) < COTA_ERROR);
	#endif

	return *vector;
	}


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *valorDevuelto = new ed::Vector3D();

	valorDevuelto->set1(k*objeto.get1());
	valorDevuelto->set2(k*objeto.get2());
	valorDevuelto->set3(k*objeto.get3());

	#ifndef NDEBUG
	assert((std::abs(valorDevuelto->get1() - (objeto.get1() * k)) < COTA_ERROR)
	  and  (std::abs(valorDevuelto->get2() - (objeto.get2() * k)) < COTA_ERROR)
	  and  (std::abs(valorDevuelto->get3() - (objeto.get3() * k)) < COTA_ERROR));
	#endif

	return *valorDevuelto;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	
	stream << "(" << objeto.get1() << ", " << objeto.get2() << ", " << objeto.get3() << ")";
	
	return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
	std::string x, y, z;

	getline(stream, x, ' ');
	getline(stream, y, ' ');
	getline(stream, z);

	objeto.set1(atof(x.c_str()));
	objeto.set2(atof(y.c_str()));
	objeto.set3(atof(z.c_str()));

  return stream;
} 

} // Fin del espacio de nombres ed
