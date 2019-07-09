
#include <iostream>
#include <string>

#include "Grafo.hpp"
#include "Vertice.hpp"

#ifndef AUXILIARES
#define AUXILIARES
namespace ed{

int menu();
void cargarVerticesDesdeFichero( ed::Grafo & grafo );
void grabarVerticesEnFichero( ed::Grafo & grafo );
void mostrarGrafo( ed::Grafo & grafo );
void cambiarDirigido( ed::Grafo & grafo );
void arbolAbarcadorMinimo( ed::Grafo & grafo, ed::Grafo & arbolPrim, ed::Grafo & arbolKruskal );

}// Fin del espacio de nombres ed
#endif
