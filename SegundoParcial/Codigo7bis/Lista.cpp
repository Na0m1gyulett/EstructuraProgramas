#include "Lista.h"
#include <iostream>

// Constructor
Lista::Lista() : cabeza(nullptr), cola(nullptr), cantidad(0) {}

// Destructor — libera toda la memoria
Lista::~Lista() {
    while (!estaVacia()) {
        eliminarInicio();
    }
    std::cout << "  [*] Memoria liberada\n";
}

bool Lista::estaVacia() const {
    return cabeza == nullptr;
}

// insertar

void Lista::insertarInicio(int valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->setSiguiente(cabeza);  
    cabeza = nuevo;               
    if (cola == nullptr)          
        cola = nuevo;
    cantidad++;
    std::cout << "  [+] Insertado al inicio: " << valor << "\n";
}

void Lista::insertarFinal(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (estaVacia()) {
        cabeza = nuevo;
        cola   = nuevo;
    } else {
        cola->setSiguiente(nuevo);  
        cola = nuevo;               
    }
    cantidad++;
    std::cout << "  [+] Insertado al final: " << valor << "\n";
}

void Lista::insertarPos(int valor, int pos) {
    if (pos <= 1) {
        insertarInicio(valor);
        return;
    }
    if (pos >= cantidad + 1) {
        insertarFinal(valor);
        return;
    }
    Nodo* nuevo  = new Nodo(valor);
    Nodo* actual = cabeza;
    for (int i = 1; i < pos - 1; i++)
        actual = actual->getSiguiente();  
    nuevo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo);
    cantidad++;
    std::cout << "  [+] Insertado en posicion " << pos
              << ": " << valor << "\n";
}



void Lista::eliminarInicio() {
    if (estaVacia()) {
        std::cout << "  [!] Lista vacia\n";
        return;
    }
    Nodo* temp = cabeza;
    std::cout << "  [-] Eliminado del inicio: " << temp->getDato() << "\n";
    cabeza = cabeza->getSiguiente();
    if (cabeza == nullptr) cola = nullptr;  
    delete temp;
    cantidad--;
}

void Lista::eliminarFinal() {
    if (estaVacia()) {
        std::cout << "  [!] Lista vacia\n";
        return;
    }
    if (cabeza == cola) {  
        std::cout << "  [-] Eliminado del final: " << cabeza->getDato() << "\n";
        delete cabeza;
        cabeza = nullptr;
        cola   = nullptr;
        cantidad--;
        return;
    }
    
    Nodo* actual = cabeza;
    while (actual->getSiguiente() != cola)
        actual = actual->getSiguiente();
    std::cout << "  [-] Eliminado del final: " << cola->getDato() << "\n";
    delete cola;
    cola = actual;
    cola->setSiguiente(nullptr);
    cantidad--;
}

void Lista::eliminarValor(int valor) {
    if (estaVacia()) {
        std::cout << "  [!] Lista vacia\n";
        return;
    }
    
    if (cabeza->getDato() == valor) {
        eliminarInicio();
        return;
    }
    Nodo* actual = cabeza;
    while (actual->getSiguiente() != nullptr &&
           actual->getSiguiente()->getDato() != valor) {
        actual = actual->getSiguiente();
    }
    if (actual->getSiguiente() == nullptr) {
        std::cout << "  [!] Valor " << valor << " no encontrado\n";
        return;
    }
    Nodo* temp = actual->getSiguiente();
    actual->setSiguiente(temp->getSiguiente());
    if (temp == cola) cola = actual; 
    std::cout << "  [-] Eliminado valor: " << valor << "\n";
    delete temp;
    cantidad--;
}

// buscar y mostrar

bool Lista::buscar(int valor) const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getDato() == valor) return true;
        actual = actual->getSiguiente();
    }
    return false;
}

void Lista::mostrar() const {
    if (estaVacia()) {
        std::cout << "  [!] Lista vacia\n";
        return;
    }
    Nodo* actual = cabeza;
    std::cout << "  Cabeza -> ";
    while (actual != nullptr) {
        std::cout << actual->getDato();
        if (actual->getSiguiente() != nullptr)
            std::cout << " -> ";
        actual = actual->getSiguiente();
    }
    std::cout << " -> nullptr\n";
}

int Lista::getTamano() const {
    return cantidad;
}