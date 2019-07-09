/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author  Álvaro García Fuentes
	\date   08-04-2018
	\version 1.0

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos privados de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//!	\name  Constructor

	/*!	
		\brief Crea un objeto de la clase Provincia
		\param nombre: dato de tipo const string, inicializado por defecto a ""
		\param codigo: dato de tipo const int, inicializado por defecto a 0
		\post  El nombre de la provincia es igual a nombre
		\post  El código de la provincia es igual a codigo
		\post  La provincia no tiene municipios
	*/
	Provincia(std::string const nombre = "", const int codigo = 0){

		this->setNombre(nombre);
		this->setCodigo(codigo);

		//_listaMunicipios.removeAll();

		#ifndef NDEBUG
		assert(this->getNombre() == nombre);
		assert(this->getCodigo() == codigo);
		assert(not this->hayMunicipios());
		#endif
		}

	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores

	/*!
		\brief  Función para consultar el nombre de la provincia
		\note   Función inline y const
		\return Dato de tipo const string
		\sa     getCodigo
	*/
	inline const std::string getNombre() const{

		return _nombre;
		}

	/*!
		\brief  Función para consultar el código de la provincia
		\note   Función inline y const
		\return Dato de tipo const int
		\sa     getNombre
	*/
	inline const int getCodigo() const{

		return _codigo;
		}

	/*!
		\brief  Función para verificar si hay municipios en ella
		\note   Función inline y const
		\note   La función devuelve true si la provincia tiene municipios y false en caso contrario.
		\return Dato de tipo bool
	*/
	inline bool hayMunicipios() const{

		return not this->_listaMunicipios.isEmpty();
		}

	/*!
		\brief  Función para consultar el número de municipios que tiene la Provincia
		\note   Función inline y const
		\return Dato de tipo const int
	*/
	inline const int getNumeroMunicipios() const{
		
		return this->_listaMunicipios.nItems();
		}
	/*!
		\brief  Función para comprobar si existe en la Provincia un Municipio dado
		\note  	Función codificada en el fichero cpp
		\note   Devuelve true si el Municipio existe en la Provincia y false en caso contrario
		\param  nombre: dato de tipo const string
		\return Dato de tipo bool
	*/
	bool existeMunicipio(std::string const nombre);

	/*!
		\brief  Función para consultar el municipio dado
		\note  	Función inline
		\param  nombre: dato de tipo const string
		\return Objeto de tipo Municipio
		\pre    El municipio existe en la Provincia
	*/
	inline const ed::Municipio & getMunicipio(std::string const nombre){

		#ifndef NDEBUG
		assert(this->existeMunicipio(nombre));
		#endif

		return this->_listaMunicipios.getCurrentItem();
		}

	/*!
		\brief  Función para consultar el número de hombres de la Provincia
		\note  	Función codificada en el fichero cpp
		\return Dato de tipo const int
		\sa     getTotalMujeres, getTotalHabitantes
	*/
	const int getTotalHombres();

	/*!
		\brief  Función para consultar el número de mujeres de la Provincia
		\note  	Función codificada en el fichero cpp
		\return Dato de tipo const int
		\sa     getTotalHombres, getTotalHabitantes
	*/
	const int getTotalMujeres();

	/*!
		\brief  Función para consultar el número de habitantes de la Provincia
		\note  	Función codificada en el fichero cpp
		\return Dato de tipo const int
		\post   El número de habitantes es igual a la suma del número de hombres y el número de mujeres de la Provincia
		\sa     getTotalHombres, getTotalMujeres
	*/
	const int getTotalHabitantes();

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	/*!
		\brief  Función para modificar el nombre de la Provincia
		\note  	Función inline
		\param  nombre: dato de tipo const string
		\post   el nombre de la Provincia es igual a nombre
	*/
	inline void setNombre(std::string const nombre){

		_nombre=nombre;

		#ifndef NDEBUG
		assert(this->getNombre() == nombre);
		#endif
		}

	/*!
		\brief  Función para modificar el código de la Provincia
		\note  	Función inline
		\param  codigo: dato de tipo const int
		\post   el código de la Provincia es igual a codigo
	*/
	inline void setCodigo(const int numero){

		_codigo=numero;

		#ifndef NDEBUG
		assert(this->getCodigo() == numero);
		#endif
		}

	/*!
		\brief  Función para insertar un Municipio en la Provincia
		\note  	Función inline
		\param  municipio: objeto de tipo const Municipio, pasado como referencia
		\pre	El municipio no existe en la Provincia
		\post   El municipio existe en la Provincia
		\post   El número de municipios de la Provincia se ha incrementado en 1
		\sa     borrarMunicipio, borrarTodosLosMunicipios
	*/
	inline void insertarMunicipio(ed::Municipio const & municipio){

	#ifndef NDEBUG
	assert(not this->existeMunicipio(municipio.getNombre()));
	#endif
	
	int old = this->getNumeroMunicipios();

	_listaMunicipios.insert(municipio);

	#ifndef NDEBUG
		assert(this->existeMunicipio(municipio.getNombre()));
		assert(this->getNumeroMunicipios() == (old + 1));
		#endif
		}

	/*!
		\brief  Función para borrar un Municipio de la Provincia
		\note  	Función inline
		\param  nombre: dato de tipo const string
		\pre	El municipio existe en la Provincia
		\post   El municipio no existe en la Provincia
		\post   El número de municipios de la Provincia ha disminuido en 1
		\sa     insertarMunicipio, borrarTodosLosMunicipios
	*/
	inline void borrarMunicipio(std::string const nombre){
		
		#ifndef NDEBUG
		assert(this->existeMunicipio(nombre));
		#endif

		int old = this->getNumeroMunicipios();

		_listaMunicipios.remove();

		#ifndef NDEBUG
		assert(not this->existeMunicipio(nombre));
		assert(this->getNumeroMunicipios() == (old - 1));
		#endif
		}

	/*!
		\brief  Función para borrar todos los Municipios de la Provincia
		\note  	Función inline
		\post   No hay municipios en la Provincia
		\sa     insertarMunicipio, borrarMunicipio
	*/
	inline void borrarTodosLosMunicipios(){

		_listaMunicipios.removeAll();

		#ifndef NDEBUG
		assert(not this->hayMunicipios());
		#endif
		}

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

	/*!
		\brief  Función que muestra por pantalla la lista de municipios de la Provincia
		\note  	Función codificada en el fichero cpp
	*/
	void escribirMunicipios();

	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros

	/*!
		\brief  Función que carga los datos de una Provincia desde un fichero de texto
		\note  	Función codificada en el fichero cpp
		\note   Devuelve true si el fichero se ha cargado con éxito y false en caso contrario
		\param  nombre: dato de tipo const string
		\return dato de tipo bool
		\sa     grabarFichero
	*/
	bool cargarFichero(std::string const nombre);

	/*!
		\brief     Función que graba los datos de una Provincia en un fichero de texto
		\note  	   Función codificada en el fichero cpp
		\note      Devuelve true si los datos se han grabado con éxito en el fichero y false en caso contrario
		\warning   El fichero se nombrará con el nombre de la Provincia seguido de ".txt", y si ya existe se sobrescribirá
		\param     nombre: dato de tipo const string
		\return    dato de tipo bool
		\sa        cargarFichero
	*/
	bool grabarFichero(std::string const nombre);

}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
