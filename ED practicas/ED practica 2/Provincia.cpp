/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author  Álvaro García Fuentes
	\date  08-04-2018
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>

// Para comprobar las pre y post condiciones
#include <cassert>

#include <cstring>
#include <cstdlib>

#include <string>
#include <sstream>
#include "Provincia.hpp"



// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

const int ed::Provincia::getTotalHombres() {

	int cuenta=0;

	if(this->getNumeroMunicipios() > 0)
		this->_listaMunicipios.gotoHead();

	while((not this->_listaMunicipios.isEmpty()) and (not this->_listaMunicipios.isLastItem())){

		cuenta = cuenta + _listaMunicipios.getCurrentItem().getHombres();
		this->_listaMunicipios.gotoNext();
		}

	if(this->getNumeroMunicipios() > 0)
		this->_listaMunicipios.gotoHead();

	return cuenta;
	}

const int ed::Provincia::getTotalMujeres() {

	int cuenta=0;

	if(this->getNumeroMunicipios() > 0)
		this->_listaMunicipios.gotoHead();

	while((not this->_listaMunicipios.isEmpty()) and (not this->_listaMunicipios.isLastItem())){

		cuenta = cuenta + _listaMunicipios.getCurrentItem().getMujeres();
		this->_listaMunicipios.gotoNext();
		}

	if(this->getNumeroMunicipios() > 0)
		this->_listaMunicipios.gotoHead();

	return cuenta;
	}

const int ed::Provincia::getTotalHabitantes() {

	int cuenta=0;

	if(this->getNumeroMunicipios() > 0)
		this->_listaMunicipios.gotoHead();

	while((not this->_listaMunicipios.isEmpty()) and (not this->_listaMunicipios.isLastItem())){

		cuenta = cuenta + _listaMunicipios.getCurrentItem().getHombres() + _listaMunicipios.getCurrentItem().getMujeres();
		this->_listaMunicipios.gotoNext();
		}
	if(this->getNumeroMunicipios() > 0)
		this->_listaMunicipios.gotoHead();

	#ifndef NDEBUG
	assert(cuenta == (this->getTotalHombres() + this->getTotalMujeres()));
	#endif
	return cuenta;
	}

bool ed::Provincia::existeMunicipio(std::string const nombre){

	ed::Municipio municipio(nombre);

	bool existe;

	if(this->getNumeroMunicipios() > 0){
		existe = this->_listaMunicipios.find(municipio);
		}
	else
		existe=false;

	return existe;
	}

///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios(){

	std::cout << "Lista de municipios: " << std::endl;	

	if(this->getNumeroMunicipios() == 0)
		std::cout << "	No hay municipios." << std::endl;	

	else{
		_listaMunicipios.gotoHead();

		int x, num = _listaMunicipios.nItems();

		for( x = 1 ; x <= num ; x++ ){
			std::cout << "	" << _listaMunicipios.getCurrentItem().getNombre() << std::endl;
			std::cout << "		Código Postal: " << _listaMunicipios.getCurrentItem().getCodigoPostal() << std::endl;
			std::cout << "		Habitantes: " << _listaMunicipios.getCurrentItem().getHabitantes() << std::endl;
			std::cout << "		 Hombres: " << _listaMunicipios.getCurrentItem().getHombres() << std::endl;
			std::cout << "		 Mujeres: " << _listaMunicipios.getCurrentItem().getMujeres() << std::endl;

			if(not _listaMunicipios.isLastItem())
				_listaMunicipios.gotoNext();
			}
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS

bool ed::Provincia::cargarFichero(std::string const nombre){

	std::ifstream fichero(nombre.c_str());
	std::string code, name, nom, codigoPostal, hombres, mujeres;
	ed::Municipio municipio;
	std::string linea;

	if(fichero.fail())
		return false;

	else{
		// Se extrae la primera línea del fichero con los datos de la provincia.
		std::getline( fichero, code, ' ');
		std::getline( fichero, name, '\n');

		this->setCodigo(atoi(code.c_str()));
		this->setNombre(name);

		// Se extraen el resto de líneas con los datos de los municipios.
		while(std::getline(fichero, linea) ){

			std::getline( fichero, codigoPostal, ' ');
			std::getline( fichero, nom, ';');
			std::getline( fichero, hombres, ';');
			std::getline( fichero, mujeres, ';');

			municipio.setCodigoPostal(atoi(codigoPostal.c_str()));
			municipio.setNombre(nom);
			municipio.setHombres(atoi(hombres.c_str()));
			municipio.setMujeres(atoi(mujeres.c_str()));

			if(not this->existeMunicipio(municipio.getNombre()))
				_listaMunicipios.insert(municipio);
			}

		fichero.close();
		return true;
		}
	}

bool ed::Provincia::grabarFichero(std::string const nombre){

	std::ofstream fichero(nombre.c_str());

		if(fichero.fail()){
			return false;
			}
		else{
			fichero << this->getCodigo();
			fichero << " " << this->getNombre() << "\n";

			if(not _listaMunicipios.isEmpty()){
				int num = _listaMunicipios.nItems();
				_listaMunicipios.gotoHead();
				for(int x = 1; x <= num ; x++){

					fichero << _listaMunicipios.getCurrentItem().getCodigoPostal();
					fichero << " " << _listaMunicipios.getCurrentItem().getNombre() << ";";
					fichero << _listaMunicipios.getCurrentItem().getHombres() << ";";
					fichero << _listaMunicipios.getCurrentItem().getMujeres() << ";" << "\n";

					if( not _listaMunicipios.isLastItem() )
						_listaMunicipios.gotoNext();
				}
				};

			fichero.close();
			return true;
			}
	}


