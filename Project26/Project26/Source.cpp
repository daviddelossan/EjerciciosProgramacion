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
int resolver(std::vector<int> const &fila, int inicio, int fin, int &sumaIzq, int &sumaDer, bool &degradado) {
	int mitad = (inicio + fin) / 2;
	int izquierda, derecha;

	if (inicio == fin) {
		degradado = false;
		return fila[inicio];
	}

	else if(inicio + 1 == fin) {
		if (fila[inicio] < fila[fin]) {
			sumaIzq = fila[inicio];
			sumaDer = fila[fin];
			degradado = true;
			return (sumaIzq + sumaDer);
		}
		else {
			degradado = false;
			return 0;
		}
	}

	else {
		izquierda = resolver(fila, inicio, mitad, sumaIzq, sumaDer, degradado);
		derecha = resolver(fila, mitad + 1, fin, sumaIzq, sumaDer, degradado);

		if (izquierda >= derecha) degradado = false;
		else degradado = true;

		return izquierda + derecha;
	}

	

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int filas, columnas, elemento, k = 0, sumaIzq = 0, sumaDer = 0;
	std::vector<std::vector<int>> matriz;
	
	bool degradado = true;

	std::cin >> filas;

	if (!std::cin)
		return false;

	std::cin >> columnas;

	
	for (int i = 0; i < filas; ++i) {
		std::vector<int> fila;

		for (int j = 0; j < columnas; ++j) {
			std::cin >> elemento;
			fila.push_back(elemento);
		}

		matriz.push_back(fila);
	}

	while (degradado && k < filas) {
		std::vector<int> filaADevolver;
		filaADevolver = matriz[k];
		
		resolver(filaADevolver, 0, filaADevolver.size() - 1, sumaIzq, sumaDer, degradado);
		k++;
	}

	if (degradado) {
		std::cout << "SI" << std::endl;
	}
	else std::cout << "NO" << std::endl;

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