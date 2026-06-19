#ifndef CLASECSV_H
#define CLASECSV_H

#include <string>
#include <vector>
using namespace std;

// Clase Persona
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

// Clase GestorCSV
class GestorCSV {
private:
    string nombreArchivo;

public:
    GestorCSV(string archivo);
    void escribir(const vector<Persona>& personas);
    vector<Persona> leer();
    void modificar(vector<Persona>& personas);
};

#endif
