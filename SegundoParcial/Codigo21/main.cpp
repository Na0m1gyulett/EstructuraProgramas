#include <iostream>
#include <vector>
#include "QuickSort.h"
#include "Estudiante.h"

int main() {
	QuickSort qs;
	std::vector<int> indices;
	
	std::vector<int> enteros ={45, 12, 78, 3, 56, 23, 91, 7};
	
	std::cout<<"Enteros\n";
	std::cout<<"Original: \n";
	for (int i=0; i <(int)enteros.size(); i++)
	   std::cout <<"[" <<i<<"] -> "<<enteros[i] <<"\n";
	   
	qs.ordenarEnteros(enteros, indices);
	
	std::cout <<"Ordenado (indirecto): \n";
	qs.mostrarEnteros(enteros, indices);
	
	std::vector<char> chars = {'z', 'a', 'm', 'b', 'x', 'e', 'k'};
	
	std::cout <<"\n Caracteres\n";
	std::cout<<"Original: \n";
	for (int i=0; i <(int)chars.size(); i++)
	  std::cout<<"[" <<i<<"] ->" <<chars[i] <<"\n";
	  
	qs.ordenarChars(chars, indices);
	
	std::cout<<"Ordenado (indirecto): \n";
	qs.mostrarChars(chars, indices);
	
	std::vector<Estudiante> estudiantes ={
	    Estudiante("Ana",    8.5),
        Estudiante("Carlos", 7.2),
        Estudiante("Maria",  9.5),
        Estudiante("Luis",   6.0),
        Estudiante("Sofia",  8.8)
	};
	
	std::cout<<"\n Estudiantes (por califación) \n";
	std::cout<<"Orginal: \n";
	for(int i=0; i<(int) estudiantes.size(); i++){
		std::cout<<"[" <<i<<"] ->";
		estudiantes[i].mostrar();
	}
	
	qs.ordenarEstudiantes(estudiantes, indices);
	
	std::cout<<"\nPresiona enter para salir";
	std::cin.get();
		
	return 0;
}