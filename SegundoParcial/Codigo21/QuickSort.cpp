#include "QuickSort.h"
#include <iostream>

// enteros

int QuickSort::particionInt(const std::vector<int>& arr,
                             std::vector<int>& indices, int izq, int der) {
    // Pivote es el ultimo indice
    int pivote = arr[indices[der]];
    int i = izq - 1;

    for (int j = izq; j < der; j++) {
        if (arr[indices[j]] <= pivote) {
            i++;
            int temp    = indices[i];
            indices[i]  = indices[j];
            indices[j]  = temp;
        }
    }
    //  pivote en su lugar
    int temp       = indices[i + 1];
    indices[i + 1] = indices[der];
    indices[der]   = temp;

    return i + 1;
}

void QuickSort::quickSortInt(const std::vector<int>& arr,
                              std::vector<int>& indices, int izq, int der) {
    if (izq >= der) return;  

    int pivot = particionInt(arr, indices, izq, der);
    quickSortInt(arr, indices, izq, pivot - 1);   
    quickSortInt(arr, indices, pivot + 1, der);   
}

void QuickSort::ordenarEnteros(const std::vector<int>& arr,
                                std::vector<int>& indices) {
    indices.resize(arr.size());
    for (int i = 0; i < (int)arr.size(); i++) indices[i] = i;
    quickSortInt(arr, indices, 0, arr.size() - 1);
}

// caracteres

int QuickSort::particionChar(const std::vector<char>& arr,
                              std::vector<int>& indices, int izq, int der) {
    char pivote = arr[indices[der]];
    int i = izq - 1;

    for (int j = izq; j < der; j++) {
        if (arr[indices[j]] <= pivote) {
            i++;
            int temp   = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }
    int temp       = indices[i + 1];
    indices[i + 1] = indices[der];
    indices[der]   = temp;

    return i + 1;
}

void QuickSort::quickSortChar(const std::vector<char>& arr,
                               std::vector<int>& indices, int izq, int der) {
    if (izq >= der) return;

    int pivot = particionChar(arr, indices, izq, der);
    quickSortChar(arr, indices, izq, pivot - 1);
    quickSortChar(arr, indices, pivot + 1, der);
}

void QuickSort::ordenarChars(const std::vector<char>& arr,
                              std::vector<int>& indices) {
    indices.resize(arr.size());
    for (int i = 0; i < (int)arr.size(); i++) indices[i] = i;
    quickSortChar(arr, indices, 0, arr.size() - 1);
}

// estudiantes

int QuickSort::particionEst(const std::vector<Estudiante>& arr,
                             std::vector<int>& indices, int izq, int der) {
    float pivote = arr[indices[der]].getCalificacion();
    int i = izq - 1;

    for (int j = izq; j < der; j++) {
        if (arr[indices[j]].getCalificacion() <= pivote) {
            i++;
            int temp   = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }
    int temp       = indices[i + 1];
    indices[i + 1] = indices[der];
    indices[der]   = temp;

    return i + 1;
}

void QuickSort::quickSortEst(const std::vector<Estudiante>& arr,
                              std::vector<int>& indices, int izq, int der) {
    if (izq >= der) return;

    int pivot = particionEst(arr, indices, izq, der);
    quickSortEst(arr, indices, izq, pivot - 1);
    quickSortEst(arr, indices, pivot + 1, der);
}

void QuickSort::ordenarEstudiantes(const std::vector<Estudiante>& arr,
                                    std::vector<int>& indices) {
    indices.resize(arr.size());
    for (int i = 0; i < (int)arr.size(); i++) indices[i] = i;
    quickSortEst(arr, indices, 0, arr.size() - 1);
}

// mostrar

void QuickSort::mostrarEnteros(const std::vector<int>& arr,
                                const std::vector<int>& indices) const {
    for (int i : indices)
        std::cout << "  [" << i << "] -> " << arr[i] << "\n";
}

void QuickSort::mostrarChars(const std::vector<char>& arr,
                              const std::vector<int>& indices) const {
    for (int i : indices)
        std::cout << "  [" << i << "] -> " << arr[i] << "\n";
}

void QuickSort::mostrarEstudiantes(const std::vector<Estudiante>& arr,
                                    const std::vector<int>& indices) const {
    for (int i : indices) {
        std::cout << "  [" << i << "] -> ";
        arr[i].mostrar();
    }
}