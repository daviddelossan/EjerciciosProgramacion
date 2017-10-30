//
//  list_eda.h
//
//  Implementación del TAD lista heredando de colas dobles
//  y con iteradores
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 6/12/16.
//  Copyright (c) 2016 Alberto Verdejo. All rights reserved.
//

#ifndef list_eda_h
#define list_eda_h

#include <stdexcept>
#include <cassert>
#include <iterator>

#include "deque_eda.h"

template <class T>
class list : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:

	// constructor: lista vacía
	list() {}

	// consultar el elemento en la posición ind, si existe (numeradas desde 0)
	T const& at(size_t ind) const {
		if (ind >= this->nelems)
			throw std::out_of_range("posicion fuera de la lista");

		Nodo* aux = this->fantasma->sig;
		for (size_t i = 0; i < ind; ++i)
			aux = aux->sig;

		return aux->elem;
	}

	


	/*
	Iteradores que permiten recorrer la lista pero no cambiar sus elementos.
	*/
	class const_iterator {
	public:
		T const& operator*() const {
			if (act == fan) throw std::out_of_range("fuera de la lista");
			return act->elem;
		}

		T const* operator->() const {
			return &(act->elem);
		}

		const_iterator & operator++() {
			if (act == fan) throw std::out_of_range("fuera de la lista");
			act = act->sig;
			return *this;
		}

		const_iterator operator++(int) {
			const_iterator ret(*this);
			operator++();
			return ret;
		}

		bool operator==(const_iterator const& that) const {
			return act == that.act;
		}

		bool operator!=(const_iterator const& that) const {
			return !(*this == that);
		}

		

	protected:
		// para que list pueda construir objetos del tipo iterador
		friend class list;

		// constructora privada
		const_iterator(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}

		// puntero al nodo actual del recorrido
		Nodo* act;
		// puntero al nodo fantasma (para saber cuándo estamos fuera)
		Nodo* fan;
	};

	// devuelve un iterador constante al principio de la lista
	const_iterator cbegin() const {
		return const_iterator(this->fantasma->sig, this->fantasma);
	}

	// devuelve un iterador constante al final del recorrido y fuera de este
	const_iterator cend() const {
		return const_iterator(this->fantasma, this->fantasma);
	}

	/*
	Iteradores que permiten recorrer la lista y cambiar sus elementos
	*/
	class iterator : public const_iterator {
	public:
		T & operator*() {
			if (this->act == this->fan) throw std::out_of_range("fuera de la lista");
			return this->act->elem;
		}
		T * operator->() {
			return &(this->act->elem);
		}

	protected:
		friend class list;
		iterator(Nodo* ac, Nodo* fa) : const_iterator(ac, fa) {}
	};

	// devuelve un iterador al principio de la lista
	iterator begin() {
		return iterator(this->fantasma->sig, this->fantasma);
	}
	const_iterator begin() const {
		return const_iterator(this->fantasma->sig, this->fantasma);
	}

	// devuelve un iterador al final del recorrido y fuera de este
	iterator end() {
		return iterator(this->fantasma, this->fantasma);
	}
	const_iterator end() const {
		return const_iterator(this->fantasma, this->fantasma);
	}

	// inserta un elemento delante del apuntado por el iterador
	iterator insert(iterator const& it, T const& elem) {
		assert(this->fantasma == it.fan); // comprueba que el iterador es de esta lista
		Nodo* nuevo = this->inserta_elem(elem, it.act->ant, it.act);
		++this->nelems;
		return iterator(nuevo, this->fantasma);
	}

	// elimina el elemento apuntado por el iterador
	iterator erase(iterator const& it) {
		assert(this->fantasma == it.fan); // comprueba que el iterador es de esta lista
		if (it.act == this->fantasma)
			throw std::out_of_range("fuera de la lista");
		iterator next(it.act->sig, this->fantasma);
		this->borra_elem(it.act);
		--this->nelems;
		return next;
	}
};

#endif // list_eda_h