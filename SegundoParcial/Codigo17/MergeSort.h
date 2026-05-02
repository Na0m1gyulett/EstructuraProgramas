#ifndef MERGESORT_H
#define MERGESORT_H

#include "Estudiante.h"
#include <vector>

class MergeSort {
private:
	void mergeInt(std::vector<int> & arr, int izq, int mid, int der);
	void mergeSortInt(std::vector<int>& arr, int izq, int der);
	
	void mergeChar(std::vector<char>& arr, int izq, int mid, int der);
	void mergeSortChar(std::vector<char>& arr, int izq, int der);
	
	void mergeEst(std::vector<Estudiante>&arr, int izq, int mid, int der);
	void mergeSortEst(std::vector<Estudiante>& arr, int izq, int der);
	
public:
	void ordenarEnteros(std::vector<int>& arr);
	void ordenarChars(std::vector<char>& arr);
    void ordenarEstudiantes(std::vector<Estudiante>& arr);

    void mostrarEnteros(const std::vector<int>& arr) const;
    void mostrarChars(const std::vector<char>& arr) const;
    void mostrarEstudiantes(const std::vector<Estudiante>& arr) const;
};

#endif