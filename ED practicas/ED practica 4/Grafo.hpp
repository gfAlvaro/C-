
	//! file\ Fichero que contiene la definición de la clase Grafo

#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include "Vertice.hpp"
//#include "Lado.hpp"

#ifndef GRAFO
#define GRAFO
namespace ed{

class Grafo{

	private:
		// Atributos privados de la clase Grafo

		bool _dirigido; //!<para controlar si es dirigido o no
		int _numVertices; //!<Numero de vertices
		int _numLados; //!<Numero de lados
		int _capacidad; //!<Capacidad del grafo
		std::vector< std::vector<double> > _matriz; //!<Matriz de adyacencia
		int _cursorVertice; //!<Cursor de vertices
		std::vector<ed::Vertice> _vertices; //!<Vector de vertices

	public:

		// Métodos públicos de la clase Grafo

		/*!
			\brief     Constructor
			\attention Se inicia a 0 y dirigido.
			\note      Se inicia la matriz de adyacencia.
			\note      constructor codificado en el fichero cpp
			\param     capacidad, esDirigido
		*/
		Grafo( const int capacidad = 0 , const bool esDirigido = true ){

			_capacidad = capacidad;
			_dirigido = esDirigido;
				
			_matriz.resize(capacidad);
			for( int i = 0 ; i < capacidad ; i++ ){

				_matriz[i].resize(capacidad);
				for ( int j = 0 ; j < capacidad ; j++ ){

					if ( i == j )
						_matriz[i][j] = 0.0; //Diagonal principal a 0
					else
						_matriz[i][j] = std::numeric_limits<double>::infinity(); //Resto a infinito
					}
				}

			_cursorVertice = -1;
			_numVertices = 0;
			_numLados = 0;
			}

		/*!
			\brief Devuelve el número de vértices.
		*/
		inline const int getNumeroVertices() const {

			return _numVertices;
			}

		/*!
			\brief Devuelve el número de lados.
		*/
		inline const int getNumeroLados() const {

			return _numLados;
			}

		/*!
			\brief Devuelve la capacidad.
		*/
		inline const int getCapacidad() const {

			return _capacidad;
			}

		/*!
			\brief Comprueba si el grafo está vacío
		*/
		inline const bool estaVacio() const {

			return ( _numVertices == 0 );
			}

		/*!
			\brief Comprueba si un grafo es dirigido o no.
			\note Devuelve true si el grafo es dirigido y false si no lo es (bool).
		*/
		inline const bool esDirigido() const {

			return _dirigido;
			}

		/*!
			\brief Devuelve true si distinto de infinito (adyacente)
			\note Usaremos los dos vértices indicicados.
			\param u, v
		*/
		inline const bool adyacente( const ed::Vertice & u , const ed::Vertice & v ) const {

			#ifndef NDEBUG
			assert( this->has(u) and this->has(v) );
			#endif

			// Si es distinto de infinito
			if( _matriz[u.getEtiqueta()][v.getEtiqueta()] != std::numeric_limits<double>::infinity() )
				return true;

			return false;
			}

		/*!
			\brief Devuelve el elemento de la matriz de adyacencia
			\note Usaremos los dos vértices indicicados.
			\param u, v
			\pre los vértices son adyacentes
		*/
		inline const double ladoAdyacente( const ed::Vertice & u , const ed::Vertice & v ) const {

			#ifndef NDEBUG
			assert(  this->adyacente( u , v )  );
			#endif

			return _matriz[u.getEtiqueta()][v.getEtiqueta()];
			}

		/*!
			\brief comprueba si un vertice está contenido en el grafo
			\note método codificado en el fichero cpp
		*/
		const bool has( const ed::Vertice & vertice ) const ;

		/*!
			\brief Comprueba si el cursor de vértices está en posición válida
			\note Devuelve true si está correcto y false si no
		*/
		inline const bool hasVerticeActual() const {

			if(  ( _cursorVertice >= 0 ) && ( _cursorVertice <= _numVertices )  )
				return true;
			return false;
			}

		/*!
			\brief Devuelve el vértice al que apunta el cursor de vértices.
			\pre hasVerticeActual() es true.

		*/
		inline const ed::Vertice verticeActual() const {

			#ifndef NDEBUG
			assert( this->hasVerticeActual() );
			#endif

			return _vertices[_cursorVertice];
			}

		/*!
			\brief Comprueba si el vertice actual tiene algún lado
			\attention Si el grafo es dirigido, comprueba si el vertice actual tiene un lado que sale de él
			\note  Método codificado en el fichero cpp
		*/
		const bool hasLadoActual() const;

		/*!
			\brief   Devuelve el índice del primer vértice al que apunta el lado actual
			\warning si el grafo es dirigido, sólo devolverá el primer lado que salga del vértice actual
			\pre     El vértice actual tiene un lado, si el grafo es dirigido el lado deberá salir de él
		*/
		const double ladoActual() const;

		/*!
			\brief Crea un grafo dirigido
			\note convierte la variable _dirigido privada a true.
		*/
		inline void creaDirigido(){

			_dirigido = true;
			}

