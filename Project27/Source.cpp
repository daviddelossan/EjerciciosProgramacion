// Grupo E67, David de los Santos Gil
//Introducimos un vector como parámetro del método resuelve, y recursivamente vamos
//haciendo una búsqueda binaria en el vector, actualizando los parámetros de inicio, fin y mitad
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// función que resuelve el problema
// comentario sobre el coste: El coste es O(log N) siendo N el número de elementos del vector,
// ya que la búsqueda binaria tiene un coste logarítmico
int resolver(std::vector<int> const & curva, int inicio, int fin, int minimoActual) {
	int mitad = (inicio + fin) / 2; //Actualizamos la mitad
	int posibleMinimo = curva.at(mitad); //Y ponemos el posible mínimo como el elemento del medio

	if (inicio > fin) return minimoActual; //Si inicio > fin hemos terminado la búsqueda

	if (posibleMinimo < minimoActual){ //Si el posible mínimo es menor, actualizamos minimoActual
		minimoActual = posibleMinimo;
	}

	if (mitad < curva.size() - 1){	//Si el valor de mitad no sobrepasa el tamaño del vector seguimos recorriendolo
		if (curva.at(mitad + 1) < posibleMinimo) //Si el de la derecha es menor
			resolver(curva, mitad + 1, fin, minimoActual); //Seguimos recorriendo la mitad derecha
		else if (curva.at(mitad + 1) > posibleMinimo) //Si el de la derecha es mayot
			resolver(curva, inicio, mitad - 1, minimoActual); //Seguimos recorriendo la mitad izquierda

	}
	else return minimoActual;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numElementos, elemento, inicio, fin, minimoActual;
	std::vector<int> curva;

	std::cin >> numElementos;

	for (int i = 0; i < numElementos; ++i){
		std::cin >> elemento;
		curva.push_back(elemento);
	}

	if (!std::cin)
		return false;

	std::cout << resolver(curva, 0, curva.size() - 1, curva.at(0)) << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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