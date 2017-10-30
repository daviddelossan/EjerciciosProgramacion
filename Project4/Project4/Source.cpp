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



// función que resuelve el problema. Especificación:
//Precondición: {0 < n}
//proc resolver (vect valores, vect & suma)
//Postcondición: {suma = 

//Comentario sobre el coste: O(N)
void resolver(const std::vector <int> & valores, std::vector <int> & suma) {
	int acumulador = 0;

	for (int i = 0; i < valores.size(); ++i){
		suma.push_back(valores.at(i) + acumulador);
		acumulador = acumulador + valores.at(i);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::vector <int> valores;
	std::vector <int> suma;
	int valor;
	// leer los datos de la entrada


	std::cin >> valor;

	if (valor == 0) return false;

	while (valor != 0){
	valores.push_back(valor);
	std::cin >> valor;
	}

	resolver(valores, suma);

	for (int i = 0; i < suma.size(); ++i){
		std::cout << suma.at(i);
		if (i < (suma.size() - 1)) std::cout << " ";
	}
		
	std::cout << std::endl;
	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}