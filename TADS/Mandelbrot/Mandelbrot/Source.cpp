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

#include "Complejo.h"
using namespace std;



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
Complejo Mandelbrot(int numIteraciones, Complejo numComplejo, bool &pertenece) {
	Complejo z, mandel;

	if (numIteraciones == 0) {
		return Complejo(0, 0);
	}
	else {
		mandel = Mandelbrot(--numIteraciones, numComplejo, pertenece);
		z = mandel * mandel + numComplejo;
		if (z.modulo() > 2.0 && pertenece) {
			pertenece = false;
			return{};
		}
		else return z;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	float parteReal, parteImaginaria;
	int numIteraciones;
	bool pertenece = true;

	cin >> parteReal >> parteImaginaria >> numIteraciones;
	 
	Complejo numeroComplejo(parteReal, parteImaginaria);
	Mandelbrot(numIteraciones, numeroComplejo, pertenece);

	if (pertenece) cout << "SI" << endl;
	else cout << "NO" << endl;
	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
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