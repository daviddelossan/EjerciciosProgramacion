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
void resolver(const std::vector <int> &Jugadores, int &maximo, int &contador) {
	int maximo = Jugadores.at(0), contador = 1;

	for (int i = 1; i < Jugadores.size(); ++i){
		if (Jugadores.at(i) > maximo){
			maximo = Jugadores.at(i);
			contador = 1;
		}
		else if (Jugadores.at(i) == maximo){
			++contador;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numJugadores, jugador, maximo, contador;

	std::vector <int> Jugadores;
	std::cin >> numJugadores;

	for (int i = 0; i < numJugadores; i++){
		std::cin >> jugador;
		Jugadores.push_back(jugador);
	}



	resolver(Jugadores, maximo, contador);

	std::cout << maximo << " " << contador << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	//std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	std::ifstream in("masejemplos.txt");
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