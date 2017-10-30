// Grupo XYZ, Fulano y Mengano
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
#include "queue_eda.h"


// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(queue<std::string> &cola, const int numCamas, const int numPalabras) {
	int palabras = numPalabras, camas = numCamas;
	std::string nombre = cola.front();

	while (palabras > 1) {
		
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numCamas, numPalabras, tamanoCola = 0;
	bool fin = false;
	queue<std::string> cola;
	cola.ult();
	
	
	std::cin.get();
	char a = std::cin.get();;

	while (!fin) {
		std::string nombre = "";

		while (a != ' ') {
			nombre = nombre + a;
			std::cin.get(a);
		}

		if (nombre != "F") {
			cola.push(nombre);
			tamanoCola++;
			std::cin.get(a);
		}
		else fin = true;


		
	}

	std::cin >> numCamas;
	std::cin >> numPalabras;

	resolver(cola, numCamas, numPalabras);
	// escribir sol
	
	if (cola.empty()) std::cout << "NADIE TIENE CAMA";


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}