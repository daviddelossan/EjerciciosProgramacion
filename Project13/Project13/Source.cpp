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



// función que resuelve el problema
// comentario sobre el coste: O(n) porque solo recorro el vector una vez
void averiguaVagon(std::vector<int> const &vagones, int vagonesAsaltados, int &vagonInicial, int &valor) {
	int sumaTotal = vagones.at(0), sumaMaxima = vagones.at(0);

	for (int i = 1; i < vagones.size(); ++i){
		if (i < vagonesAsaltados){
			sumaTotal += vagones.at(i);
			sumaMaxima = sumaTotal;
		}
		else{
			sumaTotal = sumaTotal + vagones.at(i) - vagones.at(i - vagonesAsaltados);
			if (sumaMaxima <= sumaTotal){
				sumaMaxima = sumaTotal;
				vagonInicial = i - vagonesAsaltados + 1;
			}
		}
	}

	valor = sumaMaxima;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::vector<int> vagones;
	int numVagones, vagonesAsaltados, vagon, vagonInicial = 0, valor;

	std::cin >> numVagones;
	std::cin >> vagonesAsaltados;

	for (int i = 0; i < numVagones; ++i){
		std::cin >> vagon;
		vagones.push_back(vagon);
	}

	averiguaVagon(vagones, vagonesAsaltados, vagonInicial, valor);

	std::cout << vagonInicial << " " << valor << std::endl;
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