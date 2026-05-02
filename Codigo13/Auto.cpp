#include "Auto.h"
#include <iostream>

void Auto::registrar() {
    std::cout << "Año: ";
    std::cin >> anio;
    std::cout << "Precio: ";
    std::cin >> precio;
}

void Auto::mostrar() const {
    std::cout << "(" << anio << ") - $" << precio << "\n";
}