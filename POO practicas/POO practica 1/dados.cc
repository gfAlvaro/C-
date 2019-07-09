
	/* dados.cc
	Fichero que contiene las definiciones de los miembros no inline de la clase Dados.*/

#include"dados.h"

// Constructor de la clase Dados.
// Establece la semilla para números aleatorios e inicializa los atributos privados de la clase con valores por defecto.
Dados::Dados(){

	srand(time(NULL));
	d1_=1;
	d2_=1;
	lanzamientos1_=0;
	lanzamientos2_=0;
	}

/* Métodos para ordenar los últimos lanzamientos de dados en sus vectores correspondientes.
 Van trasladando los elementos de vector1_ y vector2_ respectivamente una posición hacia atrás,
 para luego introducir en la primera posición el último valor de d1_ o d2_.*/
void Dados::getUltimos1(int *vector){

	int l=lanzamientos1_;

	if(l==0)
		exit(0);
	else if(l<=5){
		for(l=l-1 ; l>0; l--)
			vector[l]=vector[l-1];			
		vector[0]=d1_;
		}
	else{
		for(l=4; l>0; l--)
			vector[l]=vector[l-1];			
		vector[0]=d1_;
		}
	}
void Dados::getUltimos2(int *vector){

	int l=lanzamientos2_;

	if(l==0)
		exit(0);
	else if(l<=5){
		for(l=l-1 ; l>0; l--)
			vector[l]=vector[l-1];			
		vector[0]=d2_;
		}
	else{
		for(l=4; l>0; l--)
			vector[l]=vector[l-1];			
		vector[0]=d2_;
		}
	}

/* Método para efectuar el lanzamiento de los dados,
 Inicializa los atributos d1_ y d2_ con nuevos valores aleatorios comprendidos entre 1 y 6,
 después incrementa en 1 el valor de los atributos lanzamiento1_ y lanzamiento2_,
 y luego añade los valores de d1 y d2_ a los vectores d1_ y d2_ respectivamente. */
void Dados::lanzamiento(){
	
	d1_ = 1 + rand()%6;
	lanzamientos1_++;
	getUltimos1(vector1_);

	d2_ = 1 + rand()%6;
	lanzamientos2_++;
	getUltimos2(vector2_);
	}

/* Métodos para modificar el valor de los dos dados.
 Cada uno de ellos inicializa el valor de d1_ o d2_ respectivamente
 si el valor del parámetro de entrada está comprendido entre 1 o 6,
 en tal caso inicializará el atributo correspondiente y devolverá true,
 en caso contrario se limitará a devolver false. */
bool Dados::setDado1(int dado1){

	if((dado1<1) || (dado1>6))
		return false;
	else{
		d1_=dado1;
		lanzamientos1_++;
		getUltimos1(vector1_);
		return true;
		}
	}
bool Dados::setDado2(int dado2){

	if((dado2<1) || (dado2>6))
		return false;
	else{
		d2_=dado2;
		lanzamientos2_++;
		getUltimos2(vector2_);
		return true;
		}
	}

/* Métodos para calcular las medias de las sucesivas tiradas de los dos dados.
 Cada método lee los elementos de su vector correspondiente uno a uno y los va sumando en una variable,
 que luego es dividida por el número de lanzamientos que se han efectuado. */
int Dados::getMedia1(){

	int suma=0;
	int i;

	if(lanzamientos1_==0)
		return 0;
	else
		for(i=0; i<lanzamientos1_; i++){
			suma = suma + vector1_[i];
			}
		return suma/lanzamientos1_;
	}
int Dados::getMedia2(){

	int suma=0;
	int i;

	if(lanzamientos2_==0)
		return 0;
	else
		for(i=0; i<lanzamientos2_; i++){
			suma = suma + vector2_[i];
			}
		return suma/lanzamientos2_;
	}

