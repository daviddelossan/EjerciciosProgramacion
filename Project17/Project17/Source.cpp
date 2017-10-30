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



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int cuentaPiedras(std::vector<char> const & piedras, int tam, int numR, int numZ) {
	int contador = 0, cuentaR, cuentaZ;

	for (int i = 0; i < piedras.size() - tam + 1; ++i){
		cuentaR = 0;
		cuentaZ = 0;
		for (int j = i; j < i + tam; ++j){
			if (piedras.at(j) == 'r') cuentaR++;
			else if (piedras.at(j) == 'z') cuentaZ++;
		}
		if (cuentaR >= numR && cuentaZ >= numZ) contador++;
	}


	return contador;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tamVector, tam, numR, numZ;
	std::vector<char> piedras;
	char elemento;

	std::cin >> tamVector;
	std::cin >> tam;
	std::cin >> numR;
	std::cin >> numZ;

	for (int i = 0; i < tamVector; ++i){
		std::cin >> elemento;
		piedras.push_back(elemento);
	}

	std::cout << cuentaPiedras(piedras, tam, numR, numZ) << std::endl;


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