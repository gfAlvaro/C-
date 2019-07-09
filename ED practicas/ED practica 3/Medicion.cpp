/*! 
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida
ostream & operator << ( ostream &stream , ed::Medicion const &medicion ){

	stream << medicion.getFecha() << " " << medicion.getPrecipitacion();

	return stream;
	}

// Sobrecarga del operador de entrada
istream & operator >> ( istream & stream , ed::Medicion &medicion ){

	ed::Fecha fecha;
	float precipitacion;

	stream >> fecha;
	stream >> precipitacion;

	medicion.setFecha( fecha );
	medicion.setPrecipitacion( precipitacion );

	return stream;
	} 

} // Fin del espacio de nombres ed

