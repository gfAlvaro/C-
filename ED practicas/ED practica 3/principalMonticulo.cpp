/*!
 \mainpage Implementación de un montículo de mediciones
 \author   Álvaro García Fuentes
 \date     03-05-2018
 \version  1.0
*/


/*!

	\file principalMediciones.cpp
	\brief Programa principal de la practica 3 de Estructuras de Datos
*/

#include <iostream>

#include <string>

#include "funcionesAuxiliares.hpp"

#include "MonticuloMediciones.hpp"
#include "Medicion.hpp"

#include "macros.hpp"

/*! 
	\brief   Programa principal de la práctica 2: montículo de mediciones
	\return  int
*/
int main(int argc, char *argv[]){

	if (argc != 3){

		std::cout << "Modo de ejecución" << std::endl;
		std::cout << argv[0] << " <fichero-de-mediciones>  <fichero-ordenado> "  << std::endl;

		return -1;
		}

	ed::MonticuloMediciones monticulo;

	std::string nombreFicheroEntrada( argv[1] );
	std::string nombreFicheroSalida( argv[2] );
	
	// Se cargan las mediciones desde el fichero: se crea un montículo de máximos
	std::cout << "Se cargan las mediciones desde el fichero " << nombreFicheroEntrada << std::endl;
	std::cout << " Se crea un montículo de máximos " << std::endl;
	ed::cargarMonticuloDeFichero(nombreFicheroEntrada,monticulo);

	std::cout << "Tamaño del montículo " << monticulo.size() << std::endl;

	// Se graba el montículo en el fichero: las mediciones son grabadas en orden descendente
	std::cout << "Se graba el montículo en el fichero " << nombreFicheroSalida << std::endl;
	std::cout << "Las mediciones son grabadas en orden descendente " << std::endl;

	ed::grabarMonticuloEnFichero(nombreFicheroSalida,monticulo);

  
	return 0;
	}


