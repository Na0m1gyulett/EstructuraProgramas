#ifndef MICOLA_H
#define MICOLA_H

#include <queue>

class MiCola{
	private:
		std::queue<int> cola;
	public:
		MiCola();
		
		bool estaVacia() const;
		
		void encolar(int valor);
		void desencolar();
		int verFrente() const;
		int verFinal() const;
		
		void mostrar() const;
		int getTamano() const;
};

#endif