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
#include "Polinomio.h"

using namespace std;


// función que resuelve el problema
// comentario sobre el coste, O(f(N))


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada


	pair<int, int> monomio;
	Polinomio pol;
	int coeficiente, exponente, numEvaluaciones, valorEvaluacion;

	cin >> coeficiente >> exponente;
	while (coeficiente != 0 || exponente != 0) {
		monomio.first = coeficiente;
		monomio.second = exponente;
		pol.insert(monomio);
		cin >> coeficiente >> exponente;
	}

	

	if (!std::cin)
		return false;

	cin >> numEvaluaciones;
	for (int i = 0; i < numEvaluaciones; ++i) {
		cin >> valorEvaluacion;
		cout << pol.evaluar(valorEvaluacion) << " ";
	}

	cout << endl;


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