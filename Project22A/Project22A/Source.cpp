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
char resolver(std::vector<char> &presos, const int inicio, int fin) {

	if (presos.at(0) != inicio) return inicio;
	else if (presos.at(presos.size() - 1) != fin) return fin;

	if (presos.size() == 1) return inicio; //Si solo hay uno
	else if ((presos.at(presos.size() - 1) - presos.at(presos.size() - 2)) != 1)
		return (presos.at(presos.size() - 1) - 1);
	else{
		presos.pop_back();
		resolver(presos, inicio, fin - 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char inicio, fin, preso;
	std::vector<char> presos;

	std::cin >> inicio;
	std::cin >> fin;

	for (int i = 0; i < (fin - inicio); ++i){
		std::cin >> preso;
		presos.push_back(preso);
	}

	std::cout << resolver(presos, inicio, fin) << std::endl;


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