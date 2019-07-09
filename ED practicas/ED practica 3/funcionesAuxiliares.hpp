/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Álvaro García Fuentes
  \date   03-05-2018
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include "MonticuloMediciones.hpp"


namespace ed{

/*!
	\brief Función que carga un montículo almacenado en un fichero .txt
	\note  El fichero debe existir para poder cargar sus datos
	\note  Función codificada en el fichero cpp
	\param nombreFichero Variable de tipo string pasada como referencia constante
	\param monticulo Objeto de la clase MonticuloMediciones pasado como referencia
	\sa    grabarMonticuloEnFichero()
*/
void cargarMonticuloDeFichero ( std::string const & nombreFichero, ed::MonticuloMediciones & monticulo );

/*!
	\brief   Función que graba un montículo en un fichero .txt
	\note    Si el fichero no existe se crea
	\note    Función codificada en el fichero cpp
	\warning Si el fichero existe sus datos se sobreescriben
	\param   nombreFichero Variable de tipo string pasada como referencia constante
	\param   monticulo Objeto de la clase MonticuloMediciones pasado como referencia constante
	\sa      cargarMonticuloDeFichero()
*/
void grabarMonticuloEnFichero ( std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo ); 


// Funciones para principalMonticulo2.cpp

/*!
	\brief  Muestra un menú para seleccionar una opción
	\note   Función codificada en el fichero cpp
	\return variable de tipo int
*/
int menu();

/*!
	\brief Muesta un mensaje que indica si el montículo está vacío o no
	\note  Función codificada en el fichero cpp
	\param monticulo Objeto de la clase Monticulo pasado como referencia constante
	\sa    mostrarNumeroMedicionesMonticulo(), mostrarMedicionesAltas()
*/
void comprobarMonticuloVacio( const ed::MonticuloMediciones & monticulo );

/*!
	\brief Muestra el número de mediciones contenidas en el montículo
	\note  Función codificada en el fichero cpp
	\param monticulo Objeto de la clase Monticulo pasado como referencia constante
	\sa    mostrarNumeroMedicionesMonticulo(), mostrarMedicionesAltas()
*/
void mostarNumeroMedicionesMonticulo( const ed::MonticuloMediciones & monticulo );

/*!
	\brief Muestra las mediciones más altas del montículo
	\note  Función codificada en el fichero cpp
	\note  El usuario deberá indicar cuántas mediciones serán mostradas
	\param monticulo Objeto de la clase Monticulo pasado como referencia constante
	\sa    mostrarNumeroMedicionesMonticulo(), comprobarMonticuloVacio()
*/
void mostrarMedicionesAltas( const ed::MonticuloMediciones & monticulo );

/*!
	\brief Inserta una medición en el montículo respetando la ordenación de máximos
	\note  Función codificada en el fichero cpp
	\param monticulo Objeto de la clase Monticulo pasado como referencia
	\sa    borrarMedicionDeMonticulo(), borrarTodasMedicionesMonticulo()
*/
void insertarMedicionEnMonticulo( ed::MonticuloMediciones & monticulo );

/*!
	\brief Borra la medición de la cima del montículo
	\note  Función codificada en el fichero cpp
	\param monticulo Objeto de clase montículo pasado como referencia	
	\sa    insertarMedicionMonticulo(), borrarTodasMedicionesMonticulo()
*/
void borrarMedicionDeMonticulo( ed::MonticuloMediciones & monticulo );

/*!
	\brief Borra todas las mediciones del montículo
	\note  Función codificada en el fichero cpp
	\param monticulo Objeto de la clase Monticulo pasado como referencia
	\sa    insertarMonticulo(), borrarMedicionDeMonticulo()
*/
void borrarTodasMedicionesMonticulo( ed::MonticuloMediciones & monticulo );

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_
#endif

