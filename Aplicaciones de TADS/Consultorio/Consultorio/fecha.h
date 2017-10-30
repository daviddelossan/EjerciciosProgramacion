#ifndef fecha_h
#define fecha_h

class fecha {

private:
	int _dia;
	int _hora;
	int _minuto;


public:
	fecha() : _dia(0), _hora(0), _minuto(0) {};
	fecha(int dia, int hora, int minuto) {
		_dia = dia;
		_hora = hora;
		_minuto = minuto;
	}

	int getDia() {
		return _dia;
	}

	int getHora() {
		return _hora;
	}

	int getMinuto() {
		return _minuto;
	}

	bool operator<(const fecha f) const {
		return ((_dia < f._dia) || (_dia == f._dia && _hora < f._hora) || (_dia == f._dia && _hora == f._hora && _minuto < f._minuto));
	}




};



#endif