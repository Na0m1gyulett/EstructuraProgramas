#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
	private:
		Nodo*cabeza;
		Nodo*cola;
		int cantidad;
	public:
		Lista();
		~Lista();
		
		bool estaVacia() const;
		
		void insertarInicio(int valor);
		void insertarFinal(int valor);
		void insertarPos(int valor, int pos);
		
		void eliminarInicio();
		void eliminarFinal();
		void eliminarValor(int valor);
		
		bool buscar(int valor) const;
		void mostrar() const;
		int getTamano() const;
};

#endif