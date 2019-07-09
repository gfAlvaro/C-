/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author Álvaro García Fuentes
  \date   08-04-2018
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


namespace ed
{

  int menu();

	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Función que comprueba si la Provinca está vacía
		\note  	Función codificada en el fichero cpp
		\note   Muestra por pantalla un mensaje diciendo si la provincia está vacía o no
		\param  provincia: objeto de la clase Provincia, pasado como referencia
	*/
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Función que carga los datos de una Provincia desde un fichero de texto
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     grabarProvincia
	*/
	void cargarProvincia(ed::Provincia & provincia);

	/*!
		\brief  Función que graba los datos de una Provincia en un fichero de texto
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     cargarProvincia
	*/
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Función que muestra por pantalla los datos referentes a una Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     mostrarMunicipiosDeProvincia
	*/
	void consultarDatosDeProvincia(ed::Provincia & provincia);

	/*!
		\brief  Función que muestra por pantalla la lista de municipios de una Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     consultarDatosDeProvincia
	*/
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Función para modificar el nombre y/o el código de una Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
	*/
	void modificarDatosDeProvincia(ed::Provincia & provincia);

	/*!
		\brief  Función que borra la lista de municipios de una Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     insertarMunicipioEnProvincia, borrarMunicipioDeProvincia
	*/
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Función que muestra por pantalla un municipio de la lista de la Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
	*/
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

	/*!
		\brief  Función que inserta de forma ordenada un municipio en la lista de municipios de la Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     borrarMunicipioDeProvincia, borrarTodosLosMunicipiosDeProvincia
	*/
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

	/*!
		\brief  Función que borra un municipio de la lista de municipios de una Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
		\sa     insertarMunicipioEnProvincia, borrarTodosLosMunicipiosDeProvincia
	*/
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);

	// Función añadida por el estudiante
	/*!
		\brief  Función que muestra cuál es el sexo mayoritario en la Provincia
		\note  	Función codificada en el fichero cpp
		\param  provincia: objeto de la clase Provincia, pasado como referencia
	*/
	void mostrarSexoMayoritario(ed::Provincia & provincia);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

