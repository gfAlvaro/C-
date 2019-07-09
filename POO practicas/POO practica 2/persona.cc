
	/* persona.cc
	Fichero que contiene la definición de las funciones no inline
	 de la clase Persona contenida en el archivo persona.h. */

#include "persona.h"

Persona::Persona(std::string DNI, std::string nombre, std::string apellidos, std::string direccion,
 std::string localidad, std::string provincia, std::string pais){

	_DNI=DNI;
	_nombre=nombre;
	_apellidos=apellidos;
	_direccion=direccion;
	_localidad=localidad;
	_provincia=provincia;
	_pais=pais;
	}
