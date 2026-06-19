#include "claseTxt.h"
#include <iostream>
#include <fstream>
using namespace std;

// Perosna
Persona::Persona(string n, int e, char g) : nombre(n), edad(e), genero(g) {}

string Persona::getNombre() const { return nombre; }
int Persona::getEdad() const { return edad; }
char Persona::getGenero() const { return genero; }

void Persona::setNombre(string n) { nombre = n; }
void Persona::setEdad(int e) { edad = e; }
void Persona::setGenero(char g) { genero = g; }

void Persona::mostrar() const {
    cout << nombre << " - " << edad << " - " << genero << endl;
}

// gestortxt
GestorTXT::GestorTXT(string archivo) : nombreArchivo(archivo) {}

void GestorTXT::escribir(const vector<Persona>& personas) {
    ofstream archivo(nombreArchivo);
    for (const auto& p : personas) {
        archivo << p.getNombre() << " " << p.getEdad() << " " << p.getGenero() << "\n";
    }
    archivo.close();
}

vector<Persona> GestorTXT::leer() {
    vector<Persona> personas;
    ifstream archivo(nombreArchivo);

    string nombre;
    int edad;
    char genero;

    while (archivo >> nombre >> edad >> genero) {
        Persona p;
        p.setNombre(nombre);
        p.setEdad(edad);
        p.setGenero(genero);
        personas.push_back(p);
    }

    archivo.close();
    return personas;
}


void GestorTXT::modificar(vector<Persona>& personas) {
    // Agregar nueva persona
    personas.push_back(Persona("Carlos", 25, 'M'));

    // Modificar edad de la primera persona
    if (!personas.empty()) {
        int nuevaEdad = personas[0].getEdad() + 1;
        personas[0].setEdad(nuevaEdad);
    }

    // Eliminar la última persona si hay más de 3
    if (personas.size() > 3) {
        personas.pop_back();
    }
}
