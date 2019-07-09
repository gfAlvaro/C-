/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author Álvaro García Fuentes
  \date   08-04-2018
*/

#include <iostream>
#include <string>  

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


#include "macros.hpp"

#include <fstream>

int ed::menu()
{
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
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

	// Modificación hecha por el estudiante

	posicion++;
	PLACE(posicion++,10);
	std::cout << "[11] Mostrar el sexo mayoritario";

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


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
	if(provincia.hayMunicipios())
		std::cout << "La provincia tiene municipios." << std::endl;
	else
		std::cout << "La provincia no tiene municipios." << std::endl;
	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{

	std::string nombreProvincia;

	std::cout << "Introduzca el nombre del fichero a cargar: " << std::endl;
	std::cin >> nombreProvincia;

	std::ifstream fichero(nombreProvincia.c_str());

	if(fichero.fail())
		std::cout << "El fichero introducido no existe." << std::endl;
	else{
		fichero.close();

		if(provincia.cargarFichero(nombreProvincia))
			std::cout << "Provincia cargada con éxito." << std::endl;
		else
			std::cout << "Error, no se ha podido cargar la provincia." << std::endl;
		}
	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	std::string nombre;

	nombre = provincia.getNombre();

	if(provincia.grabarFichero(nombre + ".txt"))
		std::cout << "Provincia grabada con éxito." << std::endl;
	else
		std::cout << "Error, no se ha podido grabar la provincia" << std::endl;

	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	std::cout << "Provincia: " << provincia.getNombre() << std::endl;
	std::cout << "Código " << provincia.getCodigo() << std::endl;
	provincia.escribirMunicipios();

	return;
}

//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{
	provincia.escribirMunicipios();

	return;
}

////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{
	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}

void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
	provincia.borrarTodosLosMunicipios();
	std::cout << "Se han borrado todos los municipios de la provincia." << std::endl;

	return;
}

void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::string nombre;
	std::cout << "Introduzca el municipio a consultar" << std::endl;
	std::getline(std::cin, nombre);

	if(provincia.existeMunicipio(nombre)){

		std::cout << "Nombre: " << provincia.getMunicipio(nombre).getNombre() << std::endl;
		std::cout << "CódigoPostal: " << provincia.getMunicipio(nombre).getCodigoPostal() << std::endl;
		std::cout << "Habitantes: " << provincia.getMunicipio(nombre).getHabitantes() << std::endl;
		std::cout << " Hombres: " << provincia.getMunicipio(nombre).getHombres() << std::endl;
		std::cout << " Mujeres: " << provincia.getMunicipio(nombre).getMujeres() << std::endl;
		}
	else
		std::cout << "No existe el municipio dado." << std::endl;

	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
	ed::Municipio municipio;

	std::string nombre;
	int codigoPostal, hombres, mujeres;

	std::cout << "Introduzca el nombre del municipio a insertar: " << std::endl;
	std::getline(std::cin, nombre);

	std::cout << "Introduzca el código postal: " << std::endl;
	std::cin >> codigoPostal;

	std::cout << "Introduzca el número de hombres: " << std::endl;
	std::cin >> hombres;

	std::cout << "Introduzca el número de mujeres: " << std::endl;
	std::cin >> mujeres;

	municipio.setNombre(nombre);
	municipio.setCodigoPostal(codigoPostal);
	municipio.setHombres(hombres);
	municipio.setMujeres(mujeres);

	if( not provincia.existeMunicipio(municipio.getNombre()) )
		provincia.insertarMunicipio(municipio);
	else
		std::cout << "El municipio ya existe." << std::endl;
	return;
}

void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::string nombre;
	std::cout << "Indique el municipio a borrar" << std::endl;
	std::getline(std::cin, nombre);

	if( provincia.existeMunicipio(nombre) ){

		provincia.borrarMunicipio(nombre);
		std::cout << "El municipio se ha borrado." << std::endl;
		}
	else
		std::cout << "No existe el municipio dado." << std::endl;

	return;
}

// Función añadida por el estudiante.
void ed::mostrarSexoMayoritario(ed::Provincia & provincia){

	int hombres = provincia.getTotalHombres(), mujeres = provincia.getTotalMujeres();

	std::string nombre = provincia.getNombre();

	if( hombres < mujeres ){
		std::cout << "En la provincia de " << nombre;
		std::cout << " hay más mujeres (" << mujeres << ")";
		std::cout << " que hombres (" << hombres << ")." << std::endl;
		}
	else if( hombres > mujeres ){
		std::cout << "En la provincia de " << nombre;
		std::cout << " hay menos mujeres (" << mujeres << ")";
		std::cout << " que hombres (" << hombres << ")." << std::endl;
		}
	else{
		std::cout << "En la provincia de " << nombre;
		std::cout << " hay igual número de mujeres (" << mujeres << ")";
		std::cout << " que de hombres (" << hombres << ")." << std::endl;		
		}
	}







