
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author Álvaro García Fuentes
  \date  01/03/2018
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*! 
		\brief     Funcion para leer tres vectores desde teclado
		\note      El primer vector se introducirá componente a componente y los otros dos mediante el operador de sobrecarga >>
		\param     u, v, w: Objetos de tipo Vector3D pasados como referencias
	*/
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*! 
		\brief     Funcion para escribir por pantalla tres vectores
		\note      El primer vector se escribirá usando la función de la clae y los otros dos mediante el operador de sobrecarga <<
		\param     u, v, w: Objetos de tipo Vector3D pasados como referencias constantes
	*/
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);


	/*! 
		\brief     Funcion para mostrar los ángulos que forman los vectores dados
		\note      Si no se pudiera calcular algún ángulo se mostrará un mensaje indicándolo
		\param     u, v: Objetos de tipo Vector3D pasados como referencias constantes
	*/
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief     Funcion para mostrar las modificaciones posibles entre los vectores dados
		\note      Se efectúa sobre u el producto escalar y vectorial con v, además de sumarlo y multiplicarlo por k
		\param     u, v: Objetos de tipo Vector3D pasados como referencias, siendo v constante
		\param     k: valor de tipo double
	*/
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	/*! 
		\brief     Funcion para mostrar el producto escalar entre dos vectores
		\note      Se mostrará el producto escalar mediante la funcion de la clase y también con el operador de sobrecarga*
		\param     u, v: Objetos de tipo Vector3D pasados como referencias constantes
	*/
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 

	/*! 
		\brief     Funcion para mostrar el producto vectorial entre dos vectores
		\note      Se mostrará el producto vectorial mediante la funcion de la clase y también con el operador de sobrecarga^
		\param     u, v: Objetos de tipo Vector3D pasados como referencias constantes
	*/
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*! 
		\brief     Funcion para mostrar el producto mixto entre tres vectores
		\note      Si no se pudiera calcular el producto mixto se mostrará un mensaje indicándolo
		\param     u, v: objetos de tipo Vector3D pasados como referencias constantes
	*/
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*! 
		\brief     Funcion para mostrar el uso de los operadores de la clase Vector3D
		\param     u, v, w: objetos de tipo Vector3D pasados como referencias constantes
		\param     k: valor de tipo double
	*/
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);



} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

