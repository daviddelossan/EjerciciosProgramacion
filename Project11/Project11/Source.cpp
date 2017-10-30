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



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int equilibrio(std::vector<int> const &vectorEquilibrados) {
	int pos = -1, unos = 0, ceros = 0;
	bool equilibrado = false;

	for (int i = 0; i < vectorEquilibrados.size(); ++i){
		if (vectorEquilibrados.at(i) == 1){
			unos++;
		}
		else if (vectorEquilibrados.at(i) == 0){
			ceros++;
		}

		if (unos == ceros){
			equilibrado = true;
			pos = i;
		}
		else equilibrado = false;
	}

	return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numCasos, resultado = -1, componentes, componente;
	std::vector<int> vectorEquilibrados;

		std::cin >> componentes;
		for (int j = 0; j < componentes; ++j){
			std::cin >> componente;
			vectorEquilibrados.push_back(componente);
		}

		resultado = equilibrio(vectorEquilibrados);

	std::cout << resultado << std::endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
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