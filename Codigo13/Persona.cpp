#include "Persona.h"
#include <iostream>

void Persona::registrar() {
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellido Paterno: ";
    std::cin >> apellidoPaterno;
    std::cout << "Apellido Materno: ";
    std::cin >> apellidoMaterno;
    std::cout << "Género: ";
    std::cin >> genero;
    std::cout << "Edad: ";
    std::cin >> edad;
}

void Persona::mostrar() const {
    std::cout << nombre << " " << apellidoPaterno << " " << apellidoMaterno
              << ", " << genero << ", " << edad << " años\n";
}