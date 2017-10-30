// Grupo E67, David de los Santos Gil

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


//Comprueba que cada letra es mayor a la anterior
//Coste: O(n)
bool resolver(const std::vector <char> &palabra) {
	bool ok = true;
	int i = 0;

	while ((i < palabra.size() - 1) && ok){
		if (palabra.at(i) < palabra.at(i + 1)){
			ok = true;
		}
		else ok = false;

		i++;
	}

	return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	char letra, cuentaX = 0;
	bool sol;
	std::vector <char> palabra;

	std::cin.get(letra);

	while (letra != '\n'){
		palabra.push_back(letra);

		if (letra == 'X'){
			cuentaX++;
			if (cuentaX == 3)
				return false;
		}
		std::cin.get(letra);
	}


	sol = resolver(palabra);

	if (sol) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
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