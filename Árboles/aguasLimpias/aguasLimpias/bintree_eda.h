//
//  bintree_eda.h
//
//  Implementaci�n de �rboles binarios (con compartici�n de nodos)
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 20/01/17.
//  Copyright (c) 2017 Alberto Verdejo. All rights reserved.
//

#ifndef bintree_eda_h
#define bintree_eda_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>

template <typename T>
class bintree {
public:
	// �rbol vac�o
	bintree() : root_(nullptr) {}

	// �rbol hoja
	bintree(T const& e) :
		root_(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// �rbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		root_(std::make_shared<TreeNode>(l.root_, e, r.root_)) {}

	// constructora por copia, operador de asignaci�n y destructora por defecto

	// consultar si el �rbol est� vac�o
	bool empty() const { return root_ == nullptr; }

	// consultar la ra�z
	T const& root() const {
		if (empty()) throw std::domain_error("El �rbol vac�o no tiene ra�z.");
		else return root_->elem_;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El �rbol vac�o no tiene hijo izquierdo.");
		else return bintree<T>(root_->left_);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El �rbol vac�o no tiene hijo derecho.");
		else return bintree(root_->right_);
	}

	bintree<T> leerArbol(int vacio) {
		T raiz;
		std::cin >> raiz;
		if (raiz == vacio) { // es un �rbol vac�o
			return{};
		}
		else { // leer recursivamente los hijos
			auto iz = leerArbol(vacio);
			auto dr = leerArbol(vacio);
			return{ iz, raiz, dr };
		}
	}

protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vac�o (no existe).
	*/
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : left_(l), elem_(e), right_(r) {};
		T elem_;
		Link left_, right_;
	};

	// constructora privada
	bintree(Link const& r) : root_(r) {}

	// puntero a la ra�z del �rbol
	Link root_;


public:

	// recorridos

	std::vector<T> preorder() {
		std::vector<T> pre;
		preorder(root_, pre);
		return pre;
	}

	std::vector<T> inorder() {
		std::vector<T> in;
		inorder(root_, in);
		return in;
	}

	std::vector<T> postorder() {
		std::vector<T> post;
		postorder(root_, post);
		return post;
	}

	std::vector<T> levelorder() {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(root_);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem_);
				if (sig->left_ != nullptr)
					pendientes.push(sig->left_);
				if (sig->right_ != nullptr)
					pendientes.push(sig->right_);
			}
		}
		return levels;
	}

protected:
	void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem_);
			preorder(a->left_, pre);
			preorder(a->right_, pre);
		}
	}

	void inorder(Link a, std::vector<T> & in) {
		if (a != nullptr) {
			inorder(a->left_, in);
			in.push_back(a->elem_);
			inorder(a->right_, in);
		}
	}

	void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left_, post);
			postorder(a->right_, post);
			post.push_back(a->elem_);
		}
	}

public:
	// iterador que recorre el �rbol en inorden
	class const_iterator {
	public:
		T const& operator*() const { return ptr_->elem_; }

		bool operator==(const_iterator const& other) const {
			return ptr_ == other.ptr_;
		}
		bool operator!=(const_iterator const& other) const {
			return !(this->operator==(other));
		}

		const_iterator & operator++() {
			next();
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator ret(*this);
			operator++();
			return ret;
		}

	protected:
		friend class bintree;
		Link ptr_;
		std::stack<Link> ancestors;

		const_iterator() : ptr_(nullptr) {}
		const_iterator(Link act) { ptr_ = first(act); }

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left_ != nullptr) {
					ancestors.push(act);
					act = act->left_;
				}
				return act;
			}
		}

		void next() {
			if (ptr_ == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr_->right_ != nullptr) {
				ptr_ = first(ptr_->right_);
			}
			else if (ancestors.empty()) {
				ptr_ = nullptr;
			}
			else {
				ptr_ = ancestors.top();
				ancestors.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(root_);
	}
	const_iterator end() const {
		return const_iterator(nullptr);
	}

};


#endif // bintree_eda_h#pragma once
