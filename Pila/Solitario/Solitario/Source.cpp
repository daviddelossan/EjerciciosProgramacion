
// Grupo E67, David de los Santos Gil
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "stack_eda.h"



typedef struct tCarta{
	int palo;
	int numero;
};


// El método va iterando hasta que ya no queden cartas o hayamos dado una vuelta entera sin poner una carta
bool resolver(stack<tCarta> cartasMano) {
	stack<tCarta> cartasDescubiertas;
	tCarta carta;
	stack<tCarta> cartasOros;
	stack<tCarta> cartasCopas;
	stack<tCarta> cartasEspadas;
	stack<tCarta> cartasBastos;
	bool puedePoner, vueltaPoniendo = true, resultado = false;


	while(vueltaPoniendo && !cartasMano.empty()){
		vueltaPoniendo = false;

		while (!cartasMano.empty()) { //Mientras que siga habiendo cartas cubiertas
			carta = cartasMano.top();
			cartasDescubiertas.push(carta);
			cartasMano.pop();

			if (!cartasMano.empty()) {
				carta = cartasMano.top();
				cartasDescubiertas.push(carta);
				cartasMano.pop();
			}

			puedePoner = true;

			while (puedePoner) {
				if (!cartasDescubiertas.empty() && cartasDescubiertas.top().palo == 1) { //Si hay cartas descubiertas y el palo son oros
					if (cartasDescubiertas.top().numero == 1 || // Y la carta es el as, o bien es la siguiente que encaja en la pila de oros
						(!cartasOros.empty() && cartasDescubiertas.top().numero == cartasOros.top().numero + 1)) {
						cartasOros.push(cartasDescubiertas.top());
						cartasDescubiertas.pop();
						vueltaPoniendo = true;
					}
					else puedePoner = false;
				}

				else if (!cartasDescubiertas.empty() && cartasDescubiertas.top().palo == 2) { //Si el palo son copas
					if (cartasDescubiertas.top().numero == 1 ||
						(!cartasCopas.empty() && cartasDescubiertas.top().numero == cartasCopas.top().numero + 1)) {
						cartasCopas.push(cartasDescubiertas.top());
						cartasDescubiertas.pop();
						vueltaPoniendo = true;
					}
					else puedePoner = false;
				}

				else if (!cartasDescubiertas.empty() && cartasDescubiertas.top().palo == 3) { //Si el palo son espadas
					if (cartasDescubiertas.top().numero == 1 ||
						(!cartasEspadas.empty() && cartasDescubiertas.top().numero == cartasEspadas.top().numero + 1)) {
						cartasEspadas.push(cartasDescubiertas.top());
						cartasDescubiertas.pop();
						vueltaPoniendo = true;
					}
					else puedePoner = false;
				}

				else if (!cartasDescubiertas.empty() && cartasDescubiertas.top().palo == 4) { //Si el palo son bastos
					if (cartasDescubiertas.top().numero == 1 ||
						(!cartasBastos.empty() && cartasDescubiertas.top().numero == cartasBastos.top().numero + 1)) {
						cartasBastos.push(cartasDescubiertas.top());
						cartasDescubiertas.pop();
						vueltaPoniendo = true;
					}
					else puedePoner = false;
				}
				else puedePoner = false;
			}

		}

		//Ponemos las descubiertas en el mazo de la mano

		while (!cartasDescubiertas.empty()) {
			cartasMano.push(cartasDescubiertas.top());
			cartasDescubiertas.pop();
		}
	}


	if (cartasMano.empty()) {
		if (!cartasOros.empty())
			if (cartasOros.top().numero != 10)
				return false;
		if (!cartasCopas.empty())
			if (cartasCopas.top().numero != 10)
				return false;
		if (!cartasEspadas.empty())
			if (cartasEspadas.top().numero != 10)
				return false;
		if (!cartasBastos.empty())
			if (cartasBastos.top().numero != 10)
				return false;
	}
	else return false;

	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char c;
	int palos;
	tCarta carta;
	stack<tCarta> cartasMano;
	stack<tCarta> cartasOrdenadas;


	std::cin >> palos;

	if (palos == 0)
		return false;

	else {

		for (int i = 0; i < palos * 10; ++i) {
			std::cin >> carta.numero;
			std::cin >> c;

			if (carta.numero == 10 || carta.numero == 11 || carta.numero == 12) carta.numero = carta.numero - 2;

			if (c == 'O') carta.palo = 1;
			else if (c == 'C') carta.palo = 2;
			else if (c == 'E') carta.palo = 3;
			else carta.palo = 4;

			cartasMano.push(carta);
		}
	}
	
	while (!cartasMano.empty()) {
		cartasOrdenadas.push(cartasMano.top());
		cartasMano.pop();
	}
	

	if (resolver(cartasOrdenadas)) std::cout << "GANA" << std::endl;
	else std::cout << "PIERDE" << std::endl;

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	
	#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif
	

	while (resuelveCaso())
		;

	
	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");

	
	#endif
	
	return 0;
}