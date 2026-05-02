#include <iostream>
#include "Pila.h"

int main() {
	
	Pila pila;
	int opcion, valor;
	
	do {
        std::cout << "\n====== MENU PILA ======\n";
        std::cout << "1. Push  (agregar)\n";
        std::cout << "2. Pop   (eliminar)\n";
        std::cout << "3. Ver tope\n";
        std::cout << "4. Mostrar pila\n";
        std::cout << "5. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;	
		 switch(opcion){
		 	
		 	case 1:
		 		std::cout<<"Valor a agregar: ";
		 		std::cin>>valor;
		 		pila.push(valor);
		 		break;
		 		
		 	case 2:
		 		pila.pop();
		 		break;
		 		
		 	case 3:
		 		if(!pila.estaVacia())
		 		std::cout<<"Tope: "<<pila.verTope()<<"\n";
		 		break;
		 	case 4:
		 		std::cout<<"Pila actual ("
		 		<<pila.getTamano()<<"elementos): \n";
		 		pila.mostrar();
		 		break;
		 	case 5:
		 		std::cout<<"Saliendo\n";
		 		break;
		 	default:
		 		std::cout<<"[!] opcion invalida\n";
		 }
		} while (opcion !=5);
		
	return 0;
}