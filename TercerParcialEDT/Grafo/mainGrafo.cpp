#include <iostream>
#include "claseGrafo.h"
using namespace std;

int main() {
    GestorGrafo grafo("grafo.txt");

    // Nodos y aristas iniciales
    grafo.agregarNodo("A");
    grafo.agregarNodo("B");
    grafo.agregarNodo("C");

    grafo.agregarArista("AB");
    grafo.agregarArista("BC");

    // Conexiones con tiempo y costo
    grafo.agregarConexion("A", "B", "AB", 5, 10);
    grafo.agregarConexion("B", "C", "BC", 7, 20);

    // Mostrar grafo original
    cout << "Grafo original:\n";
    grafo.mostrar();

    // Modificar
    grafo.modificar();

    // Mostrar grafo modificado
    cout << "\nGrafo modificado:\n";
    grafo.mostrar();

    return 0;
}
