#include <iostream>
#include "claseArbol.h"
using namespace std;

int main() {
    GestorArbol arbol("arbol.txt");

    // Insertar nodos en el árbol binario
    arbol.insertar("A", 5, 10);
    arbol.insertar("B", 3, 7);
    arbol.insertar("C", 8, 12);

    cout << "Árbol original (preorden):\n";
    arbol.preorden();

    // Modificar árbol
    arbol.modificar();

    cout << "\nÁrbol modificado (preorden):\n";
    arbol.preorden();

    return 0;
}
