#include <iostream>
#include <vector>
#include "claseJson.h"
using namespace std;

int main() {
    // perosonas inicial
    vector<Persona> lista = {
        Persona("Ana", 20, 'F'),
        Persona("Luis", 22, 'M'),
        Persona("Maria", 19, 'F')
    };

    // gestorJSON
    GestorJSON gestor("personas.json");

    // Escribir archivo inicial
    gestor.escribir(lista);

    // Leer archivo original
    vector<Persona> cargadas = gestor.leer();
    cout << "Archivo original:\n";
    for (const auto& p : cargadas) {
        p.mostrar();
    }

    // Modificar datos
    gestor.modificar(cargadas);

    // Guardar archivo modificado
    gestor.escribir(cargadas);

    // Leer archivo modificado
    vector<Persona> modificadas = gestor.leer();
    cout << "\nArchivo modificado:\n";
    for (const auto& p : modificadas) {
        p.mostrar();
    }

    return 0;
}
