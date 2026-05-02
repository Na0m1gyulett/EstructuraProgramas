#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Estudiante.h"
#include <vector>

class QuickSort {
private:
    // enteros
    int particionInt(const std::vector<int>& arr,
                     std::vector<int>& indices, int izq, int der);
    void quickSortInt(const std::vector<int>& arr,
                      std::vector<int>& indices, int izq, int der);

    // caracteres
    int particionChar(const std::vector<char>& arr,
                      std::vector<int>& indices, int izq, int der);
    void quickSortChar(const std::vector<char>& arr,
                       std::vector<int>& indices, int izq, int der);

    //  estudiantes
    int particionEst(const std::vector<Estudiante>& arr,
                     std::vector<int>& indices, int izq, int der);
    void quickSortEst(const std::vector<Estudiante>& arr,
                      std::vector<int>& indices, int izq, int der);

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