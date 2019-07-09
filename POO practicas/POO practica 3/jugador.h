
	/* jugador.h
	Fichero de cabecera que contiene la declaración de la clase Jugador y de la clase Apuesta. */

// En este header está incluida la biblioteca string.
#include "persona.h"

#ifndef IOSTREAM
	#define IOSTREAM
	#include <iostream>
	#endif

#ifndef FSTREAM
	#define FSTREAM
	#include <fstream>
	#endif

#ifndef SSTREAM
	#define SSTREAM
	#include <sstream>
	#endif
#ifndef OSTREAM
	#define ISTREAM
	#include <istream>
	#endif

#ifndef CSTDLIB
	#define CSTDLIB
	#include <cstdlib>
	#endif

#ifndef LIST
	#define LIST
	#include <list>
	#endif

#ifndef APUESTA
	#define APUESTA
	class Apuesta{
		public:
			int tipo;
			std::string valor;
			int cantidad;
		};
	#endif

#ifndef JUGADOR
	#define JUGADOR
	class Jugador : public Persona{
		private:
			int dinero_;
			std::string codigo_;
			std::list<Apuesta> apuestas_;
		public:			
			Jugador(std::string DNI, std::string codigo, std::string nombre="", std::string apellidos="",
			 std::string direccion="", std::string localidad="", std::string provincia="", std::string pais="") :
			 Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){codigo_=codigo; dinero_=1000;};
	
			inline std::string getCodigo(){return codigo_;};
			inline int getDinero(){return dinero_;};
	
			inline void setCodigo(std::string codigo){codigo_=codigo;};
			inline void setDinero(int dinero){dinero_=dinero;};
	
			inline std::list<Apuesta> getApuestas(){return apuestas_;};
			void setApuestas();
		};
	#endif

