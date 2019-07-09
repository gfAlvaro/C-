
	/* jugador.cc
	Fichero con las definiciones de los miembros no inline de la clase Jugador.*/

#include "jugador.h"

void Jugador::setApuestas(){

	std::string linea, nombreFichero = getDNI() + ".txt";
	char tipo[256], valor[256], cantidad[256];
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
	
