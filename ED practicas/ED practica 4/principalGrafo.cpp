/*!

	\file    principalGrafo.cpp
	\brief   Programa principal de la práctica 4 de ED: árbol abarcador mínimo de un grafo
	\author  Álvaro García Fuentes
	\date    03-05-2018
	\version 1.0
*/

/*!
 \mainpage Implementación de un grafo
 \author   Álvaro García Fuentes
 \date     03-05-2018
 \version  1.0
*/

// Para los flujos de entrada y salida y para usar locale
#include <iostream>


#include <string>

#include "funcionesAuxiliares.hpp"

#include "Vertice.hpp"

//#include "Lado.hpp"

#include "Grafo.hpp"


/*! 
	\brief   Programa principal de la práctica 3: Medicion y Montículo de mediciones
	\return  int
*/
int main( ){

	ed::Grafo grafo, arbolPrim, arbolKruskal;

	int opcion;

	do{
		// Se elige la opción del menú
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch( opcion ){

			case 0: 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
				break;

			//////////////////////////////////////////////////////////////////

			case 1: 
				std::cout << "[1] Cargar un conjunto de vertices desde un fichero" << std::endl;
				ed::cargarVerticesDesdeFichero( Grafo );
				break;

			case 2:
				std::cout << "[2] Mostrar el grafo por pantalla" << std::endl;
				ed::mostrarGrafo( grafo );
				break;
			case 3: 
				std::cout << "[3] Cambiar el tipo del grafo a dirigido o no dirigido" << std::endl;
				ed::cambiarDirigido( grafo );
				break;
			//////////////////////////////////////////////////////////////////
			case 4: 
				std::cout << "[4] Árbol abarcador de coste mínimo" << std::endl;
				ed::ArbolAbarcadorMinimo( grafo , arbolPrim, arbolKruskal );
				break;

			//////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
			}
  
		if (opcion !=0){

			PLACE(25,1);
			std::cout << "Pulse ";
			std::cout << BIGREEN;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para mostrar el ";
			std::cout << INVERSE;
			std::cout << "menú"; 
			std::cout << RESET;

			// Pausa
			std::cin.ignore();

			std::cout << CLEAR_SCREEN;
			}
		}while(opcion!=0);

	return 0;
	}


