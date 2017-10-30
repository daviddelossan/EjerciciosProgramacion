// Grupo E34 Y E67, Daniel Martin Barrios y David de los Santos Gil
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
int resolver(int valor, int anterior, int acumulador) {
	int resultado;

	if (valor == 0){
		return 0;
	}
	else if (valor == 1){
		return 1;
	}
	else{
		anterior++;
		acumulador = resolver(valor - 1, anterior, acumulador) - anterior;
		anterior = acumulador + anterior;
		resultado = acumulador + anterior;
		return resultado;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int valor, resultado;


	if (!std::cin)
		return false;

	std::cin >> valor;
	std::cout << resolver(valor, 1, 0) << std::endl;


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