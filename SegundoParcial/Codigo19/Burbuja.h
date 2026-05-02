#ifndef BURBUJA_H
#define BURBUJA_H

#include "Estudiante.h"
#include <vector>

class Burbuja {
private:
    // ordenamiento
    void ordenarIndicesInt(const std::vector<int>& arr,
                           std::vector<int>& indices);

    void ordenarIndicesChar(const std::vector<char>& arr,
                            std::vector<int>& indices);

    void ordenarIndicesEst(const std::vector<Estudiante>& arr,
                           std::vector<int>& indices);

public:
    void ordenarEnteros(const std::vector<int>& arr,
                        std::vector<int>& indices);

    void ordenarChars(const std::vector<char>& arr,
                      std::vector<int>& indices);

    void ordenarEstudiantes(const std::vector<Estudiante>& arr,
                            std::vector<int>& indices);

    void mostrarEnteros(const std::vector<int>& arr,
                        const std::vector<int>& indices) const;

    void mostrarChars(const std::vector<char>& arr,
                      const std::vector<int>& indices) const;

    void mostrarEstudiantes(const std::vector<Estudiante>& arr,
                            const std::vector<int>& indices) const;
};

#endif