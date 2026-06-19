#ifndef CLASEXML_H
#define CLASEXML_H

#include <string>
#include <vector>
using namespace std;

// clase persona
class Persona {
private:
    string nombre;
    int edad;
    char genero;

public:
    Persona(string n = "", int e = 0, char g = 'U');
    string getNombre() const;
    int getEdad() const;
    char getGenero() const;
    void setNombre(string n);
    void setEdad(int e);
    void setGenero(char g);
    void mostrar() const;
};

//GestorXML
class GestorXML {
private:
    string nombreArchivo;

public:
    GestorXML(string archivo);
    void escribir(const vector<Persona>& personas);
    vector<Persona> leer();
    void modificar(vector<Persona>& personas);
};

#endif
