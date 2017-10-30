#ifndef consultorio_h
#define consultorio_h

#include <iostream>
#include "fecha.h"
#include "hashmap_eda.h"
#include "treemap_eda.h"

using namespace std;

struct nombreFecha {
	string nombre;
	vector<fecha> fechasCita;
};

using medico = string;
using paciente = string;



class consultorio {

private:
	unordered_map<medico, map<fecha, paciente>> consult; 

public:
	consultorio() {}

	void nuevoMedico(medico const& nuevoMed) {
		if (!consult.contains(nuevoMed)) consult.insert(nuevoMed);
	}

	void pideConsulta(paciente const& p, medico const& m, fecha const& f) {
		if (!consult.contains(m)) throw std::domain_error("Medico no existente");
		if (consult.find(m)->valor.contains(f)) throw std::domain_error("Fecha ocupada");
	}

	paciente siguientePaciente(medico const& m) {
		
		auto itC = consult.find(m); //El itC apunta al medico
		auto itF = itC->valor.begin(); //El itF apunta al valor que tiene el medico (hashmap de fechas(clave) y pacientes(valor))

		
		fecha minimaFecha = itF->clave; //Inicializamos la minimaFecha a la primera Fecha
		paciente siguientePaciente = itF->valor;

		while (itF != itC->valor.end()) { //Mientras que no lleguemos al final de las fechas
			if (itF->clave < minimaFecha) {//Comprobamos si la actual es menor que la mínima
				minimaFecha = itF->clave;  //Si es así, actualizamos minimaFecha
				siguientePaciente = itF->valor; //Y el siguientePaciente
			}
			++itF; //Avanzamos
		}
		
	}

	void atiendeConsulta(medico const& m) {
		if (!consult.contains(m)) throw domain_error("Medico no existente");
		auto itP = consult.find(m)->valor.begin();
		while (itP != consult.find(m)->valor.end()) {

		}
	}



};



#endif