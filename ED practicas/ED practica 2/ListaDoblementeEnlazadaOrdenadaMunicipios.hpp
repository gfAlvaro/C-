/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author Álvaro García Fuentes
	\date   08-04-2018
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/ 
namespace ed {
 
/*!	
  \class ListaDoblementeEnlazadaOrdenadaMunicipios 
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente 
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios: public ed::ListaOrdenadaMunicipiosInterfaz
  {
	//! \name  Atributos y métodos privados 

	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista

    // \name Observadores privados 

    inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const
	{
		return this->_head;
	}

	inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{
		return this->_current;
	}

    //! \name Modificadores privados 

	inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head) 
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getHead() == head);
		#endif //NDEBUG		
	}

    inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current) 
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getCurrent() == current);
		#endif //NDEBUG		
	}


	//! \name  Métodos públicos

	public:

	//! \name Constructores

    /*! 
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios()
    {
		this->setHead(NULL);
		this->setCurrent(NULL);

		#ifndef NDEBUG
		assert(this->isEmpty());
		#endif
	}
	
  
	//! \name Destructor 

    /*! 
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
	*/
	~ListaDoblementeEnlazadaOrdenadaMunicipios ();


	//! \name Observadores públicos 

	/*!
		\brief  Comprueba si la lista está vacía
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si la lista está vacía; false, en caso contrario
    */
	inline bool isEmpty() const
	{
		return (NULL == this->getHead() );
	}

    /*!
        \brief  Devuelve el número de elementos o ítems de la lista
	\note   Función codificada en el fichero .cpp
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return Número entero que representa el número de elementos o ítems de la lista
    */
	int nItems() const;

    /*!
		\brief  Comprueba si el cursor está en el primer Municipio
		\note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía
		\return Verdadero, si el cursor está situado en la cabeza; falso en caso contrario
	*/
 	inline bool isFirstItem() const {

		#ifndef NDEBUG
		assert(not this->isEmpty());
		#endif

		return (NULL == this->getCurrent()->getPrevious());
		}


    /*!
		\brief  Comprueba si el cursor está en el último Municipio
		\note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía
		\return true, si el cursor está situado al final de la lista; false, en caso contrario
    */
	inline bool isLastItem() const {

		#ifndef NDEBUG
		assert(not this->isEmpty());
		#endif

		return (NULL == this->getCurrent()->getNext());
		}

    /*!
		\brief  Devuelve el Municipio situado en el campo informativo indicado por el cursor
		\note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía
		\return Una referencia constante al municipio indicado por el cursor
    */
	inline ed::Municipio const & getCurrentItem() const {

		#ifndef NDEBUG
		assert(not this->isEmpty());
		#endif

		return this->getCurrent()->getItem();
		}

    /*!
		\brief  Devuelve el Municipio situado en el campo informativo anterior
		\note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía 
		\pre    El cursor no está situado en el primer nodo
		\return Una referencia al municipio situado en el nodo previo al indicado por el cursor
    */
	inline  ed::Municipio const & getPreviousItem() const {

		#ifndef NDEBUG
		assert(not this->isEmpty());
		assert(not this->isFirstItem());
		#endif

		return this->getCurrent()->getPrevious()->getItem();
		}


    /*!
		\brief  Devuelve el Municipio situado en el campo informativo posterior
		\note   Función inline
        \note   Función de tipo "const": no puede modificar al objeto actual
		\pre    La lista no está vacía 
		\pre 	El cursor no está situado en el último nodo
        \return Una referencia al municipio situado en el nodo siguiente al indicado por el cursor
    */
	inline ed::Municipio const & getNextItem() const{

		#ifndef NDEBUG
		assert(not this->isEmpty());
		assert(not this->isLastItem());
		#endif

		return this->getCurrent()->getNext()->getItem();
		}	

    //! \name Modificadores públicos

    /*!
		\brief  Coloca el cursor en la primera posición de la lista
		\note   Función inline
        \pre    La lista no está vacía
        \post   El ítem actual es el primero: isFirstItem() == true
		\return void
		\sa		gotoLast(), gotoPrevious(), gotoNext()
      */
	inline void gotoHead(){

		#ifndef NDEBUG
		assert(not this->isEmpty());
		#endif

		this->setCurrent(_head);

		#ifndef NDEBUG
		assert(this->isFirstItem());
		#endif
		}

      /*!
		\brief  Coloca el cursor en la última posición de la lista
		\note   Función codificada en el fichero .cpp
        \pre    La lista no está vacía
        \post   El ítem actual es el último:  isLastItem() == true
		\return void
		\sa		gotoHead(), gotoPrevious(), gotoNext()
      */
      void gotoLast();


      /*!
		\brief  Coloca el cursor en la posición anterior de la lista
		\note   Función inline
		\pre    La lista no está vacía
		\pre    El ítem actual no es el primero: isFirstItem() == false
		\post   Ninguna
		\return void
		\sa		gotoHead(), gotoLast(), gotoNext()
      */
	inline void gotoPrevious() {

	#ifndef NDEBUG
	assert(not this->isEmpty());
	assert(not this->isFirstItem());
	#endif

	this->setCurrent(this->getCurrent()->getPrevious());
	}

	/*!
		\brief  Coloca el cursor en la posición siguiente de la lista
		\note   Función inline
        \pre    La lista no está vacía
        \pre    El ítem actual no es el último: isLastItem() == false
		\post   Ninguna
		\return void
		\sa		gotoHead(), gotoLast(), gotoPrevious()
	*/
      inline void gotoNext() {

	#ifndef NDEBUG
	assert(not this->isEmpty());
	assert(not this->isLastItem());
	#endif

	this->setCurrent(this->getCurrent()->getNext());
	}	

	/*!
		\brief  Coloca el cursor en el nodo que contiene al municipio en su campo informativo, si existe;
		\note   Función codificada en el fichero .cpp
		\param  item: municipio buscado; referencia constante de la clase Municipio
 		\post   retVal==true implica que getCurrentItem() == item
    \post   retVal==false implica que getCurrentItem > item o isLastItem() == true
		\return true, si el municipio está en la lista; false, en caso contrario
    */
	bool find(ed::Municipio const & item);

	/*!
		\brief Inserta un Municipio de forma ordenada por apellidos y nombre
		\note  Función codificada en fichero .cpp
		\param item: objeto de la clase Municipio que va a ser insertado; referencia constante de la clase Municipio
		\pre   find(item) == false
 		\post  getCurrentItem() == item
		\sa    remove() 
    */
	void insert(ed::Municipio const & item);
			

	/*!
		\brief Borra el municipio indicado por el cursor
		\note  Función codificada en fichero .cpp
		\pre   La lista no está vacía: isEmpty()== false
		\post  El número de municipios se reduce en uno
           \n nItems()==old.nItems()-1
    \post  Si old.isFirstItem()==falso y  old.isLastItem()==falso
				   entonces old.getPreviousItem()== getPreviousItem() y old.getNextItem()==getCurrentItem()
		\post  Si old.lastItem()==verdadero entonces
		       isEmpty()==verdadero  
           o old.getPreviousItem()==getCurrentItem() y isLastItem()==verdadero
    \post  Si old.isFirstItem()==verdadero entonces
           isEmpty()==verdadero o old.getNextItem()==getCurrentItem() y isFirstItem()==verdadero
		\sa    insert()
     */
	void remove();
	/*!
		\brief Borra todos los nodos de la lista
		\note  Función codificada en el fichero .cpp
		\Post  isEmpty() == verdadero
		\sa    remove()
	*/
	void removeAll();


}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
 
} //namespace ed
 
#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
