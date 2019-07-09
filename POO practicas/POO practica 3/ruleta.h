
	/* ruleta.h
	 Archivo de cabecera que contiene la declaración de la clase Ruleta,
	 así como los headers y bibliotecas que esta clase necesita. */

// En este header está incluida la biblioteca string.
#include"crupier.h"
// En este header están incluidas las bibliotecas string, list, iostream, fstream, sstream, istream y cstdlib.
#include"jugador.h"

#ifndef CTIME
	#define CTIME
	#include<ctime>
	#endif

#ifndef RULETA
	#define RULETA
	class Ruleta{
		private:
			int banca_;
			int bola_;
			std::list<Jugador> jugadores_;
			Crupier crupier_;
		public:
			Ruleta(Crupier crupier);

			inline int getBanca(){return banca_;};
			inline int getBola(){return bola_;};
			inline Crupier getCrupier(){return crupier_;};
			inline std::list<Jugador> getJugadores(){return jugadores_;};

			bool setBanca(int banca);
			bool setBola(int bola);
			void setCrupier(Crupier crupier);

			bool addJugador(Jugador jugador);

			int deleteJugador(Jugador jugador);
			int deleteJugador(std::string DNI);

			void leeJugadores();
			void escribeJugadores();

			void giraRuleta();
			void getPremios();
		};
	#endif
