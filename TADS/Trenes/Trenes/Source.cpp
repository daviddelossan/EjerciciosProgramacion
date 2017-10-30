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
#include "horas.h"



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(std::vector<Horas> const horario, std::vector<Horas> const horasAConsultar) {
	bool encontrado;
	int j;
	Horas horaAMostrar;

	for (int i = 0; i < horasAConsultar.size(); ++i) { //Recorremos todos los trenes
		encontrado = false;

		j = 0;
		while (!encontrado && j < horario.size()) { //Y para cada tren, vemos el horario que le conviene

			if (horasAConsultar.at(i) < horario.at(j)) {
				encontrado = true;
				horaAMostrar = horario.at(j);
			}
		}

		std::cout << horaAMostrar;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numTrenes, numHoras;
	std::vector<Horas> horario, horasAConsultar;
	Horas hora;

	std::cin >> numTrenes;
	std::cin >> numHoras;


	if (numTrenes == 0 && numHoras == 0)
		return false;

	for (int i = 0; i < numTrenes; ++i) {
		cin >> hora;
		horario.push_back(hora);
	}

	for (int i = 0; i < numHoras; ++i) {
		cin >> hora;
		horasAConsultar.push_back(hora);
	}


	resolver(horario, horasAConsultar);


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}