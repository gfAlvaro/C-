
	// Vertice.hpp
	// Fichero que contiene la definicion de la clase Vertice

//
#include <iostream>

// Para manejar los asertos
#include <cassert>

// 
#include <vector>

// Para la funcion abs
#include <cstdlib>

#include <fstream>

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales

namespace ed{

#ifndef VERTICE
#define VERTICE
class Vertice{

	private:
		// Atributos privados de la clase Vertice

		std::vector<float> _datos;
		int _etiqueta;

	public:
		// Métodos públicos de la clase Vertice

		Vertice( const float x = 0 , const float y = 0 ){

			this->setVertice( x , y );

			this->setEtiqueta(-1);

			#ifndef NDEBUG
			assert( abs( this->getX() - x ) < COTA_ERROR );
			assert( abs( this->getY() - y ) < COTA_ERROR );
			#endif
			}

		inline const float getX() const {

			return _datos[0];
			}

		inline const float getY() const {

			return _datos[1];
			}

		inline const int getEtiqueta() const {

			int valorDevuelto = _etiqueta;

			// post-c la etiqueta es única para este vertice en el grafo
			return valorDevuelto;
			}

		inline void setVertice( const float x , const float y ){

			_datos[0] = x;
			_datos[1] = y;

			#ifndef NDEBUG
			assert( abs( this->getX() - x ) < COTA_ERROR );
			assert( abs( this->getY() - y ) < COTA_ERROR );
			#endif			
			}		

		inline void setEtiqueta( const int etiqueta ){

			_etiqueta = etiqueta;
			}

		/*!
			\brief  sobrecarga del operador == de vertice
			\param  vertice
			\return bool
		*/
		inline const bool operator == ( const ed::Vertice & vertice ) const {

			return (  ( abs( this->getX() - vertice.getX() ) < COTA_ERROR ) and ( abs( this->getY() - vertice.getY() ) < COTA_ERROR )  );
			}

		/*!
			\brief  sobrecarga del operador = de vertice
			\param  vertice
			\return this
		*/
		inline ed::Vertice & operator = ( const ed::Vertice & vertice ) {

			this->setVertice( vertice.getX() , vertice.getY() );

			this->setEtiqueta( vertice.getEtiqueta() );

			return *this;
			}

	}; // Fin de la clase Vertice

// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
std::ostream & operator << ( std::ostream & stream , ed::Vertice const & objeto ){
	
	stream << "(" << objeto.getX() << ", " << objeto.getY() << ")";
	
	return stream;
}

// Sobrecarga del operador de entrada
std::istream & operator >> ( std::istream &stream , ed::Vertice & objeto ){

	std::string x, y;

	getline( stream , x , ' ' );
	getline( stream , y );

	objeto.setVertice(  atof( x.c_str() ) , atof( y.c_str() )  );

  return stream;
}

#endif

} // Fin del espacio de nombres ed


