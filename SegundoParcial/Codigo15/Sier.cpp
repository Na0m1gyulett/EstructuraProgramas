#include "Sier.h"
#include <iostream>
#include <cmath>

Sier::Sier(int nivel) : nivel(nivel) {
    tamano = pow(2, nivel);
    inicializarLienzo();
}

void Sier::inicializarLienzo() {
    int filas    = tamano;
    int columnas = tamano * 2;
    lienzo.assign(filas, std::string(columnas, ' '));
}

void Sier::dibujarTriangulo(int fila, int columna, int tam) {
    if (tam == 1) {
        if (fila < (int)lienzo.size() && columna * 2 < (int)lienzo[fila].size()) {
            lienzo[fila][columna * 2] = '*';
        }
        return;
    }

    int mitad = tam / 2;

    dibujarTriangulo(fila,         columna,         mitad);
    dibujarTriangulo(fila + mitad, columna,         mitad);
    dibujarTriangulo(fila + mitad, columna + mitad, mitad);
}

void Sier::generar() {
    inicializarLienzo();
    dibujarTriangulo(0, 0, tamano);
}

void Sier::mostrar() const {
    std::cout << "\n=== Triangulo Sierpinski (Nivel " << nivel << ") ===\n\n";
    for (const std::string& fila : lienzo) {
        std::cout << fila << "\n";
    }
}

int Sier::getNivel()  const { return nivel;  }
int Sier::getTamano() const { return tamano; }