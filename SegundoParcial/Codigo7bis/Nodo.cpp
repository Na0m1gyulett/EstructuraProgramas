#include "Nodo.h"

Nodo::Nodo(int dato) : dato(dato), siguiente(nullptr) {}

int Nodo::getDato() const{
	return dato;
}

Nodo*Nodo::getSiguiente() const{
	return siguiente;
}

void Nodo::setSiguiente(Nodo*sig){
	siguiente=sig;
}