#ifndef Complejo_h
#define Complejo_h

#include <iostream>

using namespace std;


class Complejo {


public:
	Complejo() : _parteReal(0), _parteImaginaria(0) {};
	Complejo(float parteReal, float parteImaginaria) {
		_parteReal = parteReal;
		_parteImaginaria = parteImaginaria;
	}

	Complejo operator+ (const Complejo &numComplejo) {
		Complejo suma;
		suma._parteReal = numComplejo._parteReal + _parteReal;
		suma._parteImaginaria = numComplejo._parteImaginaria + _parteImaginaria;

		return suma;
	}

	Complejo operator*(const Complejo &numComplejo) {
		Complejo producto;
		producto._parteReal = (numComplejo._parteReal * _parteReal) - (numComplejo._parteImaginaria * _parteImaginaria);
		producto._parteImaginaria = (numComplejo._parteReal * _parteImaginaria) + (numComplejo._parteImaginaria * _parteReal);

		return producto;
	}

	float modulo() {
		return sqrt((_parteReal * _parteReal) + (_parteImaginaria * _parteImaginaria));
	}

private:
	float _parteReal;
	float _parteImaginaria;

};

#endif