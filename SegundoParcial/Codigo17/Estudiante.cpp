#include "Estudiante.h"
#include <iostream>

Estudiante::Estudiante() : nombre(""), calificacion(0.0) {}

Estudiante::Estudiante(std::string nombre, float calificacion)
    :nombre(nombre), calificacion(calificacion) {}
    
std::string Estudiante::getNombre() const { return nombre; }
float Estudiante::getCalificacion() const { return calificacion; }

void Estudiante::mostrar() const {
	std::cout << " " <<nombre << " -> " <<calificacion <<"\n";
} 