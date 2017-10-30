// Grupo E67, David de los Santos Gil

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>




void resolver(const std::vector <int> &valores, int &picos, int &valles) {
	
	if (valores.size() > 2)

	for (int i = 1; i < valores.size() - 1; ++i){
		if (valores.at(i - 1) > valores.at(i) && valores.at(i) < valores.at(i + 1)){
			valles++;
		}
		else if (valores.at(i - 1) < valores.at(i) && valores.at(i) > valores.at(i + 1)){
			picos++;
		}

	}

}


void resuelveCaso() {
	int n, valor, picos = 0, valles = 0;

	std::vector <int> valores;

	std::cin >> n;

	for (int i = 0; i < n; ++i){
		std::cin >> valor;
		valores.push_back(valor);
	}


	resolver(valores, picos, valles);

	std::cout << picos << " " << valles << std::endl;


}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	
#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}