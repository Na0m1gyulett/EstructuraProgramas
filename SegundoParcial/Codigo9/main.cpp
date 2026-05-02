#include <iostream>
#include "MiCola.h"

int main() {
	
	MiCola cola;
	int opcion, valor;
	
	do {
	    std::cout << "\n====== MENU COLA STL ======\n";
        std::cout << "1. Encolar  (agregar)\n";
        std::cout << "2. Desencolar (eliminar)\n";
        std::cout << "3. Ver frente\n";
        std::cout << "4. Ver final\n";
        std::cout << "5. Mostrar cola\n";
        std::cout << "6. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        
        switch(opcion){
        	case 1:
        		std::cout<<"Valor a encolar: ";
        		std::cin>>valor;
        		cola.encolar(valor);
        		break;
        		
        	case 2:
        		cola.desencolar();
        		break;
        		
        	case 3:
        		if(!cola.estaVacia())
        		   std::cout<<"Frente: " <<cola.verFrente() <<"\n";
        		   break;
        		   
        	case 4:
        		if(!cola.estaVacia())
        		  std::cout<<"Final: "<<cola.verFinal()<<"\n";
        	break;
        	
        	case 5:
        	  std::cout<<"Cola actual ("
			  <<cola.getTamano() <<"elementos):\n";
			  cola.mostrar();
			break;
			
			case 6:
				std::cout<<"Saliendo\n";
				break;
			default:
				std::cout<<"[!] Opcion invalida\n";
		}
	}while (opcion !=6);
	
	return 0;
}