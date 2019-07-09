
	/* crupier.h
	Fichero de cabecera con la declaración de la clase Crupier. */

#ifndef CRUPIER
	#define CRUPIER
	#include "persona.h"
	class Crupier : public Persona{
		private:
			std::string codigo_;
		public:
			Crupier(std::string DNI, std::string codigo, std::string nombre="", std::string apellidos="",
			 std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="") :
			 Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais) {codigo_=codigo;};

			inline std::string getCodigo(){return codigo_;};
			inline void setCodigo(std::string codigo){codigo_=codigo;};
		};
	#endif
