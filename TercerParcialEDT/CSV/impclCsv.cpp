#include "claseCsv.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// -------------------- Implementación Persona --------------------
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

// -------------------- Implementación GestorCSV --------------------
GestorCSV::GestorCSV(string archivo) : nombreArchivo(archivo) {}

void GestorCSV::escribir(const vector<Persona>& personas) {
    ofstream archivo(nombreArchivo);
    archivo << "nombre,edad,genero\n";
    for (const auto& p : personas) {
        archivo << p.getNombre() << "," << p.getEdad() << "," << p.getGenero() << "\n";
    }
    archivo.close();
}

vector<Persona> GestorCSV::leer() {
    vector<Persona> personas;
    ifstream archivo(nombreArchivo);
    string linea;
    getline(archivo, linea); // saltar encabezado

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, edadStr, generoStr;
        getline(ss, nombre, ',');
        getline(ss, edadStr, ',');
        getline(ss, generoStr, ',');

        Persona p(nombre, stoi(edadStr), generoStr[0]);
        personas.push_back(p);
    }
    archivo.close();
    return personas;
}

void GestorCSV::modificar(vector<Persona>& personas) {
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