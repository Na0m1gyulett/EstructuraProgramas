#ifndef PILA_H
#define Pila_H

#include "Nodo.h"

class Pila{
	private:
		Nodo*tope;
		int cantidad;
	public:
		Pila();
		~Pila();
		
		bool estaVacia() const;
		
		void push(int valor);
		void pop();
		int verTope() const;
		
		void mostrar() const;
		int getTamano() const;
};

#endif