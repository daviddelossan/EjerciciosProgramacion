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
// comentario sobre el coste, O(f(N))
int resolver(std::vector<int> const & valores) {
	int p = 0, maxTotal, maxHastaP, i = 1;

	maxTotal = valores.at(0);
	maxHastaP = maxTotal;

	while (i < valores.size()){
		if (valores.at(i) > maxTotal) maxTotal = valores.at(i);
		else if (valores.at(i) <= maxHastaP){
			p = i;
			maxHastaP = maxTotal;
		}
		++i;
	}

	return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::vector<int> valores;
	int n, valor;
	// leer los datos de la entrada
	std::cin >> n;

	for (int i = 0; i < n; ++i){
		std::cin >> valor;
		valores.push_back(valor);
	}

	std::cout << resolver(valores) << std::endl;


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