#ifndef AUTO_H
#define AUTO_H

#include <string>

class Auto {
private:
    int anio;
    int precio;

public:
    void registrar();
    void mostrar() const;
};

#endif