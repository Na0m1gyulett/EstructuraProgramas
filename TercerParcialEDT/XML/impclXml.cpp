#include "claseXml.h"
#include <iostream>
#include "tinyxml2.h"   // Librería externa para XML
using namespace tinyxml2;
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

// -------------------- Implementación GestorXML --------------------
GestorXML::GestorXML(string archivo) : nombreArchivo(archivo) {}

void GestorXML::escribir(const vector<Persona>& personas) {
    XMLDocument doc;
    XMLElement* root = doc.NewElement("personas");
    doc.InsertFirstChild(root);

    for (const auto& p : personas) {
        XMLElement* persona = doc.NewElement("persona");

        XMLElement* nombre = doc.NewElement("nombre");
        nombre->SetText(p.getNombre().c_str());
        persona->InsertEndChild(nombre);

        XMLElement* edad = doc.NewElement("edad");
        edad->SetText(p.getEdad());
        persona->InsertEndChild(edad);

        XMLElement* genero = doc.NewElement("genero");
        string g(1, p.getGenero());
        genero->SetText(g.c_str());
        persona->InsertEndChild(genero);

        root->InsertEndChild(persona);
    }

    doc.SaveFile(nombreArchivo.c_str());
}

vector<Persona> GestorXML::leer() {
    vector<Persona> personas;
    XMLDocument doc;
    doc.LoadFile(nombreArchivo.c_str());

    XMLElement* root = doc.FirstChildElement("personas");
    for (XMLElement* persona = root->FirstChildElement("persona"); persona != nullptr; persona = persona->NextSiblingElement("persona")) {
        string nombre = persona->FirstChildElement("nombre")->GetText();
        int edad = stoi(persona->FirstChildElement("edad")->GetText());
        char genero = persona->FirstChildElement("genero")->GetText()[0];

        personas.push_back(Persona(nombre, edad, genero));
    }

    return personas;
}

void GestorXML::modificar(vector<Persona>& personas) {
    // nueva persona
    personas.push_back(Persona("Carlos", 25, 'M'));

    // Modificar edad
    if (!personas.empty()) {
        int nuevaEdad = personas[0].getEdad() + 1;
        personas[0].setEdad(nuevaEdad);
    }

    // eliminar mas de 3
    if (personas.size() > 3) {
        personas.pop_back();
    }
}
