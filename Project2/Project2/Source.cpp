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
bool resolver(const std::vector <int> &valores, int p) {
	int maximo, ok = true, i = 0;

	maximo = valores.at(0);

	while (i < valores.size() && ok){
		if (i > p){
			if (valores.at(i) <= maximo){
				ok = false;
			}
		}
		else{
			if (valores.at(i) > maximo){
				maximo = valores.at(i);
			}
		}
		++i;
	}
	return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n, p, valor;
	bool ok;
	// leer los datos de la entrada
	std::vector <int> valores;

	std::cin >> n;
	std::cin >> p;

	for (int i = 0; i < n; ++i){
		std::cin >> valor;
		valores.push_back(valor);
	}


	ok = resolver(valores, p);
	if (ok) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("02EntradaEjemplo.txt");
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