
	/* dados.h
	Fichero de cabecera que contiene la declaración de la clase Dados
	 y las bibliotecas necesarias para usar sus métodos. */

#ifndef CSTDLIB
	#define CSTDLIB
	#include <cstdlib>
	#endif

#ifndef CTIME
	#define CTIME
	#include <ctime>
	#endif

#ifndef DADOS
	#define DADOS
	class Dados{
		private:
			int d1_;
			int d2_;
			int lanzamientos1_;
			int lanzamientos2_;
			int vector1_[5];
			int vector2_[5];
		public:
			Dados();

			void getUltimos1(int *vector);
			void getUltimos2(int *vector);
			void lanzamiento();

			// Métodos inline para mostrar el valor de los dados.
			// Devuelven respectivamente el valor almacenado en los atributos d1_ y d2_.
			inline int getDado1(){return d1_;};
			inline int getDado2(){return d2_;};

			// Métodos inline para mostrar el valor de los lanzamientos dados.
			// Devuelven respectivamente el valor almacenado en los atributos lanzamientos1_ y lanzamientos2_.
			inline int getLanzamientos1(){return lanzamientos1_;};
			inline int getLanzamientos2(){return lanzamientos2_;};

			bool setDado1(int dado1);
			bool setDado2(int dado2);

			// Métodos inline para mostrar la suma y la diferencia entre los valores de los dados.
			// Devuelven un entero que representa la suma o diferencia respectivamente de d1_ y d2_.
			inline int getSuma(){return d1_ + d2_;};
			inline int getDiferencia(){return d1_ - d2_;};

			int getMedia1();
			int getMedia2();
		};
	#endif
