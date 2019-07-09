/*! 
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica 
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

#include <cstdlib>
#include <cmath>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion 
class Medicion{

	//! \name Atributos privados de la clase Medicion
	private: 

		ed::Fecha _fecha;
		float _precipitacionDeLluvia;

	//! \name Funciones o métodos públicos de la clase Medicion
	public:

	//! \name Constructores de la clase Medicion

		/*!
			\brief   Crea un objeto de la clase Medicion
			\note    Método inline
			\warning Función sobrecargada
			\param   fecha Objeto de clase fecha con valores por defecto (1, 1, 1,) pasado como referencia constante
			\param   precipitacion Variable de tipo const float inicializada a 0.0
			\post    La fecha de la Medicion es igual a fecha
			\post    La precipitación de la Medicion es igual a precipitacion
			\sa      Medicion(ed::Medicion const & medicion)
		*/
		inline Medicion( ed::Fecha const & fecha = ed::Fecha(1,1,1) , const float precipitacion = 0.0 ){

			this->setFecha( fecha );
			this->setPrecipitacion( precipitacion );
	
			#ifndef NDEBUG
			assert( this->getFecha() == fecha );
			assert( abs(this->getPrecipitacion() - precipitacion) < COTA_ERROR );
			#endif
			}

		/*!
			\brief   Crea un objeto de la clase Medicion a partir otro objeto de la misma clase
			\note    Método inline
			\warning Función sobrecargada
			\param   medicion Objeto de clase Medicion pasado como referencia constante
			\post    La fecha de la Medicion es igual a fecha
			\post    La precipitación de la Medicion es igual a precipitacion
			\sa      Medicion( ed::Fecha const & fecha = ed::Fecha(1,1,1) , const float precipitacion = 0.0 )
		*/
		inline Medicion( ed::Medicion const & medicion ){

			this->setFecha( medicion.getFecha() );
			this->setPrecipitacion( medicion.getPrecipitacion() );

			#ifndef NDEBUG
			assert( this->getFecha() == medicion.getFecha() );
			assert( abs( getPrecipitacion() - medicion.getPrecipitacion() ) < COTA_ERROR );
			#endif

			}

		//! \name Observadores: funciones de consulta de la clase Medicion
	
		/*!
			\brief  muestra la fecha de la medición
			\note   método inline
			\note   método const
			\return objeto de clase fecha, devuelto como referencia constante
			\sa     setFecha(), getPrecipitacion(), setPrecipitacion()
		*/
		inline ed::Fecha const & getFecha() const{

			return _fecha;
			}

		/*!
			\brief  muestra la cantidad de precipitación de la medición
			\note   método inline
			\note   método const
			\return variable de tipo const float
			\sa     getFecha(), setFecha(), setPrecipitacion()
		*/
		inline const float getPrecipitacion() const{

			return _precipitacionDeLluvia;
			}


		//! \name Funciones de modificación de la clase Medicion
	
		/*!
			\brief modifica la fecha de la medición
			\note  método inline
			\param fecha Objeto de clase fecha, pasado como referencia constante
			\post  la fecha de la medición es igual a fecha
			\sa    getFecha(), getPrecipitacion(), setPrecipitacion()
		*/
		inline void setFecha( ed::Fecha const & fecha ){
	
			_fecha = fecha;
	
			#ifndef NDEBUG
			assert( this->getFecha() == fecha );
			#endif
			}
	
		/*!
			\brief modifica la cantidad de precipitación de la medición
			\note  método inline
			\param precipitacion Variable de tipo const float
			\pre   precipitacion es mayor o igual que 0.0
			\post  la precipitacion de la medicion es igual a precipitacion
			\sa    getFecha(), setFecha(), getPrecipitacion()
		*/
		inline void setPrecipitacion( const float precipitacion ){
	
			#ifndef NDEBUG
			assert(precipitacion >= 0.0);
			#endif
	
			_precipitacionDeLluvia = precipitacion;
	
			#ifndef NDEBUG
			assert( abs(this->getPrecipitacion() - precipitacion) < COTA_ERROR );
			#endif
			}
	
		//! \name Operadores
   	
		/*!
			\brief  operador de sobrecarga que compara si dos mediciones son iguales
			\note   método inline
			\note   método const
			\param  medicion Objeto de clase Medicion pasado como referencia constante
			\return variable de tipo bool
			\post   valorDevuelto es true si la fecha actual es igual a la fecha de medicion, y false en caso contrario
			\sa     operator = ( ed::Medicion const & Medicion )
		*/
		inline bool operator == ( ed::Medicion const & medicion ) const{

			bool valorDevuelto = ( this->getFecha() == medicion.getFecha() );

			#ifndef NDEBUG
			assert( valorDevuelto == (this->getFecha() == medicion.getFecha()) );
			#endif

			return valorDevuelto;
			}

		/*!
			\brief  operador de sobrecarga iguala dos mediciones
			\note   método inline
			\param  medicion Objeto de clase Medicion pasado como referencia constante
			\return objeto de clase Fecha devuelto como referencia constante
			\post   la fecha actual es igual a la fecha de medicion
			\post   la precipitacion actual es igual a la precipitacion de la medicion
			\sa     operator == ( ed::Medicion const & medicion )
		*/
		inline const ed::Fecha & operator = ( ed::Medicion const & medicion ){
	
			this->setFecha( medicion.getFecha() );
			this->setPrecipitacion( medicion.getPrecipitacion() );
	
			#ifndef NDEBUG
			assert( this->getFecha() == medicion.getFecha() );
			assert( this->getPrecipitacion() == getPrecipitacion() );
			#endif
	
			return this->getFecha();
			}
	
		//! \name Funciones de lectura y escritura de la clase Medicion

		/*!
			\brief Lee los datos de la medicion desde teclado
			\note  Método inline
			\sa    escribirMedicion()
		*/
		inline void leerMedicion(){

			float precipitacion;
			int agno, mes, dia;

			std::cout << "Introduzca la fecha de la medición." << std::endl;
			std::cout << "dia: ";
			std::cin >> dia;
			std::cout << "mes: ";
			std::cin >> mes;
			std::cout << "año: ";
			std::cin >> agno;
			std::cout << std::endl;
			std::cout << "Introduzca la cantidad de precipitaciones de la medición." << std::endl;
			std::cin >> precipitacion;
	
			ed::Fecha fecha(dia, mes, agno);
			this->setFecha( fecha );
			this->setPrecipitacion( precipitacion );
			}

		/*!
			\brief Escribe por pantalla los datos de la medicion con el formato (dia-mes-agno precipitacion)
			\note  Método inline
			\sa    leerMedicion()
		*/
		inline void escribirMedicion() const {

			std::cout << this->getFecha().getDia() << "-" << this->getFecha().getMes() << "-" << this->getFecha().getAgno() << " " << this->getPrecipitacion() << std::endl;
			}


	}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

/*!
	\brief  Sobrecarga del operador de salida
	\note   Método codificado en el fichero cpp
	\note   Función amiga de la clase Medicion
	\param  stream Variable de tipo ostream pasada como referencia
	\param  medicion Objeto de la clase Medicion pasado como referencia constante
	\return variable ostream devuelta como referencia
	\sa     operator >> (istream & stream, Medicion & medicion)
*/
ostream & operator << ( ostream & stream, Medicion const & medicion );

/*!
	\brief  Sobrecarga del operador de entrada
	\note   Método codificado en el fichero cpp
	\note   Función amiga de la clase Medicion
	\param  stream Variable de tipo istream pasada como referencia
	\param  medicion Objeto de la clase Medicion pasado como referencia
	\return variable istream devuelta como referencia
	\sa     operator << (ostream & stream, Medicion const & medicion)
*/
istream & operator >> ( istream & stream, Medicion & medicion );

} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
