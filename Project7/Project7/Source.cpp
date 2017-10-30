// Grupo E67, David de los Santos Gil
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>




// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(std::vector<std::string> const & linea, int &primerPixel, int &ultimoPixel) {
	int maximo = 0, actual = 0, primerPixelActual;
	bool primero = true;

	for (int i = 0; i < linea.size(); ++i){ //Recorre los string del vector

		if (linea.at(i) == "FFFFFF"){	//Si tenemos píxel blanco y es el primero de una serie
			if (primero) primerPixelActual = i;	
			
			actual++;								
			primero = false;						
		}
		else { 
			actual = 0;								
			primero = true;
		}

		if (actual > maximo) {						
			maximo = actual;						
			primerPixel = primerPixelActual;
		}
	}
	
	if (maximo == 0){
		primerPixel = 0;
		ultimoPixel = -1;
	}
	else ultimoPixel = primerPixel + maximo - 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int lineas, pixeles, primerPixel, ultimoPixel;
	std::string pixel;
	

	std::cin >> lineas;
	std::cin >> pixeles;

	if (!std::cin)
		return false;

	for (int i = 0; i < lineas; i++){
		std::vector<std::string> linea;
		for (int j = 0; j < pixeles; j++){
			std::cin >> pixel;
			linea.push_back(pixel);
		}
		resolver(linea, primerPixel, ultimoPixel);
		std::cout << primerPixel << " " << ultimoPixel << std::endl;
	}

	std::cout << std::endl;

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