#ifndef bostezos_y_mas_h
#define bostezos_y_mas_h

#include <iostream>
#include "treemap_eda.h"
#include "hashmap_eda.h"
using namespace std;


using alumno = string;
using falta = string;

class bostezos_y_mas {
private:
	using info_alumno = pair<unsigned int, unordered_map<falta, unsigned int>>;
		map<alumno, info_alumno> tabla;

public:
	bostezos_y_mas() {}

	void registrarFalta(falta const& f, alumno const& a) {
		info_alumno & info = tabla[a];
		++info.first;
		++info.second[f];
		
		/*auto itA = lista.find(a);
		if (itA->valor.second.contains(f)) itA->valor.second.find(f)->valor++;
		else itA->valor.second.insert(f);*/
	}
	
	void borrarFalta(falta const& f, alumno const& a) {
		auto itA = tabla.find(a); //Alumno e infoAlumno

		if (itA != tabla.end()) {
			auto itF = itA->valor.second.find(f); //La falta y el número de veces que se ha cometido
			if (itF != itA->valor.second.end()) {
				itA->valor.first -= itF->valor;
				if (itA->valor.first > 0) itA->valor.second.erase(f);
				else tabla.erase(a);
			}
		}
	}

	unsigned int cantidadFalta(falta const& f, alumno const& a) {
		auto itA = tabla.find(a);

		if (itA != tabla.end()) {
			auto itF = itA->valor.second.find(f);
			if (itF != itA->valor.second.end()) {
				return itF->valor;
			}
		}
		return 0;
	}

	unsigned int cantidad(alumno const& a) {
		auto itA = tabla.find(a);
		if (itA != tabla.end()) {
			return itA->valor.first;
		}
		else return 0;
	}

	vector<alumno> cantidadFalta(falta const &f, unsigned int n) {
		vector<alumno> resultado;
		
		for (auto const &par : tabla) {
			auto itF = par.valor.second.find(f);
			if (itF != par.valor.second.end() && itF->valor >= n) {
				resultado.push_back(par.clave);
			}
		}
		return resultado;
	}
};






#endif