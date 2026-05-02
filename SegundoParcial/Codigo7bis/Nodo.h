#ifndef NODO_H
#define NODO_H

class Nodo {
	private:
		int dato;
		Nodo*siguiente;
	public:
		Nodo(int dato);
		
		int getDato() const;
		Nodo*getSiguiente() const;
		void setSiguiente(Nodo*sig);
};

#endif