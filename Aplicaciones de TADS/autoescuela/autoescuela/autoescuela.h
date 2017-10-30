#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <vector>
#include "set_eda.h"
#include "hashmap_eda.h"

using namespace std;

using alumno = string;
using profesor = string;


class autoescuela {
private:
	unordered_map<alumno, pair<profesor, unsigned int>> alumnos;
	unordered_map<profesor, set<alumno>> profesores;

public:
	autoescuela() {}

	void alta(alumno const& a, profesor const& p) {
		auto itP = profesores.find(p);
		if (itP != profesores.end()) { //Si el profesor existe
			auto itA = alumnos.find(a); //Buscamos al alumno
			if (itA != alumnos.end()) { //Si el alumno ya está dado de alta
			
				profesores.find(itA->valor.first)->valor.erase(a); //Damos de baja al alumno con el antiguo profesor
				itA->valor.first = p; //Cambiamos el profesor del alumno a p
				itP->valor.insert(a); //Insertamos al profesor el nuevo alumno

			}
			else { //Si el alumno no está dado de alta
				alumnos.insert({ a, {p, 0} });
				itP->valor.insert(a); //Y en profesores
			}
		}
		else throw domain_error("El profesor no existe");

	}

	bool es_alumno(alumno const& a, profesor const& p) {
		auto itA = alumnos.find(a);
		if (itA != alumnos.end()) {
			if (itA->valor.first == p) return true;
			else return false;
		}
		else throw domain_error("El alumno " + a + " no está matriculado");

	}

	unsigned int puntuacion(alumno const& a) {
		auto itA = alumnos.find(a);
		if (itA != alumnos.end()) {
			return itA->valor.second;
		}
		else throw domain_error("El alumno " + a + " no está matriculado");
	}

	void actualizar(alumno const& a, unsigned int n) {
		auto itA = alumnos.find(a);
		if (itA != alumnos.end()) {
			itA->valor.second += n;
		}
		else throw domain_error("El alumno " + a + " no está matriculado");
	}

	vector<alumno> examen(profesor const& p, unsigned int n) {
		vector<alumno> alumnosExamen;
		string al;

		auto itP = profesores.find(p);
		if (itP != profesores.end()) { //Si el profesor existe
			auto itA = itP->valor.begin();
			
			while (itA != itP->valor.end()) {
				al = *itA;
				if (alumnos.find(al)->valor.second >= n) alumnosExamen.push_back(al);
				++itA;
			}
		}
		else throw domain_error("El profesor " + p + " no existe");

		return alumnosExamen;
	}

	void aprobar(alumno const& a) {
		string prof;

		auto itA = alumnos.find(a);
		if (itA != alumnos.end()) {
			prof = itA->valor.first;
			alumnos.erase(a);

			auto itP = profesores.find(prof);
			itP->valor.erase(a);

		}
		else throw domain_error("El alumno " + a + " no está matriculado");
	}



};


#endif