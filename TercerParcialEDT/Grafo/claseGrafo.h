#ifndef CLASEGRAFO_H
#define CLASEGRAFO_H

#include <string>
#include <vector>
using namespace std;

// Clase para representar una conexión
class ConexionNodo2Nodo {
public:
    string nodoInicial;
    string nodoFinal;
    string aristaConexion;
    int tiempo;
    int costo;

    ConexionNodo2Nodo(string ni="", string nf="", string ac="", int t=0, int c=0);
};

// Clase GestorGrafo
class GestorGrafo {
private:
    string nombreArchivo;
    vector<string> nodos;
    vector<string> aristas;
    vector<ConexionNodo2Nodo> rutas;

public:
    GestorGrafo(string archivo);
    void agregarNodo(string n);
    void agregarArista(string a);
    void agregarConexion(string ni, string nf, string ac, int t, int c);
    void mostrar() const;
    void modificar();
    void escribir();
    void leer();
};

#endif

