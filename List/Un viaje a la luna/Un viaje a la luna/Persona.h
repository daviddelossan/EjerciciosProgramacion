#ifndef Persona_h
#define Persona_h

#include <iostream>

class Persona{
public:
	Persona(int edad, std::string nombre, std::string apellido):  _edad(edad), _nombre(nombre), _apellido(apellido) {}

	int getEdad() {
		return _edad;
	}

	std::string getNombreCompleto() {
		std::string nombreCompleto = _nombre + " " + _apellido;
		return nombreCompleto;
	}

	void mostrarPersona() {
		std::cout << _edad << _nombre << _apellido;
	}

	void print(std::ostream& o = std::cout) const {
		if(25 < _edad < 60) o << _edad << _nombre << _apellido;
		else o << "-------";
	}

	

private:
	std::string _nombre;
	std::string _apellido;
	int _edad;
};

inline std::ostream & operator<<(std::ostream & salida, Persona const& p) {
	p.print(salida);
	return salida;
}

#endif