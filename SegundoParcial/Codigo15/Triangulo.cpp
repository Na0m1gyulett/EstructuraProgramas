#include "Triangulo.h"
#include <iostream>

Triangulo::Triangulo() : fila(0), columna(0), simbolo('*') {}
Triangulo::Triangulo(int fila, int columna, char simbolo)
    :fila(fila), columna(columna), simbolo(simbolo) {}
    
int Triangulo::getFila() const { return fila;}
int Triangulo::getColumna() const { return columna;}
char Triangulo::getSimbolo() const {return simbolo;}

void Triangulo::mostrar() const {
	std::cout<<"Triangulo en fila: "<<fila
	         <<", columna: " <<columna
	         <<", simbolo:" <<simbolo << '*';
}


	
