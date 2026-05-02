#include <iostream>
#include <vector>
#include "Burbuja.h"
#include "Estudiante.h"


int main() {
	
	Burbuja b;
	std::vector<int> indices;
	
	std::vector<int> enteros = {45, 12, 78, 3, 56, 23, 91, 7};
	
	std::cout<<"Enteros\n";
	std::cout<<"Original: \n";
	for (int i=0; i < (int) enteros.size(); i++)
	   std::cout <<"[" <<i<<"]->" <<enteros[i] <<"\n";
	   
	b.ordenarEnteros(enteros, indices);
	
	std::cout <<"Ordenado (indirecto): \n";
	b.mostrarEnteros(enteros, indices);
	
	//estudiantes
	std::vector<Estudiante> estudiantes ={
		Estudiante("Ana",    8.5),
        Estudiante("Carlos", 7.2),
        Estudiante("Maria",  9.5),
        Estudiante("Luis",   6.0),
        Estudiante("Sofia",  8.8)		
	};
	
	std::cout<<"\n Estudiantes(por calificacion)\n";
	std::cout<<"Original: \n";
	for (int i =0; i < (int)estudiantes.size(); i++) {
		std::cout<<" [" <<i<<"] ->";
		estudiantes[i].mostrar(); 
	}
	
	b.ordenarEstudiantes(estudiantes, indices);
	
	std::cout<< "Ordenado(indirecto): \n";
	b.mostrarEstudiantes(estudiantes, indices);
	
	std::cout <<"\n Presiona Enter para salir";
	std::cin.get();
	   
	return 0;
}