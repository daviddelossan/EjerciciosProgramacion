﻿// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <sstream>
#include <stdio.h>
#include <algorithm>

//
//  treemap_eda.h
//
//  Implementación de diccionarios <clave, valor> como árboles binarios de búsqueda
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 1/03/17.
//  Copyright (c) 2017 Alberto Verdejo. All rights reserved.
//

#ifndef treemap_eda_h
#define treemap_eda_h

#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>


template <class Clave, class Valor, class Comparador = std::less<Clave>>
class map {
public:
	// parejas (clave, valor)
	struct clave_valor {
		const Clave clave;
		Valor valor;
		clave_valor(Clave const& c, Valor const& v = Valor()) : clave(c), valor(v) {};
	};
	// using clave_valor = std::pair<const Clave, Valor>;
protected:
	using map_t = map<Clave, Valor, Comparador>;

	/*
	Clase nodo que almacena internamente la pareja (clave, valor)
	y punteros al hijo izquierdo y al hijo derecho.
	*/
	struct TreeNode;
	using Link = TreeNode *;
	struct TreeNode {
		clave_valor cv;
		Link iz;
		Link dr;
		TreeNode(clave_valor const& e, Link i = nullptr, Link d = nullptr) : cv(e), iz(i), dr(d) {}
	};

	// puntero a la raíz de la estructura jerárquica de nodos
	Link raiz;

	// número de parejas <clave, valor>
	size_t nelems;

	// objeto función que compara elementos
	Comparador menor;

public:

	map(Comparador c = Comparador()) : raiz(nullptr), nelems(0), menor(c) {}

	map(map_t const& other) {
		raiz = copia(other.raiz);
		nelems = other.nelems;
		menor = other.menor;
	}

	map_t & operator=(map_t const& that) {
		if (this != &that) {
			libera(raiz);
			raiz = copia(that.raiz);
			nelems = that.nelems;
			menor = that.menor;
		}
		return *this;
	}

	~map() {
		libera(raiz);
		raiz = nullptr;
	};

	void insert(clave_valor const& cv) {
		inserta(cv, raiz);
	}

	bool empty() const {
		return raiz == nullptr;
	}

	size_t size() const {
		return nelems;
	}

	bool contains(Clave const& c) const {
		return busca(c, raiz) != nullptr;
	}

	Valor const& at(Clave const& c) const {
		Link p = busca(c, raiz);
		if (p == nullptr)
			throw std::out_of_range("La clave no se puede consultar");
		return p->cv.valor;
	}

	// devuelve el valor asociado a la clave, si existe.
	// Si no existe, crea un nuevo nodo (con valor por defecto) y
	// lo devuelve.
	Valor & operator[](Clave const& c) {
		return corchete(c, raiz);
	}

	void erase(Clave const& c) {
		borra(c, raiz);
	}

	// solo para depurar (gira la cabeza)
	void print(std::ostream& o = std::cout) const {
		if (raiz != nullptr) {
			print(o, 0, raiz);
		}
		else
			o << "vacio\n";
	}

protected:

	static Link copia(Link a) {
		if (a == nullptr) return nullptr;
		else return new TreeNode(a->cv, copia(a->iz), copia(a->dr));
	}

	static void libera(Link a) {
		if (a != nullptr) {
			libera(a->iz);
			libera(a->dr);
			delete a;
		}
	}

	Link busca(Clave const& c, Link a) const {
		if (a == nullptr) {
			return nullptr;
		}
		else if (menor(c, a->cv.clave)) {
			return busca(c, a->iz);
		}
		else if (menor(a->cv.clave, c)) {
			return busca(c, a->dr);
		}
		else { // c == a->cv.clave
			return a;
		}
	}

	void inserta(clave_valor const& cv, Link & a) {
		if (a == nullptr) {
			a = new TreeNode(cv);
			++nelems;
		}
		else if (menor(cv.clave, a->cv.clave)) {
			inserta(cv, a->iz);
		}
		else if (menor(a->cv.clave, cv.clave)) {
			inserta(cv, a->dr);
		}
		else { // la clave ya está, se actualiza el valor asociado
			a->cv.valor = cv.valor;
		}
	}

	Valor & corchete(Clave const& c, Link & a) {
		if (a == nullptr) {
			a = new TreeNode(clave_valor(c));
			++nelems;
			return a->cv.valor;
		}
		else if (menor(c, a->cv.clave)) {
			return corchete(c, a->iz);
		}
		else if (menor(a->cv.clave, c)) {
			return corchete(c, a->dr);
		}
		else { // la clave ya está, se devuelve el valor asociado
			return a->cv.valor;
		}
	}

	void borra(Clave const& c, Link & a) {
		if (a != nullptr) {
			if (menor(c, a->cv.clave)) {
				borra(c, a->iz);
			}
			else if (menor(a->cv.clave, c)) {
				borra(c, a->dr);
			}
			else // c == a->cv.clave
				if (a->iz == nullptr || a->dr == nullptr) {
					Link aux = a;
					a = a->iz == nullptr ? a->dr : a->iz;
					--nelems;
					delete aux;
				}
				else { // tiene dos hijos
					subirMenor(a, a->dr, nullptr);
					--nelems;
				}
		}
	}

	static void subirMenor(Link & a, Link b, Link padre) {
		if (b->iz != nullptr) {
			subirMenor(a, b->iz, b);
		}
		else {
			if (padre != nullptr) {
				padre->iz = b->dr;
				b->dr = a->dr;
			}
			b->iz = a->iz;
			delete a;
			a = b;
		}
	}

