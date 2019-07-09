
	/* jugador.cc
	Fichero con las definiciones de los miembros no inline de la clase Jugador.*/

#include "jugador.h"

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

void Jugador::setApuestas(){

	std::string linea, nombreFichero = getDNI() + ".txt";
	char tipo[256], valor[256], cantidad[256];
	//std::istringstream lineaStream;
	Apuesta Apu;

	std::ifstream fichero(nombreFichero.c_str());

	if(!fichero.is_open()){
		std::cout << "Error, no se pudo abrir el fichero." << std::endl;
		exit(1);
		}
	else{	
		while(std::getline(fichero, linea)){
			std::istringstream lineaStream(linea);
			
			lineaStream.getline(tipo, 256, ',');
			Apu.tipo=atoi(tipo);

			lineaStream.getline(valor, 256, ',');
			Apu.valor=valor;

			lineaStream.getline(cantidad, 256, '\n');
			Apu.cantidad=atoi(cantidad);

			apuestas_.push_back(Apu);
			}
		fichero.close();
		}	
	}
	
