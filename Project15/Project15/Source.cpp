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
int resolver(int filas, int columnas) {
	int elemento, cuentaOrdenados = 0;

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			std::cin >> elemento;
			if (elemento == i) ++cuentaOrdenados;
		}
	}

	return cuentaOrdenados;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas, columnas;

	std::cin >> filas;
	std::cin >> columnas;


	if (!std::cin)
		return false;

	

	std::cout << resolver(filas, columnas) << std::endl;


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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