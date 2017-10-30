// Grupo E76, David de los Santos Gil
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
// comentario sobre el coste: el coste de la función es O(n)
// siendo n el número de elementos del vector, ya que solo lo recorre una vez
int resolver(std::vector<int> const & suma) {
	int maximo, numMaximos = 1, sumaTotal = 0, maximoAnterior;

	maximo = suma.at(0);

	for (int i = 1; i < suma.size(); ++i){
		if (maximo < suma.at(i)){
			sumaTotal = sumaTotal + (maximo * numMaximos);

			maximo = suma.at(i);
			numMaximos = 1;
		}

		else if (maximo == suma.at(i)){
			++numMaximos;
		}
		else {
			sumaTotal += suma.at(i);
		}

	}



	return sumaTotal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tam, componente;
	std::vector<int> suma;

	std::cin >> tam;

	for (int i = 0; i < tam; ++i){
		std::cin >> componente;
		suma.push_back(componente);
	}
	std::cout << resolver(suma) << std::endl;


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

