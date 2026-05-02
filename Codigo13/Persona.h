#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string nombre;
    std::string apellidoPaterno;
    std::string apellidoMaterno;
    std::string genero;
    int edad;

public:
    void registrar();
    void mostrar() const;
};

#endif