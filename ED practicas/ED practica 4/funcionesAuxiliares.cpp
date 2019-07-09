/*1
	\file funcionesAuxiliares.cpp
	\author Álvaro García Fuentes
*/
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

namespace ed{

int menu(){
	/*
	1. Cargar un vértices desde un fichero.
	2. Mostrar el grafo por pantalla.
	3. Árbol abarcador de coste mínimo
		a) Aplicar el algoritmo de Prim
		b) Aplicar el algoritmo de Kruskal
		c) Mostrar el árbol abarcador de coste mínimo (si ha sido generado)
		d) Mostrar la longitud total del árbol abarcador de coste mínimo (si ha sido generado)
		e) Etc.
	4. Etc.
	0. Terminar
	*/

	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Cargar un conjunto de vertices desde un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Mostrar el grafo por pantalla";
	posicion++;

	//////////////////////////////////////////////////////////////////////////////
	PLACE(posicion++,10);
	std::cout << "[3] Cambiar el tipo del grafo a dirigido o no dirigido";
	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Árbol abarcador de coste mínimo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
	}

void cargarVerticesDesdeFichero( ed::Grafo & grafo ){

	std::string nombreFichero;


	std::cout << "Introduzca el nombre del fichero a cargar" << std::endl;

	std::getline(std::cin, nombreFichero );	


	std::ifstream fichero( nombreFichero.c_str() );

	if( not fichero.is_open() )
		std::cout << "No se pudo abrir el fichero o no existe." << std::endl;
	
	else{
		std::vector<float> vector;

		while( fichero >> vector[0] ){

			fichero >> vector[1];
			grafo.addVertice( vector );
			}
		fichero.close();

		// Se añaden lados que conecten los vértices del grafo
		grafo.principioVertice();
		ed::Vertice v = grafo.verticeActual();
		ed::Vertice u = grafo.verticeActual();

		for( int j = 0 ; j < grafo. getNumeroVertices() ; j++ ){

			for( int i = 0 ; i < grafo.getNumeroVertices() ; i++ ){

				
				if(  not ( v == u )  ){
					double peso = sqrt(  pow( v.getX() - u.getX() , 2 ) + pow( v.getY() - u.getY() , 2 )  );
					grafo.addLado( peso, v, u );
					}
				else{
					grafo.addLado( 0.0, v, u );

					if( not grafo.esDirigido() )
						break;
					}

				grafo.goTo(u);
				grafo.siguienteVertice();
				u = grafo.verticeActual();
				}

			grafo.goTo(v);
			grafo.siguienteVertice();
			v = grafo.verticeActual();
			}

		grafo.principioVertice();
		}
	}

void grabarVerticesEnFichero( ed::Grafo & grafo ){

	std::string nombreFichero;

	std::cout << "Introduzca el nombre del fichero donde guardar el grafo" << std::endl;
	std::cout << "(Si el fichero ya existe será sobreescrito)" << std::endl;
	std::getline( std::cin , nombreFichero );

	std::ofstream fichero( (nombreFichero + ".txt").c_str() );

	if( not fichero.is_open() )
		std::cout << "No se pudo crear el fichero de guardado" << std::endl;
	else{

		grafo.principioVertice();

		for( int i = 0 ; i  < grafo.getNumeroVertices() ; i++ ){

			fichero << grafo.verticeActual() << std::endl;

			grafo.siguienteVertice();
			}

		fichero.close();
		}

	}

void mostrarGrafo( ed::Grafo & grafo ){

	grafo.principioVertice();

	ed::Vertice primerVertice, segundoVertice;


	if( grafo.esDirigido() )
		std::cout << "El grafo es dirigido" << std::endl;
	else
		std::cout << "El grafo no es dirigido" << std::endl;

	std::cout << "Vértices del grafo:" << std::endl << std::endl;

	for( int i = 0 ; i < grafo.getNumeroVertices() ; i++ )
		std::cout << grafo.verticeActual().getEtiqueta() << " " << grafo.verticeActual() << std::endl;

	std::cout << "Lados del grafo:" << std::endl << std::endl;
	grafo.principioVertice();

	for( int j = 0 ; j < grafo.getNumeroVertices() ; j++ ){

		grafo.goTo(j);
		primerVertice = grafo.verticeActual();

		for( int i = 0 ; i < grafo.getNumeroVertices() ; i++ ){

			grafo.goTo(i);
			segundoVertice = grafo.verticeActual();

			if( grafo.esDirigido() )
				if(  ( not ( i == j ) ) and grafo.adyacente( primerVertice , segundoVertice )  )
					std::cout << "Lado desde " << primerVertice.getEtiqueta() << " hasta "  << segundoVertice.getEtiqueta()
					 << " con peso: " << grafo.ladoAdyacente( primerVertice, segundoVertice ) << std::endl;

			else if( i == j )
				break;

			else if(  grafo.adyacente( primerVertice , segundoVertice )  )
					std::cout << "Lado entre vertice " << primerVertice.getEtiqueta() << " y "  << segundoVertice.getEtiqueta()
					 << " con peso: " << grafo.ladoAdyacente( primerVertice, segundoVertice ) << std::endl;
			}
		}

	grafo.principioVertice();
	}

void cambiarDirigido( ed::Grafo & grafo ){

	int numero;

	bool dirigido = grafo.esDirigido();

	do{
		if( dirigido ){
			std::cout << "El grafo es dirigido" << std::endl;
			std::cout << "Si desea cambiarlo a no dirigido pulse 1." << std::endl;
			}
		else{
			std::cout << "El grafo no es dirigido" << std::endl;
			std::cout << "Si desea cambiarlo a dirigido pulse 1." << std::endl;
			}
		std::cout << "En caso contrario pulse 0" << std::endl;

		std::cin >> numero;

		}while(  ( numero != 0 ) and ( numero != 1 )  );

	if( numero == 1 ){

		if(dirigido){
			grafo.creaNoDirigido();
			std::cout << "Ahora el grafo es no dirigido" << std::endl;
			}
		else{
			grafo.creaDirigido();
			std::cout << "Ahora el grafo es dirigido" << std::endl;
			}
		}
	else
		std::cout << "El tipo de grafo no se ha cambiado" << std::endl;
	}

void arbolAbarcadorMinimo( ed::Grafo & grafo, ed::Grafo arbolPrim, ed::Grafo arbolKruskal ){

	/*
		a) Aplicar el algoritmo de Prim
		b) Aplicar el algoritmo de Kruskal
		c) Mostrar el árbol abarcador de coste mínimo (si ha sido generado)
		d) Mostrar la longitud total del árbol abarcador de coste mínimo (si ha sido generado)
		e) Etc.
	*/

	// algoritmo de Prim
	
	int numVertices = grafo.getNumeroVertices();

	if( grafo.esDirigido() )
		std::cout << "No se ha podido crear el árbol abarcador minimo con el algoritmo de Prim porque el grafo es dirigido" << std::endl;

	else{
		// arbolPrim = Grafo;

		// copiar matriz de adyacencia del grafo
		std::vector< std::vector<double> > adyacencia;

		grafo.principioVertice();
		for( int i = 0 ; i < numVertices ; i++ ){

			ed::Vertice primerVertice = grafo.verticeActual();

		for( int j = 0 ; j < numVertices ; j++ ){

				ed::Vertice segundoVertice = grafo.verticeActual();

				if(  grafo.adyacente( primerVertice , segundoVertice )  )
					adyacencia[i][j] = grafo.ladoAdyacente( primerVertice, segundoVertice );

				grafo.siguienteVertice();
				}
	
			grafo.principioVertice();
			grafo.goTo(primerVertice);

			grafo.siguienteVertice();
			}


		std::vector< std::vector<double> > arbol( numVertices );
		std::vector<double> lineasMarcadas;
		std::vector<double> :: iterator itVec;

		// Inicializo las distancias del arbol.
		for( int i = 0 ; i < numVertices ; i++ ){

			for(int j = 0 ; j < numVertices ; j++ )
				if (i == j)
					arbol[i][j] = 0.0;
				else
					arbol[i][j] = std::numeric_limits<double>::infinity();	
			}
		int padre = 0;
		int hijo = 0;

		while(  ( lineasMarcadas.size() + 1 ) < (unsigned) numVertices  ){

			padre = hijo;

			// Marco la fila y elimino la columna del nodo padre.
			lineasMarcadas.push_back(padre);
			for( int i = 0 ; i < numVertices ; i++ )
				adyacencia[i][padre] = std::numeric_limits<double>::infinity();

			// Encuentro la menor distancia entre las filas marcadas.
			// El nodo padre es la linea marcada y el nodo hijo es la columna del minimo.
			double minPeso = std::numeric_limits<double>::infinity();

			for( itVec = lineasMarcadas.begin() ; itVec != lineasMarcadas.end() ; itVec++ )
				for(int i = 0 ; i < numVertices ; i++)
					if(  ( *itVec != i ) and ( minPeso > adyacencia[*itVec][i] )  ){
						minPeso = adyacencia[*itVec][i];
						padre = *itVec;
						hijo = i;
						}

			grafo.goTo(padre);
			ed::Vertice verticePadre = grafo.verticeActual();

			grafo.goTo(hijo);
			ed::Vertice verticeHijo = grafo.verticeActual();

			arbolPrim.addLado( minPeso , verticePadre , verticeHijo );

			std::vector<float> vector;
			vector[0] = verticeHijo.getX();
			vector[1] = verticeHijo.getY();

			arbolPrim.addVertice(vector);
			}

		std::cout << "Árbol abarcador mínimo con algoritmo de Prim con longitud: " << arbolPrim.getNumeroVertices() << std::endl << std::endl;
		ed::mostrarGrafo( arbolPrim );
		}


	// algoritmo de Kruskal

	// Copiar matriz de adyacencia del grafo
	std::vector< std::vector<double> > adyacencia;

	grafo.principioVertice();
	for( int i = 0 ; i < numVertices ; i++ ){

		ed::Vertice primerVertice = grafo.verticeActual();

		for( int j = 0 ; j < numVertices ; j++ ){

			ed::Vertice segundoVertice = grafo.verticeActual();

			if(  grafo.adyacente( primerVertice , segundoVertice )  )
				adyacencia[i][j] = grafo.ladoAdyacente( primerVertice, segundoVertice );

			grafo.siguienteVertice();
			}
	
		grafo.principioVertice();
		grafo.goTo(primerVertice);

		grafo.siguienteVertice();
		}


	std::vector< std::vector<double> > arbol( grafo.getNumeroVertices() );
	std::vector<int> pertenece( numVertices ); // indica a que árbol pertenece el vertice

	for( int i = 0 ; i < numVertices ; i++){
		arbol[i] = std::vector<double> ( numVertices , 0 );
		pertenece[i] = i;
		}

	int verticeA = 0;
	int verticeB = 0;
	int arcos = 1;

	while( arcos < numVertices ){
		// Encontrar  el arco mínimo que no forma ciclo y guardar los nodos y la distancia.
		double minPeso = std::numeric_limits<double>::infinity();
		for(int i = 0 ; i < numVertices ; i++ )
			for(int j = 0; j < numVertices ; j++ )
				if( minPeso > adyacencia[i][j] && adyacencia[i][j]!=0 && pertenece[i] != pertenece[j]){
					minPeso = adyacencia[i][j];
					verticeA = i;
					verticeB = j;
					}

			// Si los vertices no pertenecen al mismo árbol agrego el arco al árbol mínimo.
		if(pertenece[verticeA] != pertenece[verticeB]){
			arbol[verticeA][verticeB] = minPeso;
			arbol[verticeB][verticeA] = minPeso;

			// Todos los vertices del árbol del verticeB ahora pertenecen al árbol del verticeA.
			int temp = pertenece[verticeB];
			pertenece[verticeB] = pertenece[verticeA];
			for( int k = 0 ; k < numVertices ; k++ )
				if( pertenece[k] == temp )
					pertenece[k] = pertenece[verticeA];
	
			arcos++;
	        	}

		grafo.goTo(verticeA);
		ed::Vertice verticePadre = grafo.verticeActual();

		grafo.goTo(verticeB);
		ed::Vertice verticeHijo = grafo.verticeActual();

		arbolKruskal.addLado( minPeso , verticePadre , verticeHijo );

		std::vector<float> vector;
		vector[0] = verticeHijo.getX();
		vector[1] = verticeHijo.getY();

		grafo.principioVertice();

		arbolKruskal.addVertice(vector);
		}

	std::cout << "Árbol abarcador mínimo con algoritmo de Kruskal de longitud" << arbolKruskal.getNumeroVertices() << ":" << std::endl << std::endl;
	ed::mostrarGrafo( arbolKruskal );
	}



} // Fin del espacio de nombres ed
