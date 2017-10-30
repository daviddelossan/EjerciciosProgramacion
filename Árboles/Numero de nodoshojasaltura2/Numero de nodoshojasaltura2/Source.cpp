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
#include "bintree_eda.h"



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
/*
Solucion resolver(Datos datos) {


}
*/
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

		// leer los datos de la entrada
	bintree<char> arbol;
	char raiz = '*';
	int numNodos = 0, numHojas = 0, altura = 0;

	arbol = arbol.leerArbol(raiz);

	if (!arbol.empty()) {
		numNodos = arbol.calculaNodos(numNodos);
		numHojas = arbol.calculaHojas(numHojas);
		altura = arbol.calculaAltura(altura);
	}
	/*
	altura = arbol.calculaAltura();
	Solucion sol = resolver(datos);*/
	// escribir sol

	std::cout << numNodos << " " << numHojas << " " << altura << std::endl;


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
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