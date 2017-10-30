﻿// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "queue_eda.h"



// función que resuelve el problema
// comentario sobre el coste, O(f(N))

/*queue<int> duplicar(queue<int> cola) {
	queue<int> colaDuplicada;

	while (!cola.empty()) {
	colaDuplicada.push(cola.front());
	colaDuplicada.push(cola.front());
	cola.pop();
	}

	return colaDuplicada;
}
*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elemento;

	if (!std::cin)
		return false;

	queue<int> cola;
	std::cin >> elemento;
	
	while (elemento != 0) {		
		cola.push(elemento);
		std::cin >> elemento;
	}
	
	queue<int> colaDuplicada = colaDuplicada.duplicarLista(cola);
	colaDuplicada.imprimirLista();

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