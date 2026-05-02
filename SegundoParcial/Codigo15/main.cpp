#include <iostream>
#include "Sier.h"
#include "Triangulo.h"

int main() {

    // Nivel fijo = 4 (puedes cambiar entre 1 y 6)
    int nivelFijo = 4;

    // Crear objeto Sierpinski
    Sier figura(nivelFijo);

    // Generar el fractal con recursividad
    figura.generar();

    // Mostrar en consola
    figura.mostrar();

    // Información del objeto
    std::cout << "Nivel de recursion : " << figura.getNivel()  << "\n";
    std::cout << "Tamano del lienzo  : " << figura.getTamano() << "\n";
    
    std::cout << "\nPresiona Enter para salir...";
    std::cin.get();
    

    return 0;
}