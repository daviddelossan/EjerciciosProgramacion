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
#include <string>



// función que resuelve el problema
// comentario sobre el coste, O(f(N))
std::vector<std::vector<int>> resolver(std::vector<std::vector<int>> & matriz, int filas, int columnas, std::string componenteString) {
	int a, b, c, aux, fila, columna, i, j;

	if (componenteString == "filas"){ //Intercambio de filas
		std::cin >> a;
		std::cin >> b;

		for (int i = 0; i < columnas; ++i){
			aux = matriz[a - 1][i];
			matriz[a - 1][i] = matriz[b - 1][i];
			matriz[b - 1][i] = aux;
		}
	}

	else if (componenteString == "columnas"){ //Intercambio de columnas
		std::cin >> a;
		std::cin >> b;

		for (int i = 0; i < filas; ++i){
			aux = matriz[i][a - 1];
			matriz[i][a - 1] = matriz[i][b - 1];
			matriz[i][b - 1] = aux;
		}
	}

	else if (componenteString == "cruz"){ //Rellenar diagonales
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;

		fila = a - 1;
		columna = b - 1;
		
		i = fila;
		j = columna;
		while (i >= 0 && j >= 0){//Hacia arriba izq
			matriz[i][j] = c;
			i--;
			j--;
		}

		i = fila;
		j = columna;
		while (i >= 0 && j < columnas){//Hacia arriba der
			matriz[i][j] = c;
			i--;
			j++;
		}

		i = fila;
		j = columna;
		while (i < filas && j >= 0){//Hacia abajo izq
			matriz[i][j] = c;
			i++;
			j--;
		}

		i = fila;
		j = columna;
		while (i < filas && j < columnas){//Hacia abajo der
			matriz[i][j] = c;
			i++;
			j++;
		}



		/*
		//Diagonal hacia abajo
		if (a > b){
			fila = a - b - 1;
			columna = 0;
		}
		else if (a < b){
			fila = 0;
			columna = b - a;
		}
		else{
			fila = 0;
			columna = 0;
		}

		while (fila < filas && columna < columnas){
			matriz[fila][columna] = c;
			fila++;
			columna++;
		}

		fila = a - 1;
		columna = b - 1;

		//Diagonal hacia arriba
		if (a > b){
			fila = a + b;
			columna = 0;
		}
		else if (b < a){
			fila = 0;
			columna = b + a;
		}
		else{
			if (fila > (filas - 1) / 2){
				columna = columna - (filas - 1 - fila);
				fila = filas - 1;
			}
			else{
				fila = a + b - 2;
				columna = 0;
			}
		}

		while (fila < filas && fila >= 0 && 0 <= columna && columna < columnas){
			matriz[fila][columna] = c;
			fila--;
			columna++;
		}*/
	}

	else if (componenteString == "rotarFila"){ //Rotar fila
		std::cin >> a;

		if (a > 0){
			aux = matriz[a - 1][columnas - 1];
			for (int i = columnas - 1; i > 0; --i){
				matriz[a - 1][i] = matriz[a - 1][i - 1];
			}
			matriz[a - 1][0] = aux;
		}

		else{
			a = a * -1;
			aux = matriz[a - 1][0];
			for (int i = 0; i < columnas - 1; ++i){
				matriz[a - 1][i] = matriz[a - 1][i + 1];
			}
			matriz[a - 1][columnas - 1] = aux;
		}
	}

	else{ //Rotar columna
		std::cin >> a;

		if (a > 0){
			aux = matriz[filas - 1][a - 1];
			for (int i = filas - 1; i > 0; --i){
				matriz[i][a - 1] = matriz[i - 1][a - 1];
			}
			matriz[0][a - 1] = aux;
		}

		else{
			a = a * -1;
			aux = matriz[0][a - 1];
			for (int i = 0; i < filas - 1; ++i){
				matriz[i][a - 1] = matriz[i + 1][a - 1];
			}
			matriz[filas - 1][a - 1] = aux;
		}
	}

	return matriz;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas, columnas, elemento, numTransformaciones;
	std::string componenteString;
	

	std::cin >> filas;
	std::cin >> columnas;

	if (filas == 0 && columnas == 0) return false;

	std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){
			std::cin >> elemento;
			matriz[i][j] = elemento;
		}
	}

	std::cin >> numTransformaciones;
	std::cin.get();

	for (int k = 0; k < numTransformaciones; k++){
		std::cin >> componenteString;
		matriz = resolver(matriz, filas, columnas, componenteString);


		//QUITAR LUEGOOO
		/*for(int l = 0; l < filas; ++l){
			for (int m = 0; m < columnas; ++m){
				std::cout << matriz[l][m] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "---" << std::endl;*/
		//HASTA AQUIII
	}
	std::cin.get();

	for (int l = 0; l < filas; ++l){
		for (int m = 0; m < columnas; ++m){
			std::cout << matriz[l][m] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "---" << std::endl;

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