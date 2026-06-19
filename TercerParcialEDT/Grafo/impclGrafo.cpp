#include "claseGrafo.h"
#include <iostream>
#include <fstream>
using namespace std;

// conexion
ConexionNodo2Nodo::ConexionNodo2Nodo(string ni, string nf, string ac, int t, int c)
    : nodoInicial(ni), nodoFinal(nf), aristaConexion(ac), tiempo(t), costo(c) {}

// GestorGrafo
GestorGrafo::GestorGrafo(string archivo) : nombreArchivo(archivo) {}

void GestorGrafo::agregarNodo(string n) { nodos.push_back(n); }
void GestorGrafo::agregarArista(string a) { aristas.push_back(a); }
void GestorGrafo::agregarConexion(string ni, string nf, string ac, int t, int c) {
    rutas.push_back(ConexionNodo2Nodo(ni, nf, ac, t, c));
}

void GestorGrafo::mostrar() const {
    cout << "Nodos:\n";
    for (auto& n : nodos) cout << n << " ";
    cout << "\n\nAristas:\n";
    for (auto& a : aristas) cout << a << " ";
    cout << "\n\nRutas:\n";
    for (auto& r : rutas) {
        cout << r.nodoInicial << " -> " << r.nodoFinal
             << " | Arista: " << r.aristaConexion
             << " | Tiempo: " << r.tiempo
             << " | Costo: " << r.costo << endl;
    }
}

void GestorGrafo::modificar() {
    // modificación
    rutas.push_back(ConexionNodo2Nodo("C", "A", "CA", 8, 15));
    if (!rutas.empty()) rutas[0].costo += 5;
}

void GestorGrafo::escribir() {
    ofstream archivo(nombreArchivo);
    for (auto& r : rutas) {
        archivo << r.nodoInicial << " " << r.nodoFinal << " "
                << r.aristaConexion << " " << r.tiempo << " " << r.costo << "\n";
    }
    archivo.close();
}

void GestorGrafo::leer() {
    rutas.clear();
    ifstream archivo(nombreArchivo);
    string ni, nf, ac;
    int t, c;
    while (archivo >> ni >> nf >> ac >> t >> c) {
        rutas.push_back(ConexionNodo2Nodo(ni, nf, ac, t, c));
    }
    archivo.close();
}
