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


bool estaMarcado(std::vector<std::vector<bool>> const &marcados, int i, int k, int numFuncionarios) {
	for (int j = 0; j < numFuncionarios; ++j) {
		if (marcados[i][j]) {
			return true;
		}
		if (marcados[j][k]) {
			return true;
		}
	}
	return false;
}




// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(std::vector<std::vector<int>> const &matriz, int i, int &mejorTiempo, int suma, int numFuncionarios, std::vector<std::vector<bool>> &marcados) {
	int k = 0;

	while (i < numFuncionarios && k < numFuncionarios) {

		suma += matriz[i][k];

		if (!estaMarcado(marcados, i, k, numFuncionarios)) { // Compruebo si podemos coger esa casilla
			marcados[i][k] = true;
			if (i == numFuncionarios - 1) { // Si es solución
				if (mejorTiempo > suma) {
					mejorTiempo = suma;
				}
			}
			else {
				resolver(matriz, i + 1, mejorTiempo, suma, numFuncionarios, marcados);
			}
			marcados[i][k] = false;
		}
		suma -= matriz[i][k];		
		k++;
	}
}






// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int mejorTiempo = 10000, numFuncionarios, elemento;
	std::vector<std::vector<int>> matriz;
	std::vector<std::vector<bool>> marcados;
	
	


	std::cin >> numFuncionarios;

	if (numFuncionarios == 0)
		return false;

	for (int i = 0; i < numFuncionarios; ++i) {
		std::vector<int> lineaTrabajos;
		std::vector<bool> lineaMarcados;

		for (int j = 0; j < numFuncionarios; ++j) {
			std::cin >> elemento;
			lineaTrabajos.push_back(elemento);
			lineaMarcados.push_back(false);
		}
		matriz.push_back(lineaTrabajos);
		marcados.push_back(lineaMarcados);
	}

	resolver(matriz, 0, mejorTiempo, 0, numFuncionarios, marcados);

	std::cout << mejorTiempo << std::endl;

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