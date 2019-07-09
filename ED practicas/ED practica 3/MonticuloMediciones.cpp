/*!
	\file   MonticuloMediciones.cpp
	\brief  Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author Álvaro García Fuentes
	\date   03-05-2018
*/

//#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones

// El elemento indicado por el índice es subido en el montículo hasta que se verifica la ordenación de máximos.
void ed::MonticuloMediciones::shiftUp( const int i ){

	unsigned int tam = this->size();

	#ifndef NDEBUG
	assert(  ( i > 0 ) and ( (unsigned) i < tam )  );
	#endif

	int k = i;

	while( k > 0 )
		if( this->getElement(k).getPrecipitacion() > this->getElement(this->getParent(k)).getPrecipitacion() ){

			ed::Medicion Aux( this->getElement(k) );
			this->setElement( k, this->getElement(this->getParent(k)) );
			this->setElement( this->getParent(k) , Aux );

			k = this->getParent(k);
			}
		else
			break;

	#ifndef NDEBUG
	if( not ( k == 0 ) )
		assert( this->getElement(k).getPrecipitacion() <= this->getElement(this->getParent(k)).getPrecipitacion() );

	unsigned int izq = this->getLeftChild(k);
	if( izq < tam )
		assert( this->getElement(k).getPrecipitacion() >= this->getElement(izq).getPrecipitacion() );

	unsigned int der = this->getRightChild(k);
	if( der < tam )
		assert( this->getElement(k).getPrecipitacion() >= this->getElement(der).getPrecipitacion() );
	#endif
	}

// El elemento indicado por el índice es bajado en el montículo hasta que se verifica la ordenación de máximos.
void ed::MonticuloMediciones::shiftDown( const int i ){

	unsigned int tam = this->size();

	#ifndef NDEBUG
	assert( (i >= 0 ) and ((unsigned) i < tam ) );
	#endif

	unsigned int k = i, izquierdo, derecho;

	while( k < tam ){

		izquierdo = this->getLeftChild(k);
		derecho = this->getRightChild(k);

		// Selecciona por qué hijo se va a bajar
		if( izquierdo < tam ){

			if(  this->getElement(k).getPrecipitacion() <= this->getElement(izquierdo).getPrecipitacion()  )

				k = izquierdo;

			if(  ( derecho < tam )
			 and ( this->getElement(k).getPrecipitacion() <= this->getElement(derecho).getPrecipitacion() )  )

				k = derecho;
	
			// Intercambia los valores del hijo elegido con el padre
			ed::Medicion Aux = this->getElement(this->getParent(k));
			setElement( this->getParent(k) , this->getElement(k) );
			setElement( k , Aux );
			}

		else
			break;
		}

	#ifndef NDEBUG
	if(  not ( this->top() == this->getElement(k) )  )
		assert( this->getElement(k).getPrecipitacion() <= this->getElement(this->getParent(k)).getPrecipitacion() );

	unsigned int izq = this->getLeftChild(k);
	if(  ( izq > 0 ) and ( izq < tam )  )
		assert( this->getElement(k).getPrecipitacion() >= this->getElement(izq).getPrecipitacion() );

	unsigned int der = this->getRightChild(k);
	if(  ( der > 0 ) and ( der < tam )  )
		assert( this->getElement(k).getPrecipitacion() >= this->getElement(der).getPrecipitacion() );
	#endif
	}

// Se comprueba si la medición está incluida en el montículo.
bool ed::MonticuloMediciones::has( ed::Medicion const & medicion ) const {

	bool valorDevuelto;

	unsigned int k, tam = this->size();

	float precipitacion = medicion.getPrecipitacion();
	ed::Fecha fecha = medicion.getFecha();

	for(  k = 0 ; k < tam ; k++ )

		// Compara el elemento actual con el parámetro de entrada
		if(  ( fecha == this->getElement(k).getFecha() )
		 and ( precipitacion == this->getElement(k).getPrecipitacion() )  ){

			valorDevuelto = true;
			break;
			}

	if( k == tam )
		valorDevuelto = false;

	return valorDevuelto;
	}

////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

// Inserta una nueva medición en el montículo
void ed::MonticuloMediciones::insert( ed::Medicion const & medicion ){

	//añadir al vector
	_vectorMediciones.push_back(medicion);

	//flotar
	unsigned int i = this->size() - 1;
	if (i > 0)
		this->shiftUp(i);

	#ifndef NDEBUG
	assert( not this->isEmpty() );
	assert( this->has(medicion) );
	#endif
	}

// Borra todas la mediciones del montículo
void ed::MonticuloMediciones::removeAll(){

	while( not this->isEmpty() )
		this->remove();

	#ifndef NDEBUG
	assert( this->isEmpty() );
	#endif
	}

// Escribe las mediciones tal y como están almacenadas en el vector que representa el montículo.
void ed::MonticuloMediciones::print() const {

	int i, tam = this->size();

	for( i = 0 ; i < tam ; i++ )
		this->getElement(i).escribirMedicion();
	}



