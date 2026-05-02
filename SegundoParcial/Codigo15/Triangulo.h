#include <iostream>
#include "Sier.h"

class Triangulo {
private:
		int fila;
		int columna;
		char simbolo;
public:
	Triangulo();
	Triangulo(int fila, int columna, char simbolo);
	
	int getFila() const;
	int getColumna() const;
	char getSimbolo() const;
	
	void mostrar() const;
};
#endif