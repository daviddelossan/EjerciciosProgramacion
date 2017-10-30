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

#include "deque_eda.h"

deque<int> creaAfortunados(const int &n) {
	deque<int> colaAfortunados;
	
	int m = 2, contador, tamano;

	for (int i = 1; i <= n; i++) { //Inicializamos la cola
		colaAfortunados.push_back(i);
	}

	while (m < colaAfortunados.size()) {
		deque<int> colaAuxiliar;
		tamano = colaAfortunados.size();
		contador = 0;
		while (contador < tamano) {

			if (!colaAfortunados.empty()) {
				colaAfortunados.pop_front();
				contador++;
			}

			for (int j = 1; j < m; j++) {
				if (!colaAfortunados.empty()) {
					colaAuxiliar.push_back(colaAfortunados.front());
					colaAfortunados.pop_front();
					contador++;
				}
			}

		}
		colaAfortunados = colaAuxiliar;
		m++;
	}


	return colaAfortunados;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	deque<int> afortunados;
	int n;

	std::cin >> n;
	if (n == 0)
		return false;



	afortunados = creaAfortunados(n);
	afortunados.imprimirDecreciente();

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