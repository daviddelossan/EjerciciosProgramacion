#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


class Polinomio {
public:

	Polinomio() : _pol(){}
	Polinomio(vector<pair<int, int>> polinomio){
		_pol = polinomio;
	}

	void insert(pair<int, int> monomio) {
		_pol.push_back(monomio);
	}

	int evaluar(int valor) {
		int sumaTotal = 0;

		for (int i = 0; i < _pol.size(); ++i) {
			sumaTotal += _pol.at(i).first * elevar(valor, _pol.at(i).second);
		}

		return sumaTotal;
	}

	int elevar(const int valor, int exponente) {
		int resultado = 1;

		while (exponente > 0) {
			resultado *= valor;
			exponente--;
		}

		return resultado;
	}

private:
	vector<pair<int, int>> _pol;
	
};