 #include <iostream>
#include <vector>
#include "claseCsv.h"   // Incluimos la definición de clases
using namespace std;

int main() {
    // Crear lista inicial
    vector<Persona> lista = {
        Persona("Ana", 20, 'F'),
        Persona("Luis", 22, 'M'),
        Persona("Maria", 19, 'F')
    };

    // Crear gestor CSV
    GestorCSV gestor("personas.csv");

    // 1. Escribir archivo inicial
    gestor.escribir(lista);

    // 2. Leer archivo original
    vector<Persona> cargadas = gestor.leer();
    cout << "Archivo original:\n";
    for (const auto& p : cargadas) {
        p.mostrar();
    }

    // 3. Modificar datos
    gestor.modificar(cargadas);

    // 4. Guardar archivo modificado
    gestor.escribir(cargadas);

    // 5. Leer archivo modificado
    vector<Persona> modificadas = gestor.leer();
    cout << "\nArchivo modificado:\n";
    for (const auto& p : modificadas) {
        p.mostrar();
    }

    return 0;
}

