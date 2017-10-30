#ifndef bostezos_h
#define bostezos_h

#include <iostream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "treemap_eda.h"

using namespace std;

using alumno = string;

class bostezos {
private: 
	map<alumno, unsigned int> tabla;

public: 

	bostezos() {}

	void registraBostezo(alumno const& a) {
		tabla.insert(a);
	}

	void borraBostezos(alumno const &a) {
		tabla.erase(a);
	}

	unsigned int consultaNumBostezos(alumno const& a) {
		auto itA = tabla.find(a);

		if(itA == tabla.end()) throw domain_error("No hay bostezos en el sistema");
		else return itA->valor;
	}

	vector<alumno> listaAlumnos() {
		vector<alumno> lista;

		auto itA = tabla.begin();

		while (itA != tabla.end()) {
			if(itA->valor > 2) lista.push_back(itA->clave);
			++itA;
		}

		return lista;
	}

};




#endif