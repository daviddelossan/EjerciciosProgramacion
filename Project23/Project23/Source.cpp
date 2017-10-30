// Grupo E34 y E67, Daniel Martín Barrios y David de los Santos Gil
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
bool resolver(std::vector<int> const & carton, const int & cantado, int i, int &solucion) {
	if (i >= carton.size()) return false;

	if (cantado + i == carton[i]){
		solucion = carton[i];
		return true;
	}
	else resolver(carton, cantado, i + 1, solucion);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numValores, cantado, valor, sol;


	std::cin >> numValores;
	std::cin >> cantado;

	std::vector<int> carton(numValores);

	for (int i = 0; i < numValores; ++i){
		std::cin >> valor;
		carton[i] = valor;
	}

	if (resolver(carton, cantado, 0, sol)) std::cout << sol << std::endl;
	else std::cout << "NO" << std::endl;

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