
	// guess.cc
	// Programa que genera un número aleatorio para luego compararlo con uno introducido por teclado.

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

	int num, ran;

	srand(time(NULL));
	ran= 1 + rand()%10;

	do{
		std::cout << "Introduzca un número entre 1 y 10.\n";
		std::cin >> num;
	}while((num<1) || (num>10));

	if(ran<num)
		std::cout << "El número generado es menor que " << num << ".\n";
	else if(ran>num)
		std::cout << "El número generado es mayor que " << num << ".\n";
	else
		std::cout << "El número generado es correcto.\n";
}
