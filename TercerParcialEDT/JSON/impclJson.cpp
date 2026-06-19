#include "claseJson.h"
#include <iostream>
#include <fstream>
#include "json.hpp"   // Librería nlohmann/json
using json = nlohmann::json;
using namespace std;

// persona
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

// GestorJSON
GestorJSON::GestorJSON(string archivo) : nombreArchivo(archivo) {}

void GestorJSON::escribir(const vector<Persona>& personas) {
    json j;
    j["personas"] = json::array();

    for (const auto& p : personas) {
        j["personas"].push_back({
            {"nombre", p.getNombre()},
            {"edad", p.getEdad()},
            {"genero", string(1, p.getGenero())}
        });
    }

    ofstream archivo(nombreArchivo);
    archivo << j.dump(4);
    archivo.close();
}

vector<Persona> GestorJSON::leer() {
    vector<Persona> personas;
    ifstream archivo(nombreArchivo);
    json j;
    archivo >> j;
    archivo.close();

    for (const auto& item : j["personas"]) {
        string nombre = item["nombre"];
        int edad = item["edad"];
        char genero = item["genero"].get<string>()[0];
        personas.push_back(Persona(nombre, edad, genero));
    }

    return personas;
}

void GestorJSON::modificar(vector<Persona>& personas) {
    // nueva PERSONA
    personas.push_back(Persona("Carlos", 25, 'M'));

    // modificación
    if (!personas.empty()) {
        int nuevaEdad = personas[0].getEdad() + 1;
        personas[0].setEdad(nuevaEdad);
    }

//eliminar mas de 3
    if (personas.size() > 3) {
        personas.pop_back();
    }
}
