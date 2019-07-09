
#include "Grafo.hpp"

const bool ed::Grafo::has( const ed::Vertice & vertice ) const {
		
	for( int i = 0 ; i < getNumeroVertices() ; i++ )
		if( vertice == _vertices[i] )
			return true;

	return false;
	}

const bool ed::Grafo::hasLadoActual() const {

	for ( int i = 0 ; i < getNumeroVertices() ; i++ )
		if( _matriz[_cursorVertice][i] != std::numeric_limits<double>::infinity() and ( _cursorVertice != i )  )
			return true;

	return false;
	}

const double ed::Grafo::ladoActual() const {

	#ifndef NDEBUG
	assert( this->hasLadoActual() );
	#endif

	double retVal = 0;

	for( int i = 0 ; i < getNumeroVertices() ; i++ )
		if( _matriz[_cursorVertice][i] != std::numeric_limits<double>::infinity() and ( _cursorVertice != i )  )
			retVal = _matriz[_cursorVertice][i];

	return retVal;
	}

void ed::Grafo::buscaVertice( const std::vector<float> & datos ){

	for( int i = 0 ; i < getNumeroVertices() ; i++ )
		if(  ( datos[i] == _vertices[i].getX() ) and ( datos[i+1] == _vertices[i].getY() )  )
			_cursorVertice = i;
	}



void ed::Grafo::buscaSiguienteVertice( const std::vector<float> & datos ){

	this->buscaVertice(datos);
	
	for( int i = _cursorVertice + 1 ; i < getNumeroVertices() ; i++ )
		if(  ( datos[i] == _vertices[i].getX() ) and ( datos[i+1] == _vertices[i].getY() )  )
			_cursorVertice = i;

	#ifndef NDEBUG
	if( this->hasVerticeActual() )
		assert(  ( this->verticeActual().getX() == datos[0] ) and ( this->verticeActual().getY() == datos[1] )  );
	#endif
	}

// borra el vertice actual y todos sus lados.
void ed::Grafo::borraVertice(){

	#ifndef NDEBUG
	assert( this->hasVerticeActual() );
	#endif

	// Borrar vértice
	_vertices.erase( _vertices.begin( ) + _cursorVertice );

	for( int k = _cursorVertice ; k <= _numVertices - 1 ; k++ )
		_vertices[k].setEtiqueta(k);

	// Borrar lados asociados al vértice eliminado
	for( int i = 0 ; i < getNumeroVertices() ; i++ ){
		if(  ( i != _cursorVertice )
		 and ( _matriz[_cursorVertice][i] != std::numeric_limits<double>::infinity() )  )
			// Cuando termine el bucle se borrará la fila entera con erase
			_numLados--;

		if(  ( this->esDirigido() ) and ( i != _cursorVertice )
		 and ( _matriz[i][_cursorVertice] != std::numeric_limits<double>::infinity() )  )
			_numLados--;
			
		_matriz[_cursorVertice].erase( _matriz[_cursorVertice].begin() + i);
		}

	_matriz.erase(_matriz.begin() + _cursorVertice);
	_numVertices = getNumeroVertices() - 1;

	_capacidad = _capacidad - 1 ;
	this->principioVertice();
	}

// borra el lado actual
void ed::Grafo::borraLado(){

	#ifndef NDEBUG
	assert( this->hasLadoActual() );
	#endif

	for( int i = 0 ; i < getNumeroVertices() ; i++ )
		if(  ( _matriz[_cursorVertice][i] != std::numeric_limits<double>::infinity() ) and ( i != _cursorVertice )  ){
			_matriz[_cursorVertice][i] = std::numeric_limits<double>::infinity();

			if( not this->esDirigido() )
				_matriz[i][_cursorVertice] = std::numeric_limits<double>::infinity();

			_numLados--;
			break;
			}
	}



