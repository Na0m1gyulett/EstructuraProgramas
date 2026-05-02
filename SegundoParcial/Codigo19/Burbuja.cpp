#include "Burbuja.h"
#include <iostream>

//enteros
void Burbuja::ordenarIndicesInt(const std::vector<int>& arr,
                                 std::vector<int>& indices) {
    int n = arr.size();
    // Inicializar
    for (int i = 0; i < n; i++) indices[i] = i;

    // Burbuja indirecto
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[indices[j]] > arr[indices[j + 1]]) {
                int temp      = indices[j];
                indices[j]    = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}

void Burbuja::ordenarEnteros(const std::vector<int>& arr,
                              std::vector<int>& indices) {
    indices.resize(arr.size());
    ordenarIndicesInt(arr, indices);
}

//caracteres
void Burbuja::ordenarIndicesChar(const std::vector<char>& arr,
                                  std::vector<int>& indices) {
    int n = arr.size();
    for (int i = 0; i < n; i++) indices[i] = i;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[indices[j]] > arr[indices[j + 1]]) {
                int temp       = indices[j];
                indices[j]     = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}

void Burbuja::ordenarChars(const std::vector<char>& arr,
                            std::vector<int>& indices) {
    indices.resize(arr.size());
    ordenarIndicesChar(arr, indices);
}
//estudiantes

void Burbuja::ordenarIndicesEst(const std::vector<Estudiante>& arr,
                                 std::vector<int>& indices) {
    int n = arr.size();
    for (int i = 0; i < n; i++) indices[i] = i;

    // Ordenar por calificacion de menor a mayor
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[indices[j]].getCalificacion() >
                arr[indices[j + 1]].getCalificacion()) {
                int temp       = indices[j];
                indices[j]     = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}

void Burbuja::ordenarEstudiantes(const std::vector<Estudiante>& arr,
                                  std::vector<int>& indices) {
    indices.resize(arr.size());
    ordenarIndicesEst(arr, indices);
}

// mostrar

void Burbuja::mostrarEnteros(const std::vector<int>& arr,
                              const std::vector<int>& indices) const {
    for (int i : indices)
        std::cout << "  [" << i << "] -> " << arr[i] << "\n";
}

void Burbuja::mostrarChars(const std::vector<char>& arr,
                            const std::vector<int>& indices) const {
    for (int i : indices)
        std::cout << "  [" << i << "] -> " << arr[i] << "\n";
}

void Burbuja::mostrarEstudiantes(const std::vector<Estudiante>& arr,
                                  const std::vector<int>& indices) const {
    for (int i : indices) {
        std::cout << "  [" << i << "] -> ";
        arr[i].mostrar();
    }
}