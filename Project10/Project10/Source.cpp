// Grupo e67, David de los Santos Gil
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
void resolver(std::vector<int> &vectorRepetidos, std::vector<int> siguienteVector) {
	std::vector<int> nuevoVectorRepetidos;
	bool encontrado = false;
	int i = 0, j = 0;

	while (i < vectorRepetidos.size() && j < siguienteVector.size()){
		if (vectorRepetidos.at(i) == siguienteVector.at(j)){ //Si el elemento es igual lo guardamos en el vector de repetidos
			nuevoVectorRepetidos.push_back(vectorRepetidos.at(i));
			i++;
			j++;
		}
		else if (vectorRepetidos.at(i) >= siguienteVector.at(j)) j++; //Si es mayor, avanzamos en siguienteVector
		else i++; //Si es menor, avanzamos en vectorRepetidos
	}

	vectorRepetidos = nuevoVectorRepetidos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numeroVectores, valor;
	std::vector<int> vectorRepetidos;

	std::cin >> numeroVectores;


	std::cin >> valor;
	while (valor != 0){
		vectorRepetidos.push_back(valor);
		std::cin >> valor;
	}

	for (int i = 1; i < numeroVectores; ++i){
		std::vector<int> siguienteVector;
		std::cin >> valor;
		while (valor != 0){
			siguienteVector.push_back(valor);
			std::cin >> valor;
		}

		resolver(vectorRepetidos, siguienteVector);
	}


	// if (numeroVectores == 1) resultado = primerVector;
	// else resultado = resolver(primerVector, numeroVectores);

	for (int i = 0; i < vectorRepetidos.size(); ++i){
		std::cout << vectorRepetidos.at(i) << " ";
	}
	std::cout << std::endl;
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
