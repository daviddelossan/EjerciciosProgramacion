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
int resolver(std::vector<int> const &decreciente, int inicio, int fin) {
	int mitad = (inicio + fin) / 2;

	if (inicio == fin) return decreciente.at(inicio);
	if (decreciente.at(inicio) < decreciente.at(mitad + 1)) {
		fin = mitad;
	}
	else {
		inicio = mitad + 1;
	}

	resolver(decreciente, inicio, fin);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int elementos, elemento;
	std::vector<int> decreciente;

	std::cin >> elementos;
	


	for (int i = 0; i < elementos; ++i) {
		std::cin >> elemento;
		decreciente.push_back(elemento);
	}

	if (!std::cin)
		return false;

	std::cout << resolver(decreciente, 0, decreciente.size() - 1) << std::endl;

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