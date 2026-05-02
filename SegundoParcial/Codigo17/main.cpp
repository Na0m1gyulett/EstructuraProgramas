#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "Estudiante.h"

int main() {
	MergeSort ms;
	
	std::vector<int> enteros = {45, 12, 78, 3, 56, 23, 91, 7};
	
	std::cout<<"Enteros\n";
	std::cout<<"Antes: \n";
	ms.mostrarEnteros(enteros);
	
	ms.ordenarEnteros(enteros);
	
	std::cout<<"Despues: \n";
	ms.mostrarEnteros(enteros);
	
	std::vector<char> chars ={'z', 'a', 'm', 'b', 'x', 'e', 'k'};
	
	std::cout <<"\n Caracteres\n";
	std::cout<<"Antes: \n";
	ms.mostrarChars(chars);
	
	ms.ordenarChars(chars);
	
	std::cout<<"Despues: \n";
	ms.mostrarChars(chars);
	
	//estudiantes
	std::vector<Estudiante> estudiantes = {
		Estudiante("Ana", 8.5),
		Estudiante("Carlos", 7.2),
		Estudiante("Maria", 9.5),
		Estudiante("Luis", 6.0),
		Estudiante("Sofia", 8.8),
	};
	
	std::cout<<"\n Estudiantes(por calificación)\n";
	std::cout<< "Antes: \n";
	ms.mostrarEstudiantes(estudiantes);
	
	ms.ordenarEstudiantes(estudiantes);
	
	std::cout << "Despues: \n";
	ms.mostrarEstudiantes(estudiantes);
	
	std::cout<<"\nPresionar enter para salir";
	std::cin.get();
	
	return 0;
}