	// imprime el árbol (solo para depurar)
	static void print(std::ostream & o, int indent, Link r) {
		if (r != nullptr) {
			print(o, indent + 2, r->dr);
			o << std::string(indent, ' ');
			o << '(' << r->cv.clave << ',' << r->cv.valor << ")\n";
			print(o, indent + 2, r->iz);
		}
	}

protected:
	// iteradores que recorren los pares <clave, valor> de menor a mayor clave
	template <class Apuntado>
	class Iterador {
	public:
		Apuntado & operator*() const {
			if (act == nullptr) throw std::out_of_range("No hay elemento a consultar");
			return act->cv;
		}

		Apuntado * operator->() const {
			return &operator*();
		}

		Iterador & operator++() {  // ++ prefijo
			next();
			return *this;
		}

		bool operator==(Iterador const& that) const {
			return act == that.act;
		}

		bool operator!=(Iterador const& that) const {
			return !(this->operator==(that));
		}

	protected:
		friend class map;
		Link act;
		std::stack<Link> ancestros;  // antecesores no visitados

									 // construye el iterador al primero
		Iterador(Link r) { act = first(r); }

		// construye el iterador al último
		Iterador() : act(nullptr) {}

		// construye el iterador a una clave concreta (para find)
		Iterador(map_t const* m, Clave const& c) {
			act = m->raiz;
			bool encontrado = false;
			while (act != nullptr && !encontrado) {
				if (m->menor(c, act->cv.clave)) {
					ancestros.push(act);
					act = act->iz;
				}
				else if (m->menor(act->cv.clave, c)) {
					act = act->dr;
				}
				else
					encontrado = true;
			}
			if (!encontrado) { // vaciamos la pila
				ancestros = std::stack<Link>();
			}
		}

		Link first(Link ptr) {
			if (ptr == nullptr) {
				return nullptr;
			}
			else { // buscamos el nodo más a la izquierda
				while (ptr->iz != nullptr) {
					ancestros.push(ptr);
					ptr = ptr->iz;
				}
				return ptr;
			}
		}

		void next() {
			if (act == nullptr) {
				throw std::out_of_range("El iterador no puede avanzar");
			}
			else if (act->dr != nullptr) { // primero del hijo derecho
				act = first(act->dr);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				act = nullptr;
			}
			else { // podemos retroceder
				act = ancestros.top();
				ancestros.pop();
			}
		}
	};

public:
	// iterador que no permite modificar el elemento apuntado
	using const_iterator = Iterador<clave_valor const>;

	const_iterator cbegin() const {
		return const_iterator(raiz);
	}
	const_iterator begin() const {
		return cbegin();
	}

	const_iterator cend() const {
		return const_iterator();
	}
	const_iterator end() const {
		return cend();
	}

	const_iterator find(Clave const& c) const {
		return const_iterator(this, c);
	}

	// iterador que sí permite modificar el elemento apuntado (su valor)
	using iterator = Iterador<clave_valor>;

	iterator begin() {
		return iterator(raiz);
	}

	iterator end() {
		return iterator();
	}

	iterator find(Clave const& c) {
		return iterator(this, c);
	}

};


template <class Clave, class Valor, class Comparador>
inline std::ostream& operator<<(std::ostream & o, map<Clave, Valor, Comparador> const& a) {
	a.print(o);
	return o;
}

#endif // treemap_eda_h



using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(map<std::string, int> antiguoDiccionario, map<std::string, int> nuevoDiccionario, 
	vector<string> &anadidos, vector<string> &eliminados, vector<string> &modificados) {
	bool encontrado = false;
	auto itA = antiguoDiccionario.begin();
	auto itN = nuevoDiccionario.begin();

	while (itA != antiguoDiccionario.end()) { //Recorremos todo el diccionario antiguo
		if (nuevoDiccionario.contains(itA->clave)) { //Si el nuevo tiene la clave del antiguo, existe
			if (nuevoDiccionario.find(itA->clave)->valor != antiguoDiccionario.find(itA->clave)->valor) 
				modificados.push_back(itA->clave); //Si no es el mismo valor, añadimos la clave a modificados
		}
		else eliminados.push_back(itA->clave); //Si no tiene la clave, la añadimos a eliminados
		++itA;
	}

	while (itN != nuevoDiccionario.end()) {
		if (!antiguoDiccionario.contains(itN->clave)) anadidos.push_back(itN->clave);
		++itN;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	map<std::string, int> antiguoDiccionario;
	map<std::string, int> nuevoDiccionario;
	vector<string> anadidos, eliminados, modificados;

	std::string clave, linea1, linea2;
	int valor;

	if (!std::cin) return;

	
	getline(cin, linea1);
	stringstream ss(linea1);

	while (ss >> clave) {
		ss >> valor;
		antiguoDiccionario.insert({ clave, valor });
	}

	
	getline(cin, linea2);

	stringstream sa(linea2);

	while (sa >> clave) {
		sa >> valor;
		nuevoDiccionario.insert({ clave, valor });
	}

	resolver(antiguoDiccionario, nuevoDiccionario, anadidos, eliminados, modificados);


	if (!eliminados.empty() || !modificados.empty() || !anadidos.empty()) {
		if (!anadidos.empty()) {
			cout << "+ ";
			for (int i = 0; i < anadidos.size(); ++i)
				cout << anadidos.at(i) << " ";
			cout << endl;
		}


		if (!eliminados.empty()) { //Eliminados
			cout << "- ";
			for (int i = 0; i < eliminados.size(); ++i)
				cout << eliminados.at(i) << " ";
			cout << endl;
		}

		if (!modificados.empty()) { //Modificados
			cout << "* ";
			for (int i = 0; i < modificados.size(); ++i)
				cout << modificados.at(i) << " ";
			cout << endl;
		}
	}
	else cout << "Sin cambios" << endl;

	cout << "----" << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	cin.get();
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}