		/*!
			\brief Crea un grafo no dirigido
			\note convierte la variable _dirigido privada a false.
			\pre Ninguna
			\post Ninguna
		*/
		inline void creaNoDirigido(){

			_dirigido = false;
			}

		/*!
			\brief Añade un vertice al grafo a partir de  datos
			\note Aumentamos el numero de vertices en 1
			\param datos tipo std::vector <float>
			\pre numVertices() < capacidad()

		*/
		inline void addVertice( const std::vector<float> datos ){// Vector de vertices, push_back?

			#ifndef NDEBUG
			assert( this->getNumeroVertices() < this->getCapacidad() );
			#endif

			ed::Vertice v( datos[0] , datos[1] );

			v.setEtiqueta(_numVertices);
			_vertices.push_back(v);
			_numVertices++;

			/*
			this->principioVertice();
			for( int i = 0 ; i < this->getNumeroVertices() ; i++ ){

				if(  not ( v == this->verticeActual() )  ){
					double peso = sqrt(  pow( v.getX() - this->verticeActual().getX() , 2 ) + pow( v.getY() - this->verticeActual().getY() , 2 )  );
					addLado( peso, v, this->verticeActual() );
					}

				this->siguienteVertice();
				}
			*/

			#ifndef NDEBUG
			assert(  this->hasVerticeActual()
				 and ( this->verticeActual().getX() == datos[0] )
				 and ( this->verticeActual().getY() == datos[1] )  );
			#endif
			}

		/*!
			\brief Añade un lado al grafo a partir de sus dos vértices y su peso.
			\note Esto se reflejará sólo en la matriz de adyacencia
			\param peso, primero, segundo
			\pre primero y segundo pertenecen al grafo.
		*/
		void addLado( const double peso , const ed::Vertice & primero , const ed::Vertice & segundo ){

			#ifndef NDEBUG
			assert( this->has(primero) and this->has(segundo) );
			#endif

			int v1 = primero.getEtiqueta();
			int v2 = segundo.getEtiqueta();
			_cursorVertice = v1;

			if( hasVerticeActual() ){

				_cursorVertice = v2;

				if( hasVerticeActual() ){

					if( not esDirigido() ){

						_matriz[v1][v2] = peso;
						_matriz[v2][v1] = peso;
						}
					else
						_matriz[v1][v2] = peso;

					_numLados++;
					}
				}

			#ifndef NDEBUG
			if( this->esDirigido() )
				assert( _matriz[v1][v2] == peso );
			else
				assert(	 ( _matriz[v1][v2] == peso ) and ( _matriz[v2][v1] == peso )  );
			#endif
			}

		/*!
			\brief borra el vertice actual y todos sus lados
			\note  Método codificado en el fichero cpp
			\pre   El cursor apunta a un vértice válido
		*/
		void borraVertice();

		/*!
			\brief borra el lado actual
			\note  Método codificado en el fichero cpp
			\pre   existe un lado en el vertice actual
		*/
		void borraLado();

		// Modificadores

		/*!
			\brief Busca un vertice a partir de sus datos, colocando el cursor en dicho vértice
			\note  método codificado en el fichero cpp
			\param datos tipo vector de float, pasado como referencia constante
		*/
		void buscaVertice( const std::vector<float> & datos );

		/*!
			\brief busca el siguiente vertice a partir de sus datos
			\note  método codificado en el fichero cpp
			\post  hasVerticeActual() implica VerticeActual().getX() = datos[0] y VerticeActual().getY() = datos[1]
		*/
		void buscaSiguienteVertice( const std::vector<float> & datos );

		/*!
			\brief Lleva el cursor a un vertice a partir de dicho vertice
			\param v
			\pre v pertenece al grafo
		*/
		inline void goTo( const ed::Vertice & v ){

			#ifndef NDEBUG
			assert( this->has(v) );
			#endif
			
			_cursorVertice = v.getEtiqueta();
			}

			/*!
				\brief Lleva el cursor a un vértice a partir de la posicion de dicho vertice
				\param idx que es un int y buscaremos el vértice que tenga la misma etiqueta.
				\pre 0 <= id < getNumeroVertices()
				\post Ninguna
			*/
			void goTo( const int & id ){

				#ifndef NDEBUG
				assert(  0 <= ( id < getNumeroVertices() )  );
				#endif

				_cursorVertice = id;
				}

		/*!
			\brief Lleva el cursor al primer vertice
		*/
		inline void principioVertice(){

			if( not this->estaVacio() )
				_cursorVertice = 0;
			else
				_cursorVertice = -1;

			#ifndef NDEBUG
			if ( this->estaVacio() )
				assert ( not this->hasVerticeActual() );
			#endif
			}

		/*!
			\brief Avanza el cursor al siguiente vertice.
		*/
		inline void siguienteVertice(){

			_cursorVertice++;
			}

		/*!
			\brief Comprueba si el cursor ha sobrepasado su última posicion válida
			\note Si el cursor es la ultima posicion del vértice.
		*/
		inline const bool afterEndVertice() const {

			if ( _cursorVertice == this->getNumeroVertices() )
				return true;
			return false;
			}

	}; // Fin de la clase Grafo


} // Fin del espacio de nombres ed
#endif

