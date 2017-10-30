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
void resolver(std::vector<std::vector<int>> & matriz, int dimension, int valor, int &numDiagonales, int &diagonalMasCercana, int &franjasIgualMaximo) {
	int i, j, sumaTotal, elementos, numDiagonalesActual = 0, inicio;

	for (int k = 0; k < dimension; k++) { //Para cada diagonal
		sumaTotal = 0;
		elementos = 0;
		i = k;
		j = 0;


		while (i < dimension) { //Recorremos la diagonal
			sumaTotal += matriz[i][j];
			i++;
			j++;
			elementos++;
		}

		if ((sumaTotal / elementos) >= valor) {
			if (numDiagonalesActual == 0) inicio = k;

			numDiagonalesActual++;

			if (numDiagonalesActual == numDiagonales) ++franjasIgualMaximo;
			else if (numDiagonalesActual > numDiagonales) {
				numDiagonales = numDiagonalesActual;
				diagonalMasCercana = inicio;
				franjasIgualMaximo = 1;
			}
		}
		else numDiagonalesActual = 0;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dimension, valor, elemento, numDiagonales = 0, diagonalMasCercana = 0, franjasIgualMaximo = 0;




	std::cin >> dimension;
	std::cin >> valor;

	if (!std::cin)
		return false;

	std::vector<std::vector<int>> matriz(dimension, std::vector<int>(dimension));

	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			std::cin >> elemento;
			matriz[i][j] = elemento;
		}
	}




	resolver(matriz, dimension, valor, numDiagonales, diagonalMasCercana, franjasIgualMaximo);

	if(numDiagonales > 0) std::cout << numDiagonales << " " << diagonalMasCercana << " " << franjasIgualMaximo << std::endl;
	else std::cout << "NO" << std::endl;


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