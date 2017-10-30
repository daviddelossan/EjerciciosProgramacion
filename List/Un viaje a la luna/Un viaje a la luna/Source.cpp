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
#include <string>

#include "list_eda.h"
#include "Persona.h"




// función que resuelve el problema
// comentario sobre el coste, O(f(N))


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string linea, nombre, apellido;
	int edad;
	list<Persona> listaViajeros;

	std::cin >> edad;
	std::cin >> nombre;
	std::cin >> apellido;

	Persona viajero(edad, nombre, apellido);
	while (edad != 0 && nombre != "0" && apellido != "0") {
		listaViajeros.push_back(viajero);
		Persona viajero(edad, nombre, apellido);
	}


	if (edad == 0 && nombre == "0" && apellido == "0")
		return false;

	for (auto it = listaViajeros.begin(); it != listaViajeros.end(); it++){
		std::cout << *it;
	}

	// escribir sol

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