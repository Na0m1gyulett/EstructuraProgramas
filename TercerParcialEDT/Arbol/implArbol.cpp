#include "claseArbol.h"
#include <iostream>
#include <fstream>
using namespace std;

// Nodo
Nodo::Nodo(string n, int t, int c) : nombre(n), tiempo(t), costo(c), izquierdo(nullptr), derecho(nullptr) {}

//gestor arbol
GestorArbol::GestorArbol(string archivo) : nombreArchivo(archivo), raiz(nullptr) {}

void GestorArbol::insertar(string n, int t, int c) {
    insertarRec(raiz, n, t, c);
}

void GestorArbol::insertarRec(Nodo*& actual, string n, int t, int c) {
    if (actual == nullptr) {
        actual = new Nodo(n, t, c);
    } else if (t < actual->tiempo) {
        insertarRec(actual->izquierdo, n, t, c);
    } else {
        insertarRec(actual->derecho, n, t, c);
    }
}

void GestorArbol::preorden() const {
    preordenRec(raiz);
}

void GestorArbol::preordenRec(Nodo* actual) const {
    if (actual != nullptr) {
        cout << actual->nombre << " | Tiempo: " << actual->tiempo << " | Costo: " << actual->costo << endl;
        preordenRec(actual->izquierdo);
        preordenRec(actual->derecho);
    }
}

void GestorArbol::modificar() {
    if (raiz != nullptr) {
        raiz->costo += 5; 
    }
}

void GestorArbol::escribir() {
    ofstream archivo(nombreArchivo);
    escribirRec(raiz, archivo);
    archivo.close();
}

void GestorArbol::escribirRec(Nodo* actual, ofstream& archivo) {
    if (actual != nullptr) {
        archivo << actual->nombre << " " << actual->tiempo << " " << actual->costo << "\n";
        escribirRec(actual->izquierdo, archivo);
        escribirRec(actual->derecho, archivo);
    }
}

void GestorArbol::leer() {
    raiz = nullptr;
    ifstream archivo(nombreArchivo);
    string n;
    int t, c;
    while (archivo >> n >> t >> c) {
        insertar(n, t, c);
    }
    archivo.close();
}

