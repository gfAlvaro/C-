/*!
	\file   MonticuloMedicionesInterfaz.hpp
	\brief  Se define la interfaz del TAD MonticuloMediciones.
	\author Álvaro García Fuentes
	\date   03-05-2018
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"


namespace ed{

	class MonticuloMedicionesInterfaz{

		public:
			//!	\name Observadores públicos

			/*!
				\brief  Comprueba si el montículo está vacío
				\note   Método virtual puro, a definir por la clase heredera
				\note   Método const
				\return variable de tipo const bool
				\post   Devuelve verdadero si no tiene condiciones, y falso en caso contrario
			*/
			virtual const bool isEmpty() const = 0;

			/*!
				\brief  Devuelve el elemento que está en la cima del montículo
				\note   Método virtual puro, a definir en la clase heredera
				\note   Método const
				\return Objeto de la clase Medicion devuelto como referencia constante
				\pre    El montículo no está vacío
			*/
			virtual const ed::Medicion & top() const = 0;


			//!	\name Modificadores públicos

			/*!
				\brief Inserta un elemento en el montículo de mediciones de forma ordenada
				\note  Método virtual puro, a definir en la clase heredera
				\param medicion Objeto de la clase Medicion pasado como referencia constante
				\post  El montículo no está vacío
			*/
			virtual void insert( const ed::Medicion & medicion ) = 0;

			/*!
				\brief Elimina el último elemento del montículo
				\note  Método virtual puro, a definir en la clase heredera
				\pre   El montículo no está vacío
			*/
			virtual void remove() = 0;

		}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
