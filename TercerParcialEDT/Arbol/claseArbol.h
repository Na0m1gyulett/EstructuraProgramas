#ifndef CLASEARBOL_H
#define CLASEARBOL_H

#include <string>
#include <fstream>
using namespace std;

// nodo
class Nodo {
public:
    string nombre;
    int tiempo;
    int costo;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(string n="", int t=0, int c=0);
};

// Clase GestorArbol
class GestorArbol {
private:
    string nombreArchivo;
    Nodo* raiz;

    void insertarRec(Nodo*& actual, string n, int t, int c);
    void preordenRec(Nodo* actual) const;
    void escribirRec(Nodo* actual, ofstream& archivo);

public:
    GestorArbol(string archivo);
    void insertar(string n, int t, int c);
    void preorden() const;
    void modificar();
    void escribir();
    void leer();
};

#endif
