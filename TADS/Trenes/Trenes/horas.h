#ifndef Horas_h
#define Horas_h

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
using namespace std;

class Horas {
private:
	int _hora;
	int _minuto;
	int _segundo;

public:
	//Constructoras
	Horas() : _hora(0), _minuto(0), _segundo(0) {};
	Horas(int h, int m, int s) {
		if (0 <= h < 24) {
			_hora = h;
			if (0 <= m < 60) {
				_minuto = m;
				if (0 <= s < 60) {
					_segundo = s;
				}
				else throw invalid_argument("Segundos no válidos");
			}
			else throw invalid_argument("Minutos no válidos");
		}
		else throw invalid_argument("Horas no válidas");
	}

	//Operadores

	bool operator<(const Horas &h) const {
		return (_hora < h._hora || (_hora == h._hora && _minuto < h._minuto) ||
			(_hora == h._hora && _minuto == h._minuto && _segundo < h._segundo));
	}

	bool operator>(const Horas &h) const {
		return (_hora > h._hora || (_hora == h._hora && _minuto > h._minuto) ||
			(_hora == h._hora && _minuto == h._minuto && _segundo > h._segundo));
	}

	bool operator==(const Horas &h) const {
		return (_hora == h._hora && _minuto == h._minuto && _segundo == h._segundo);
	}

	//Observadores
	int getHora() const {
		return _hora;
	}
	int getMinuto() const {
		return _minuto;
	}
	int getSegundo() const {
		return _segundo;
	}


	void read(std::istream & in = std::cin) {
		char c;
		int h, m, s;

		in >> h;
		in >> c;
		in >> m;
		in >> c;
		in >> s;
	}

	void print(std::ostream& o = std::cout) const {
		o << setfill('0') << setw(2) << _hora << ':'
			<< setfill('0') << setw(2) << _minuto << ':'
			<< setfill('0') << setw(2) << _segundo;
	}

};

inline ostream & operator<<(ostream & salida, Horas const& h) {
	h.print(salida);
	return salida;
}

inline istream & operator >> (istream & entrada, Horas & h) {
	h.read(entrada);
	return entrada;
}


#endif
