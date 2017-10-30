#ifndef videoclub_h
#define videoclub_h

#include <iostream>
#include <vector>

#include "hashmap_eda.h"

using namespace std;

using socio = string;
using pelicula = string;

class videoclub{
private:
	using info_peli = pair<unsigned int, unsigned int>;
	unordered_map<pelicula, info_peli> pelis;
	using alquiladas_t = vector<pelicula>;
	unordered_map<socio, alquiladas_t> socios;



public:
	videoclub() {}

	void insertarPeli(pelicula const& pel) {
		pelis.insert(pel);
	}

	void anadirSocio(socio const& soc) {
		socios.insert(soc);
	}

	void alquilar(socio const& soc, pelicula const& pel) {
		auto itP = pelis.find(pel);
		if (itP != pelis.end()) {
			if (itP->valor.first > 0) {
				itP->valor.first--;
				auto itS = socios.find(soc);
				if (itS != socios.end()) {
					itS->valor.push_back(pel);
				}
			}
			else throw domain_error("Todas las copias están alquiladas");
		}
		else throw domain_error("La pelicula no existe");
	}

	void devolver(socio const& soc, pelicula const& pel) {
		auto itS = socios.find(soc);
		if (itS != socios.end()) {
			//itS->valor.find(pel);
			//if(itS != valor.end())
			auto itP = pelis.find(pel);
			if (itP != pelis.end()) {
				if (itP->valor.second > 0) {
				//	itS->valor.erase(pel);
					--itP->valor.second;
				}
				else throw domain_error("Esa película no está alquilada");
			}
			else throw domain_error("La pelicula no existe");


			//else throw domain_error("Error. La película no está alquilada por ese socio");
		}
		else throw domain_error("Error. El socio no existe");
	}

};


#endif



