#include <iostream>
#include "claseDigrafo.h"
using namespace std;

int main() {
    GestorDigrafo digrafo("digrafo.txt");

    // nodos, aristas iniciales
    digrafo.agregarNodo("A");
    digrafo.agregarNodo("B");
    digrafo.agregarNodo("C");

    digrafo.agregarArista("AB");
    digrafo.agregarArista("BC");

    // Conexiones
    digrafo.agregarConexion("A", "B", "AB", 5, 10);
    digrafo.agregarConexion("B", "C", "BC", 7, 20);

    cout << "Digrafo original:\n";
    digrafo.mostrar();

    digrafo.modificar();

    cout << "\nDigrafo modificado:\n";
    digrafo.mostrar();

    return 0;
}
