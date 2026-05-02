#include "Cola.h"
#include <iostream>

Cola::Cola() : frente(0), final(-1), cantidad(0) {}

bool Cola::estaVacia() const {
	return cantidad==0;
}

bool Cola::estaLlena() const{
	return cantidad==MAXIMO;
}

void Cola::encolar(int valor){
	if(estaLlena()){
		std::cout<<"[!] Cola llena, no se puede encolar" <<valor<<"\n";
		return;
	}
	final =(final+1) % MAXIMO;
	datos[final]=valor;
	cantidad++;
	std::cout<<"[!]Encolado: "<<valor<<"\n";
}

void Cola::desencolar(){
	if(estaVacia()){
		std::cout<<"[!] Cola vacia, no se puede desencolar\n";
		return;
	}
	    std::cout<<"[-]Desencolado: "<<datos[frente]<<"\n";
		frente =(frente+1) % MAXIMO;
		cantidad--;
	}
int Cola::verFrente() const{
	if(estaVacia()){
		std::cout<<"[!] Cola vacia\n";
		return -1;
	}
	return datos[frente];
}

void Cola::mostrar() const {
	if(estaVacia()){
		std::cout<<"[!] Cola vacia\n";
		return;
	}
	std::cout<<"Frente ->";
	for(int i =0; i <cantidad; i++){
		int pos=(frente +i) %MAXIMO;
		std::cout<<datos[pos];
		if(i<cantidad -1) std::cout<<"│";
	}
	std::cout<<"<-Final\n";
}
int Cola::getTamano() const{
	return cantidad;
}
 