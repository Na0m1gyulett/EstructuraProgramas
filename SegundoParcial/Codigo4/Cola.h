#ifndef COLA_H
#define COLA_H

const int MAXIMO=5;

class Cola {
	private:
		int datos[MAXIMO];
		int frente;
		int final;
		int cantidad;
	public:
		Cola();
		
		bool estaVacia() const;
		bool estaLlena() const;
		
		void encolar(int valor);
		void desencolar();
		int verFrente() const;
		
		void mostrar() const;
		int getTamano() const;
};
 #endif