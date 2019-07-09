/*!
	\file   MonticuloMediciones.hpp
	\brief  Se define el TAD MonticuloMediciones
	\author Álvaro García Fuentes
	\date   03-05-2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"


namespace ed{


class MonticuloMediciones : public MonticuloMedicionesInterfaz{

	private:

		//! \name Atributos privados de la clase MonticuloMediciones

		std::vector<ed::Medicion> _vectorMediciones;


		//! \name Métodos privados de la clase MonticuloMediciones

		/*!
			\brief  Consulta un elemento del montículo de mediciones
			\note   Método const
			\note   Método inline
			\param  i Variable de tipo const int
			\return Objeto de la clase Medicion devuelto como referencia constante
			\pre    i es mayor o igual que 0, y es menor que el tamaño del montículo
			\sa     setElement(), modify()

		*/
		inline const ed::Medicion & getElement( const int i ) const {

			#ifndef NDEBUG
			assert( (i >= 0) and ( (unsigned) i < this->size()) );
			#endif

			return _vectorMediciones[i];
			}

		/*!
			\brief   Modifica un elemento del montículo de mediciones
			\note    Método inline
			\warning Esta función puede romper el orden de máximos del montículo
			\param   i Variable de tipo const int
			\param   medicion Objeto de la clase Medicion pasado como referencia constante
			\pre     i es mayor o igual que 0, y es menor que el tamaño del montículo
			\post    el elemento actual del montículo es igual a medicion
			\sa      getElement(), modify(), shiftDown()
		*/
		inline void setElement( const int i, const ed::Medicion & medicion ){

			#ifndef NDEBUG
			assert( (i >= 0) and ( (unsigned) i < this->size()) );
			#endif

			_vectorMediciones[i] = medicion ;

			#ifndef NDEBUG
			assert( this->getElement(i) == medicion );
			#endif
			}

		/*!
			\brief  Devuelve el índice del hijo izquierdo del indice recibido
			\note   Método inline
			\note   Método const
			\param  i Variable de tipo const int
			\return variable de tipo const int
			\pre    i es mayor o igual que 0
			\post   valorDevuelto es igual a 2 * i + 1
			\sa     getRightChild(), getParent()
		*/
		inline const int getLeftChild( const int i ) const {

			#ifndef NDEBUG
			assert( i >= 0 );
			#endif

			int valorDevuelto = 2 * i + 1;

			#ifndef NDEBUG
			assert( valorDevuelto == (2 * i + 1) );
			#endif

			return valorDevuelto;
			}

		/*!
			\brief  Devuelve el índice del hijo derecho del indice recibido
			\note   Método inline
			\note   Método const
			\param  i Variable de tipo const int
			\return variable de tipo const int
			\pre    i es mayor o igual que 0
			\post   valorDevuelto es igual a 2 * i + 2
			\sa     getLeftChild(), getParent()
		*/
		inline const int getRightChild( const int i ) const {

			#ifndef NDEBUG
			assert( i >= 0 );
			#endif

			int valorDevuelto = 2 * i + 2;

			#ifndef NDEBUG
			assert( valorDevuelto == (2 * i + 2) );
			#endif

			return valorDevuelto;
			}

		/*!
			\brief  Devuelve el índice del padre del índice recibido
			\note   Método inline
			\note   Método const
			\param  i Variable de tipo const int
			\return Variable de tipo const int
			\pre    i es mayor o igual que 1
			\post   valorDevuelto es igual a (i - 1) / 2
			\sa     getLeftChild(), getRightChild()
		*/
		inline const int getParent( const int i ) const {

			#ifndef NDEBUG
			assert( i >= 1 );
			#endif

			int valorDevuelto = (i - 1) / 2 ;

			#ifndef NDEBUG
			assert( valorDevuelto == ((i - 1) / 2) );
			#endif

			return valorDevuelto;
			}

		/*!
			\brief El elemento del índice es subido en el montículo hasta verificar la ordenación de máximos
			\note  Método codificado en el fichero cpp
			\param i Variable de tipo const int
			\pre   i es mayor que 0 y menor que el tamaño del montículo
			\post  Si no es la cima, el elemento actual es menor o igual que su padre
			\post  Si tiene hijo izquierdo, el elemento actual es mayor o igual que él
			\post  Si tiene hijo derecho, el elemento actual es mayor o igual que él
			\sa    shiftDown()
		*/
		void shiftUp( const int i );

		/*!
			\brief El elemento del índice es bajado en el montículo hasta verificar la ordenación de máximos
			\note  Método codificado en el fichero cpp
			\param i Variable de tipo const int
			\pre   i es mayor o igual que 0 y menor que el tamaño del montículo
			\post  Si no es la cima, el elemento actual es menor o igual que su padre
			\post  Si tiene hijo izquierdo, el elemento actual es mayor o igual que él
			\post  Si tiene hijo derecho, el elemento actual es mayor o igual que él
			\sa    shiftUp()
		*/
		void shiftDown( const int i );

		/*!
			\brief Se comprueba si la medición está incluida en el montículo.
			\note  Método codificado en el fichero cpp
			\note  Método const
			\param medicion Objeto de la clase Medicion pasado como referencia constante
			\return variable de tipo bool
		*/
		bool has( ed::Medicion const & medicion ) const;


	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

		/*!
			\brief crea un montículo de medciones vacío
			\note  Método inline
			\post  El montículo de mediciones está vacío
		*/
		inline MonticuloMediciones(){

			this->removeAll();

			#ifndef NDEBUG
			assert( this->isEmpty() );
			#endif
			}

		//! \name Observadores

		/*!
			\brief  Comprueba si el montículo está vacío
			\note   Método const
			\note   Método heredado de la clase interfaz
			\return variable de tipo bool
			\post   ValorDEvuelto es true si el tamaño del montículo es igual a 0, y false en caso contrario
			\sa     size()
		*/
		const bool isEmpty() const{


			bool valorDevuelto = (this->size() == 0);

			#ifndef NDEBUG
			assert( valorDevuelto == (this->size() == 0) );
			#endif

			return valorDevuelto;
			}

		/*!
			\brief Devuelve el número de mediciones del montículo
			\note  Método inline
			\note  Método const
			\return Variable de tipo const unsigned int
		*/
		inline const unsigned int size() const {

			return _vectorMediciones.size();
			}

		/*!
			\brief  Devuelve la cima del montículo
			\note   Método const
			\note   Método heredado de la clase interfaz
			\return Objeto de la clase Medicion devuelto como referencia constante
			\pre    El montículo no está vacío
			\post   el valor devuelto es igual al primer elemento del montículo
		*/
		const ed::Medicion & top() const {

			#ifndef NDEBUG
			assert( not this->isEmpty() );
			#endif

			return this->getElement(0);
			}

		////////////////////////////////////////////////////////////

		//! \name Modificadores públicos

		/*!
			\brief Inserta una nueva medición en el montículo
			\note  Método codificado en el fichero cpp
			\note  Métdo heredado de la clase interfaz
			\param medicion Objeto de la clase Medicion pasado como referencia constante
			\post  El montículo no está vacío
			\post  medicion está dentro del montículo
			\sa    remove(), removeAll()
		*/
		void insert( const ed::Medicion & medicion );

		/*!
			\brief Borra la medición que ocupa la cima
			\note  Método heredado de la clase interfaz
			\pre   El montículo no está vacío
			\sa    insert(), removeAll()
		*/
		void remove(){

			#ifndef NDEBUG
			assert( not this->isEmpty() );
			#endif

			unsigned int tam = this->size();

			// Se borra el elemento
			if( tam > 1 )	this->setElement( 0 , _vectorMediciones.back() );
			_vectorMediciones.pop_back();

			// Se reordena el montículo
			if( tam > 1 )
				this->shiftDown(0);
			}

		/*!
			\brief Borra todas la mediciones del montículo
			\note  Método codificado en el fichero cpp
			\post  El montículo está vacío
			\sa    insert(), remove()
		*/
		void removeAll();

		/*!
			\brief Modifica la medición que ocupa la cima y actualiza el montículo para que esté ordenado.
			\note  Método inline
			\param medicion Objeto de la clase Medicion pasado como referencia constante
			\pre   El montículo no está vacío
			\post  medicion está dentro del montículo
			\sa    setElement(), getElement()
		*/
		inline void modify( ed::Medicion const & medicion ){

			#ifndef NDEBUG
			assert( not this->isEmpty() );
			#endif

			// Se modifica la cima
			this->setElement( 0 , medicion );

			// Se hunde la cima
			if( this->size() > 1 )
				this->shiftDown(0);

			// Versión alternativa
			// this->remove();
			// this->insert( medicion );

			#ifndef NDEBUG
			assert( this->has(medicion) );
			#endif
			}

		//! \name Operadores

		/*!
			\brief   Devuelve el montículo actual que ha sido modificado con las mediciones del montículo “m”
			\note    Método inline
			\param   m Objeto de la clase MonticuloMediciones pasado como referencia constante
			\return  this
			\pre     El montículo actual no es igual a m
		*/
		inline ed::MonticuloMediciones & operator = ( ed::MonticuloMediciones const & m ){

			#ifndef NDEBUG
			assert( this != &m );
			#endif 

			this->removeAll();

			this->_vectorMediciones = m._vectorMediciones;

			return *this;
			}

		////////////////////////////////////////////////////////////////////

		//! \name Función de escritura

		/*!
			\brief Escribe las mediciones tal y como están almacenadas en el vector que representa el montículo.
			\note  Método codificado en el fichero cpp
			\note  Método const
			\note  El formato de las mediciones es: dia-mes-año precipitacion
		*/
		void print() const;


	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
