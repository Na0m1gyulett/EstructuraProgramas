#include <iostream>
#include <vector>
#include "claseXml.h"
using namespace std;

int main() {
    // personas
    vector<Persona> lista = {
        Persona("Ana", 20, 'F'),
        Persona("Luis", 22, 'M'),
        Persona("Maria", 19, 'F')
    };

    // gestorXML
    GestorXML gestor("personas.xml");

    // arch inicial
    gestor.escribir(lista);

    // leer
    vector<Persona> cargadas = gestor.leer();
    cout << "Archivo original:\n";
    for (const auto& p : cargadas) {
        p.mostrar();
    }

    // Modificar datos
    gestor.modificar(cargadas);

    // guardado
    gestor.escribir(cargadas);

    // leer modificado
    vector<Persona> modificadas = gestor.leer();
    cout << "\nArchivo modificado:\n";
    for (const auto& p : modificadas) {
        p.mostrar();
    }

    return 0;
}
