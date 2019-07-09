
#include"ruleta.h"

Ruleta::Ruleta(Crupier crupier) : crupier_(crupier){
	
	srand(time(NULL));
	bola_ = -1;
	banca_ = 1000000;
	}

bool Ruleta::setBanca(int banca){

	if(banca<0)
		return false;
	else
		return true;
	}

bool Ruleta::setBola(int bola){

	if ((bola<0) || (bola>36))
		return false;
	else
		return true;
	}

bool Ruleta::addJugador(Jugador jugador){

	std::list<Jugador>::iterator it = jugadores_.begin(), itend = jugadores_.end();
	std::string nombreFichero = jugador.getDNI() + ".txt";
	std::ifstream fichero;

	fichero.open(nombreFichero.c_str());

	if(!fichero.is_open())
		std::ofstream fichero(nombreFichero.c_str());	

	for( ; it!=itend; it++)
		if(it->getDNI()==jugador.getDNI())
			return false;

	jugadores_.push_back(jugador);

	return true;
	}

int Ruleta::deleteJugador(Jugador jugador){

	std::list<Jugador>::iterator it = jugadores_.begin(), itend = jugadores_.end();

	if(jugadores_.empty())
		return -1;
	else{
		for( ; it!=itend; it++)
			if(it->getDNI() == jugador.getDNI()){
				jugadores_.erase(it);
				return 1;
				}
		return -2;
		}
	}

int Ruleta::deleteJugador(std::string DNI){

	std::list<Jugador>::iterator it = jugadores_.begin(), itend = jugadores_.end();

	if(jugadores_.empty())
		return -1;
	else{
		for( ; it!=itend; it++)
			if(it->getDNI() == DNI){
				jugadores_.erase(it);
				return 1;
				}
		return -2;
		}
	}

void Ruleta::leeJugadores(){

	std::ifstream fichero;
	std::string linea;
	char DNI[256], codigo[256], nombre[256], apellidos[256], direccion[256],
	 localidad[256], provincia[256], pais[256], dinero[256];
	std::istringstream lineaStream;
	Jugador Aux(0, 0);
	
	fichero.open("jugadores.txt");

	if(fichero.is_open())
		jugadores_.clear();
	else
		std::cout << "Error: no se pudo abrir el fichero." << std::endl;

	while(std::getline(fichero, linea)){

		std::istringstream lineaStream(linea);

		lineaStream.getline(DNI, 256, ',');
		Aux.setDNI(DNI);

		lineaStream.getline(codigo, 256, ',');
		Aux.setCodigo(codigo);

		lineaStream.getline(nombre, 256, ',');
		Aux.setNombre(nombre);

		lineaStream.getline(apellidos, 256, ',');
		Aux.setApellidos(apellidos);

		lineaStream.getline(direccion, 256, ',');
		Aux.setDireccion(direccion);

		lineaStream.getline(localidad, 256, ',');
		Aux.setLocalidad(localidad);

		lineaStream.getline(provincia, 256, ',');
		Aux.setProvincia(provincia);

		lineaStream.getline(pais, 256, ',');
		Aux.setPais(pais);

		lineaStream.getline(dinero, 256, '\n');
		Aux.setDinero(atoi(dinero));

		jugadores_.push_back(Aux);
		}
	
	fichero.close();
	}

void Ruleta::escribeJugadores(){

	std::list<Jugador>::iterator it = jugadores_.begin(), itend = jugadores_.end();
	std::ifstream fichero;
	std::string cadena, dinero;
	fichero.open("jugadores.txt");

	if(!fichero.is_open())
		std::ofstream fichero("jugadores.txt");

	for( ; it!=itend; it++){
		dinero = std::to_string(it->getDinero());
		cadena = it->getDNI() + "," + it->getCodigo() + "," + it->getNombre() + ","
		 + it->getApellidos() + "," + it->getDireccion() + "," + it->getLocalidad()
		 + "," + it->getProvincia() + "," + it->getPais() + "," + dinero + '\n'; 

		fichero >> cadena;
		}

	fichero.close();
	}

void Ruleta::giraRuleta(){

	bola_ = rand()%37;
	}

void Ruleta::getPremios(){

	std::list<Jugador>::iterator it = jugadores_.begin(), itend = jugadores_.end();
	std::list<Apuesta>::iterator it2, itend2;

	for( ; it!=itend; it++){

		it->setApuestas();
		it2 = it->getApuestas().begin();
		itend2 = it->getApuestas().end();

		for( ; it2!=itend2; it2++)
			if( ((bola_%2==0) && (it2->valor=="par"))
			 || ((bola_%2==1) && (it2->valor=="impar"))

			 || (((bola_>=1) && (bola_<=18)) && (it2->valor=="bajo"))
			 || (((bola_>=19) && (bola_<=36)) && (it2->valor=="alto"))

			 || (((((bola_>=1) && (bola_<=9)) && (bola_%2==1))
			 || (((bola_>=12) && (bola_<=18)) && (bola_%2==0))
			 || (((bola_>=19) && (bola_<=27)) && (bola_%2==1))
			 || (((bola_>=30) && (bola_<=36)) && (bola_%2==0))) && (it2->valor=="rojo"))

			 || (((((bola_>=2) && (bola_<=10)) && (bola_%2==0))
			 || (((bola_>=11) && (bola_<=13)) && (bola_%2==1))
			 || (((bola_>=20) && (bola_<=28)) && (bola_%2==0))
			 || (((bola_>=29) && (bola_<=35)) && (bola_%2==1))) && (it2->valor=="negro")) ){
				it->setDinero(it->getDinero() + it2->cantidad);
				banca_ = banca_ - it2->cantidad;
				}
			else{
				it->setDinero(it->getDinero() - it2->cantidad);
				banca_ = banca_ + it2->cantidad;
				}
		}
	}

