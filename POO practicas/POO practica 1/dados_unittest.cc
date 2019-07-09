//
// He añadido mis tests al final del fichero.
//

// dados_unittest.cc: Álvaro García Fuentes
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}



// Tests operación diferencia
TEST(Dados, Diferencia){
	Dados d;
  
	EXPECT_EQ(d.getDado1()-d.getDado2(), d.getDiferencia());
	}

// Tests cuenta de lanzamientos
TEST(Dados, Lanzamientos){
	Dados d;
	int i;
	
	EXPECT_EQ(0, d.getLanzamientos1());
 	EXPECT_EQ(0, d.getLanzamientos2());

	for(i=0; i<3; i++)
 		d.lanzamiento();
	EXPECT_EQ(i, d.getLanzamientos1());
 	EXPECT_EQ(i, d.getLanzamientos2());
	}

TEST(Dados, SetLanzamientos){
	Dados d;

	d.setDado1(1+rand()%6);
	d.setDado2(1+rand()%6);
	EXPECT_EQ(1, d.getLanzamientos1());
 	EXPECT_EQ(1, d.getLanzamientos2());
	}

// Tests cuenta de las medias
TEST(Dados, Medias){
	Dados d;
	int i, dados1=0, dados2=0;
	
	EXPECT_EQ(0, d.getMedia1());
 	EXPECT_EQ(0, d.getMedia2());

	for(i=0; i<5; i++){
		d.lanzamiento();
		dados1 = dados1 + d.getDado1();
		dados2 = dados2 + d.getDado2();
		}
	dados1 = dados1 / d.getLanzamientos1();
	dados2 = dados2 / d.getLanzamientos2();

	EXPECT_EQ(dados1, d.getMedia1());
 	EXPECT_EQ(dados2, d.getMedia2());
	}

//Tests función getUltimos de forma indirecta
TEST(Dados, getUltimos){
	Dados d;
	int vector1[5], vector2[5], i=0, media1=0, media2=0;

	for(i=4; i>=0; i--){
		d.lanzamiento();
		vector1[i]=d.getDado1();
		vector2[i]=d.getDado2();
		media1 = media1 + vector1[i];
		media2 = media2 + vector2[i];

		EXPECT_EQ(media1/d.getLanzamientos1(), d.getMedia1());
		EXPECT_EQ(media2/d.getLanzamientos2(), d.getMedia2());		
		}
	}

