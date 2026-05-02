#ifndef SIER_H
#define SIER_h

#include "Triangulo.h"
#include <vector>
#include <string>

class Sier {
	private:
		int nivel;
		int tamano;
		std::vector<std::string> lienzo;
		
		void dibujarTriangulo(int fila, int columna, int tam);
		void inicializarLienzo();
	public:
		Sier(int nivel);
		
		void generar();
		void mostrar() const;
		int getNivel() const;
		int getTamano() const;
};

#endif