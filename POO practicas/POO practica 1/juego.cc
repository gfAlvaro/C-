
	/* juego.cc
	Programa que implementa un menú que comprueba el funcionamiento de todos los métodos de la clase Dados. */

#include <iostream>
#include "dados.h"

int main(){

	Dados Dados;
	int seguir, dado1, dado2;

	do{
		std::cout << "Introduzca la opción deseada.\n";
		std::cout << "1 para efectuar un lanzamiento de dados.\n";
		std::cout << "2 para mostrar el valor del primer dado.\n";
		std::cout << "3 para mostrar el valor del segundo dado.\n";
		std::cout << "4 para modificar el valor del primer dado.\n";
		std::cout << "5 para modificar el valor del segundo dado.\n";
		std::cout << "6 para mostrar el valor de la suma de los dados.\n";
		std::cout << "7 para mostrar el valor de la diferencia entre los dados.\n";
		std::cout << "0 para salir del menú.\n";
		std::cin >> seguir;

		switch(seguir){
			case 1:
				Dados.lanzamiento();
				std::cout << "Lanzamiento efectuado.\n";
				std::cout << "Nuevos valores de los dados:\n";
				std::cout << " Primer dado: " << Dados.getDado1() << "\n";
				std::cout << " Segundo dado: " << Dados.getDado2() << "\n";
				break;
			case 2:
				std::cout << "Valor del primer dado: " << Dados.getDado1() << "\n";
				break;
			case 3:
				std::cout << "Valor del segundo dado: " << Dados.getDado2() << "\n";
				break;
			case 4:
				std::cout << "Introduzca el valor para modificar el primer dado:\n";
				std::cin >> dado1;
				if(!Dados.setDado1(dado1))
					std::cout << "Error: el valor introducido no es válido.\n";
				else
					std::cout << "Nuevo valor para el primer dado: " << Dados.getDado1() << "\n";
				break;
			case 5:
				std::cout << "Introduzca el valor para modificar el segundo dado:\n";
				std::cin >> dado2;
				if(!Dados.setDado2(dado2))
					std::cout << "Error: el valor introducido no es válido.\n";
				else
					std::cout << "Nuevo valor para el segundo dado: " << Dados.getDado2() << "\n";
				break;
			case 6:
				std::cout << "La suma de los valores de los dos dados es: " << Dados.getSuma() << "\n";
				break;
			case 7:
				std::cout << "La diferencia entre los valores de los dos dados es: "
				 << Dados.getDiferencia() << "\n";
				break;
			case 0:
				std::cout << "Saliendo del menú...\n";
				break;
			default:
				std::cout << "Opción no válida.\n";
			}
		std::cout << "\n";
		}while(seguir != 0);
	}
