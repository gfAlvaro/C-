
	/* persona.h
	Fichero de cabecera que contiene la declaración de la clase Persona. */

#ifndef STRING
	#define STRING
	#include <string>
	#endif

#ifndef PERSONA
	#define PERSONA
	class Persona{
		private:
			std::string _DNI;
			std::string _nombre;
			std::string _apellidos;
			std::string _direccion;
			std::string _localidad;
			std::string _provincia;
			std::string _pais;
		public:
			Persona(std::string DNI, std::string nombre="", std::string apellidos="", std::string direccion="",
			 std::string localidad="", std::string provincia="", std::string pais="");

			inline void setDNI(std::string DNI){_DNI=DNI;};
			inline void setNombre(std::string nombre){_nombre=nombre;};
			inline void setApellidos(std::string apellidos){_apellidos=apellidos;};
			inline void setDireccion(std::string direccion){_direccion=direccion;};
			inline void setLocalidad(std::string localidad){_localidad=localidad;};
			inline void setProvincia(std::string provincia){_provincia=provincia;};
			inline void setPais(std::string pais){_pais=pais;};

			inline std::string getDNI(){return _DNI;};
			inline std::string getNombre(){return _nombre;};
			inline std::string getApellidos(){return _apellidos;};
			inline std::string getDireccion(){return _direccion;};
			inline std::string getLocalidad(){return _localidad;};
			inline std::string getProvincia(){return _provincia;};
			inline std::string getPais(){return _pais;};

			inline std::string getApellidosyNombre(){return _apellidos + ", " + _nombre;};
		};
	#endif

