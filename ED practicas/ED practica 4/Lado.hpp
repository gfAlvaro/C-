
#include "Vertice.hpp"

namespace ed{

#ifndef LADO
#define LADO
class Lado{

	private:

		// Atributos Privados de la clase Lado

		ed::Vertice _primero; //!<Primer vertice del lado
		ed::Vertice _segundo; //!<Segundo vertice del lado
		double _peso; //!<Peso del lado

	public:
		// Métodos públicos de la clase Lado

		//! Observadores

		/*!
		  \brief devuelve el peso del lado.

		*/
		inline const double & getPeso() const{

			return _peso;
			}
		/*!
			\brief devuelve el primer vertice del lado.
		*/
		inline const ed::Vertice & getPrimero() const {


			ed::Vertice retVal = _primero;

			#ifndef NDEBUG
			assert( otro(retVal) == _segundo );
			#endif

			return retVal;
			}

		/*!
			  \brief devuelve el segundo vértice del lado
		*/
		inline const ed::Vertice & getSegundo() const {

			ed::Vertice retVal = _segundo;

			#ifndef NDEBUG
			assert( otro(retVal) == _primero );
			#endif

			return retVal;
			}

		/*!
			  \brief has() Devuelve si el vértice tiene o no lado. (conexo)
			  \param vertice
		*/
		inline bool has( const ed::Vertice & vertice ) const {

			return (  ( vertice == this->getPrimero() ) or ( vertice == this->getSegundo() )  );
			}

		/*!
			\brief devuelve el vértice contrario del lado al que pertenece.
			\param vertice
			\pre el vertice pertenece al lado
			return objeto de clase ed::Vertice pasado como referencia constante
		*/
		inline const ed::Vertice & otro( const ed::Vertice & vertice ) const {

			#ifndef NDEBUG
			assert( this->has(vertice) );
			#endif

			ed::Vertice retVal;

			if ( vertice == this->getPrimero() )
				retVal = this->getSegundo();

			if ( vertice == this->getSegundo() )
				retVal = this->getPrimero();

			#ifndef NDEBUG
			assert(  has(retVal) and ( otro(retVal) == u )  );
			#endif

			return retVal;
			}
		/*!
			  \brief inserta en _peso el double que le pasamos
			  \param peso
		*/
		inline void setPeso( const double peso ){

			_peso = peso;

			#ifndef NDEBUG
			assert( this->getPeso() == peso );
			#endif
			}

		/*!
			  \brief que establece como primer vertice del lado al vertice recibido
			  \param primero
		*/
      		inline void setPrimero( const ed::Vertice & primero ){

			_primero = primero;

			#ifndef NDEBUG
			assert( this->getPrimero() == primero );
			#endif
			}

		/*!
			\brief setFirst() que establece como segundo vertice del lado al vertice recibido
			\param segundo
		*/
      		inline void setSegundo( const ed::Vertice & segundo ){

			_segundo = segundo;

			#ifndef NDEBUG
			assert( this->getSegundo() == segundo );
			#endif
			}

		/*!
			\brief Sobrecarga del operador == para la clase Lado
			\param lado
		*/
		inline const bool operator == ( const ed::Lado & lado ) const {

			return (  ( lado.getPrimero() == this->getPrimero() ) and ( lado.getSegundo() == this->getSegundo() )  );
			}

	}; // Fin de la clase Lado
#endif

} // Fin del espacio de nombres ed
