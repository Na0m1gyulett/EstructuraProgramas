#include <iostream>
#include "Cola.h"

int main() {
	
	Cola cola;
	int opcion, valor;
	
	do {
	    std::cout << "\n==MENU COLA==\n";
        std::cout << "1. Encolar (agregar)\n";
        std::cout << "2. Desencolar (eliminar)\n";
        std::cout << "3. Ver frente\n";
        std::cout << "4. Mostrar cola\n";
        std::cout << "5. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        
        switch (opcion){
        	case 1:
        		if(cola.estaLlena()) {
        			std::cout<<"[!] Cola llena "<<MAXIMO<<"elementos)\n";
				} else {
					std::cout<<"Valor a encolar: ";
					std::cin>>valor;
					cola.encolar(valor);
				}
				break;
				
			case 2:
			    cola.desencolar();
				break;
			case 3:
			    if(!cola.estaVacia())
				  std::cout<<"Frente: " <<cola.verFrente()<<"\n";
				break;
			case 4:
				std::cout<<"Cola actual ("<<cola.getTamano()
				<<"/"<<MAXIMO<<"):\n";
				cola.mostrar();
				break;
		    case 5:
		    	std::cout<<"Saliendo\n";
		    	break;
		    default:
		    	std::cout<<"[!] Opcion invalida\n";
		}
	} while (opcion !=5);
	
	return 0;
}