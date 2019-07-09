/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  Álvaro García Fuentes
	\date   08-04-2018
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

namespace ed{

ed::ListaDoblementeEnlazadaOrdenadaMunicipios::~ListaDoblementeEnlazadaOrdenadaMunicipios(){

	this->removeAll();

	#ifndef NDEBUG
	assert(this->isEmpty());	
	#endif
	}

int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const {

	int cuenta = 0;

	if(not this->isEmpty()){

		ed::NodoDoblementeEnlazadoMunicipio *current;

		current = this->getHead();

		cuenta = cuenta + 1;

		while(current->getNext() != NULL ){
			current = current->getNext();
			cuenta = cuenta + 1;
			}
		}

	return cuenta;
	}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){

	#ifndef NDEBUG
	assert(not this->isEmpty());
	#endif

	while(not this->isLastItem()){
	
		this->setCurrent(this->getCurrent()->getNext());
		}

	#ifndef NDEBUG
	assert(this->isLastItem());
	#endif
	}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const & item){

	bool encontrado;

	if(not this->isEmpty()){

		this->gotoHead();

		while( (this->getCurrentItem() < item) and (not this->isLastItem()) ){

			this->gotoNext();
			}

		if(this->getCurrentItem() == item)
			encontrado = true;
		else
			encontrado = false;
		}
	else
		encontrado = false;

	#ifndef NDEBUG
	if(encontrado)
		assert( this->getCurrentItem() == item );
	else if(not this->isEmpty())
		assert( (not (this->getCurrentItem() < item)) or (this->isLastItem()) );
	#endif

	return encontrado;
	}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const & item) {
	
	#ifndef NDEBUG
	assert(not this->find(item));
	#endif

	// Para comprobar luego las postcondiciones
	int num = this->nItems();

	ed::NodoDoblementeEnlazadoMunicipio *Nodo;
	Nodo = new ed::NodoDoblementeEnlazadoMunicipio(item, NULL, NULL);

	// Si la lista está vacía
	if ( this->nItems() == 0 ){
		this->setHead(Nodo);
		this->gotoHead();
		}

	// Si la lista sólo tiene un elemento
	else if( this->nItems() == 1 ){

		if(this->getCurrent()->getItem() < Nodo->getItem()){

			// Insertar por detrás
			Nodo->setPrevious(this->getCurrent());

			this->getCurrent()->setNext(Nodo);

			this->gotoNext();
			}
		else{
			// Insertar por delante, quedando el nuevo nodo como cabeza de la lista
			Nodo->setNext(this->getCurrent());

			this->getCurrent()->setPrevious(Nodo);

			this->setHead(Nodo);
			this->gotoHead();
			}
		}

	// Si la lista tiene más de un elemento
	else if(this->nItems() > 1){
		if(this->getCurrentItem() < Nodo->getItem()){

			// Insertar por detrás, aquí estaríamos siempre en el último nodo
			Nodo->setPrevious(this->getCurrent());

			this->getCurrent()->setNext(Nodo);

			this->gotoNext();
			}
		else{
			// Insertar por delante, pudiendo quedar en ocasiones el nuevo nodo como cabeza de lista
			Nodo->setNext(this->getCurrent());
			Nodo->setPrevious(this->getCurrent()->getPrevious());

			this->setCurrent(Nodo);

			this->getCurrent()->getNext()->setPrevious(this->getCurrent());

			if( NULL != getCurrent()->getPrevious() )
				this->getCurrent()->getPrevious()->setNext(this->getCurrent());

				// Si el elemento insertado es ahora el primero de la lista
			if(NULL == this->getCurrent()->getPrevious())
				setHead(this->getCurrent());
			}
		}

	#ifndef NDEBUG
	assert( this->nItems() == (num + 1) );
	assert( item == this->getCurrentItem() );
	#endif
	}			

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove() {

	#ifndef NDEBUG
	assert(not this->isEmpty());
	#endif

// Variables con datos referentes a la lista original para luego comprobar las postcondiciones

	int oldNum = this->nItems();
	bool oldIsFirst = this->isFirstItem();
	bool oldIsLast = this->isLastItem();

	ed::NodoDoblementeEnlazadoMunicipio *oldPrevious = this->getCurrent()->getPrevious();
	ed::NodoDoblementeEnlazadoMunicipio *oldNext = this->getCurrent()->getNext();

// Se borra el nodo actual de la lista

	ed::NodoDoblementeEnlazadoMunicipio *nodoBorrar;

	nodoBorrar = this->getCurrent();

	// Si el cursor no está en el primer ni último elemento.
	if((not this->isFirstItem()) and (not this->isLastItem())){

		this->getCurrent()->getNext()->setPrevious( this->getCurrent()->getPrevious() );
		this->getCurrent()->getPrevious()->setNext( this->getCurrent()->getNext() );
		this->gotoNext();
		}
	
	// Si el cursor está en el último elemento y hay más de uno.
	else if((not this->isFirstItem()) and this->isLastItem()){

		this->getCurrent()->getPrevious()->setNext(NULL);
		this->gotoPrevious();
		}

	// Si el cursor está en el primer elemento y hay más de uno.
	else if(this->isFirstItem() and (not this->isLastItem())){

		this->getCurrent()->getNext()->setPrevious(NULL);
		this->gotoNext();
		this->setHead(this->getCurrent());
		}

	// Si la lista sólo tiene un elemento.
	else{
		this->setHead(NULL);
		this->setCurrent(NULL);
		}
	// Se libera la memoria del nodo borrado.
	delete nodoBorrar;
	nodoBorrar=NULL;

// Se comprueban las postconcidiones usando las variables de la lista original

	#ifndef NDEBUG
	assert( this->nItems() == (oldNum - 1) );
	if( not (oldIsFirst or oldIsLast) )
		assert( (oldPrevious->getItem() == this->getPreviousItem())
		    and (oldNext->getItem() == this->getCurrentItem()) );
	if(oldIsLast)
		assert(this->isEmpty()
		        or ( (oldPrevious->getItem() == this->getCurrentItem()) and this->isLastItem() ) );
	if(oldIsFirst)
		assert( this->isEmpty()
			or ( (oldNext->getItem() == this->getCurrentItem()) and this->isFirstItem() ) );
	#endif
	}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll(){

	while(not this->isEmpty())
		this->remove();

	#ifndef NDEBUG
	assert(this->isEmpty());
	#endif
	}

}// Fin de namespace ed
