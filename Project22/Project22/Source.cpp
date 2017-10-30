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
void encuentraFugado(std::vector<int> const & presidiarios, const int primerPresidiario, int contador, int &resultado) {
	if ((primerPresidiario + contador) != presidiarios.at(contador))
		resultado = presidiarios.at(contador) - 1;
	else encuentraFugado(presidiarios, primerPresidiario, contador + 1, resultado);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int primerPresidiario, ultimoPresidiario, numPresidiarios, presidiario, contador = 1, resultado = 0;
	std::vector<int> presidiarios;


	std::cin >> primerPresidiario;
	std::cin >> ultimoPresidiario;

	numPresidiarios = ultimoPresidiario - primerPresidiario;

	for (int i = 0; i < numPresidiarios; ++i){
		std::cin >> presidiario;
		presidiarios.push_back(presidiario);
	}


	presidiario = presidiarios.at(1);
	encuentraFugado(presidiarios, primerPresidiario, contador, resultado);
	std::cout << resultado << std::endl;
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