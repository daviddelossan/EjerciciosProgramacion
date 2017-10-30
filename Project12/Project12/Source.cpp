// Grupo E67, David de los Santos Gil
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
// comentario sobre el coste: el coste es O(n) porque recorro
// el vector de alturas una sola vez
void resolver(std::vector<int> const & edificios, int altura, int & inicio, int & fin) {
	int maximoSeguidos = 0, anteriorMaximoSeguidos = 0, posibleInicio = 0;
	inicio = 0, fin = 0;

	for (int i = 0; i < edificios.size(); ++i){

		if (edificios.at(i) > altura){
			++maximoSeguidos;

			if (maximoSeguidos == 1) posibleInicio = i;

			if (maximoSeguidos > anteriorMaximoSeguidos){
				anteriorMaximoSeguidos = maximoSeguidos;
				inicio = posibleInicio;
				fin = i;
			}
		}

		else maximoSeguidos = 0;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numEdificios, altura, alturaEdificio, inicio, fin;
	std::vector<int> edificios;

	std::cin >> numEdificios;
	std::cin >> altura;

	for (int i = 0; i < numEdificios; ++i){
		std::cin >> alturaEdificio;
		edificios.push_back(alturaEdificio);
	}

	resolver(edificios, altura, inicio, fin);
	std::cout << inicio << " " << fin << std::endl;


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