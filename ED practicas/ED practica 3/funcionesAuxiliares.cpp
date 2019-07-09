/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Álvaro García Fuentes
  \date   03-05-2018
*/


#include <iostream>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"

// Cargar datos de monticulo desde un fichero de texto.
void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo){

	std::ifstream fichero( nombreFichero.c_str() );

	if( not fichero.is_open() )
		std::cout << "No se pudo abrir el fichero solicitado" << std::endl;
	else{
		monticulo.removeAll();

		ed::Medicion medicion;

		while( fichero >> medicion )
			monticulo.insert( medicion );

		fichero.close();

		std::cout << "Se ha cargado el montículo desde el fichero " << nombreFichero << std::endl;
		}

	return;
	}

// Grabar datos de monticulo en un fichero de texto.
void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo){

	std::ofstream fichero( nombreFichero.c_str() );

	if( not fichero.is_open() )
		std::cout << "No se pudo crear el fichero solicitado" << std::endl;
	else{
		ed::MonticuloMediciones monti( monticulo );

		while( not monti.isEmpty() ){

			fichero << monti.top() << std::endl;
			monti.remove();
			}

		fichero.close();

		std::cout << "Se ha grabado el montículo en el fichero " << nombreFichero <<std::endl;
		}

	return;
	}

 
// Funciones para el segundo programa de prueba

int ed::menu(){

	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si el montículo tiene mediciones";

	PLACE(posicion++,10);
	std::cout << "[2] Mostrar el número de mediciones del montículo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[3] Cargar el montículo desde el fichero";
 
	PLACE(posicion++,10);
	std::cout << "[4] Grabar el montículo en el fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar las mediciones más altas del montículo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[6] Insertar una medición";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar la primera medición del montículo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Borrar todas las mediciones del montículo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
	}

// Comprobar si el montículo está vacío
void ed::comprobarMonticuloVacio( const ed::MonticuloMediciones & monticulo ){

	if( monticulo.isEmpty() )
		std::cout << "El montículo está vacío" << std::endl;
	else
		std::cout << "El montículo no está vacío" << std::endl;
	}

// Mostrar el número de mediciones que contiene el montículo
void ed::mostarNumeroMedicionesMonticulo( const ed::MonticuloMediciones & monticulo ){

	std::cout << "El montículo tiene " << monticulo.size() << " mediciones" << std::endl;
	}

// Mostrar las "num" mediciones más altas del montículo
void ed::mostrarMedicionesAltas( const ed::MonticuloMediciones & monticulo ){

	unsigned int tam = monticulo.size();

	if(tam == 0){
		std::cout << "El montículo está vacío" << std::endl;
		return;
		}
	else{
		int num;
		ed::MonticuloMediciones monti( monticulo );

		do{
			std::cout << "Seleccione cuántas mediciones desea ver (Entre 1 y " << tam << ")" << std::endl;
			std::cin >> num;	
			}while( (num < 1) or ( (unsigned) num > tam ) );

		// Se elimina el salto de línea del flujo de entrada
		std::cin.ignore();

		for(int i = 1 ; i <= num ; i++ ){

			std::cout << i << " " << monti.top().getFecha() << " " << monti.top().getPrecipitacion() << std::endl;
			monti.remove();
			}

		monti.removeAll();
		return;
		}
	}

// Insertar una medición en el montículo de mediciones manteniendo la ordenación de máximos
void ed::insertarMedicionEnMonticulo( ed::MonticuloMediciones & monticulo ){

	ed::Medicion medicion;

	std::cout << "Introduzca la medición con el formato: dd-mm-aaaa precipitacion" << std::endl;
	std::cin >> medicion;

	monticulo.insert(medicion);
	std::cout << "Se ha insertado la medicion en el montículo" << std::endl;
	}

// Borrar el elemento de la cima del montículo de mediciones
void ed::borrarMedicionDeMonticulo( ed::MonticuloMediciones & monticulo ){
	
	monticulo.remove();
	std::cout << "Se ha borrado la primera medición del montículo" << std::endl;
	}

// Borrar todos los elementos del montículo de mediciones
void ed::borrarTodasMedicionesMonticulo( ed::MonticuloMediciones & monticulo ){
	
	monticulo.removeAll();
	std::cout << "Se han borrado las mediciones del montículo" << std::endl;
	}


