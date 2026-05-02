#include "MergeSort.h"
#include <iostream>

// --- ENTEROS ------------------------------------------------

void MergeSort::mergeInt(std::vector<int>& arr, int izq, int mid, int der) {
    std::vector<int> izqArr(arr.begin() + izq, arr.begin() + mid + 1);
    std::vector<int> derArr(arr.begin() + mid + 1, arr.begin() + der + 1);

    int i = 0, j = 0, k = izq;
    while (i < (int)izqArr.size() && j < (int)derArr.size()) {
        if (izqArr[i] <= derArr[j])
            arr[k++] = izqArr[i++];
        else
            arr[k++] = derArr[j++];
    }
    while (i < (int)izqArr.size()) arr[k++] = izqArr[i++];
    while (j < (int)derArr.size()) arr[k++] = derArr[j++];
}

void MergeSort::mergeSortInt(std::vector<int>& arr, int izq, int der) {
    if (izq >= der) return;                      // caso base
    int mid = (izq + der) / 2;
    mergeSortInt(arr, izq, mid);                 // mitad izquierda
    mergeSortInt(arr, mid + 1, der);             // mitad derecha
    mergeInt(arr, izq, mid, der);                // combinar
}

void MergeSort::ordenarEnteros(std::vector<int>& arr) {
    mergeSortInt(arr, 0, arr.size() - 1);
}

//caracteres
void MergeSort::mergeChar(std::vector<char>& arr, int izq, int mid, int der) {
    std::vector<char> izqArr(arr.begin() + izq, arr.begin() + mid + 1);
    std::vector<char> derArr(arr.begin() + mid + 1, arr.begin() + der + 1);

    int i = 0, j = 0, k = izq;
    while (i < (int)izqArr.size() && j < (int)derArr.size()) {
        if (izqArr[i] <= derArr[j])
            arr[k++] = izqArr[i++];
        else
            arr[k++] = derArr[j++];
    }
    while (i < (int)izqArr.size()) arr[k++] = izqArr[i++];
    while (j < (int)derArr.size()) arr[k++] = derArr[j++];
}

void MergeSort::mergeSortChar(std::vector<char>& arr, int izq, int der) {
    if (izq >= der) return;
    int mid = (izq + der) / 2;
    mergeSortChar(arr, izq, mid);
    mergeSortChar(arr, mid + 1, der);
    mergeChar(arr, izq, mid, der);
}

void MergeSort::ordenarChars(std::vector<char>& arr) {
    mergeSortChar(arr, 0, arr.size() - 1);
}

// estudiantes

void MergeSort::mergeEst(std::vector<Estudiante>& arr, int izq, int mid, int der) {
    std::vector<Estudiante> izqArr(arr.begin() + izq, arr.begin() + mid + 1);
    std::vector<Estudiante> derArr(arr.begin() + mid + 1, arr.begin() + der + 1);

    int i = 0, j = 0, k = izq;
    while (i < (int)izqArr.size() && j < (int)derArr.size()) {
        // Ordenar por calificacion de menor a mayor
        if (izqArr[i].getCalificacion() <= derArr[j].getCalificacion())
            arr[k++] = izqArr[i++];
        else
            arr[k++] = derArr[j++];
    }
    while (i < (int)izqArr.size()) arr[k++] = izqArr[i++];
    while (j < (int)derArr.size()) arr[k++] = derArr[j++];
}

void MergeSort::mergeSortEst(std::vector<Estudiante>& arr, int izq, int der) {
    if (izq >= der) return;
    int mid = (izq + der) / 2;
    mergeSortEst(arr, izq, mid);
    mergeSortEst(arr, mid + 1, der);
    mergeEst(arr, izq, mid, der);
}

void MergeSort::ordenarEstudiantes(std::vector<Estudiante>& arr) {
    mergeSortEst(arr, 0, arr.size() - 1);
}

// --- MOSTRAR ------------------------------------------------

void MergeSort::mostrarEnteros(const std::vector<int>& arr) const {
    for (int x : arr) std::cout << "  " << x << "\n";
}

void MergeSort::mostrarChars(const std::vector<char>& arr) const {
    for (char c : arr) std::cout << "  " << c << "\n";
}

void MergeSort::mostrarEstudiantes(const std::vector<Estudiante>& arr) const {
    for (const Estudiante& e : arr) e.mostrar();
}