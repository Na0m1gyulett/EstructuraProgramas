#include "Pila.h"
#include <iostream>

Pila::Pila() : tope(nullptr), cantidad(0) {}


Pila::~Pila() {
    while (!estaVacia()) {
        pop();
    }
    std::cout << "  [*] Memoria liberada\n";
}

bool Pila::estaVacia() const {
    return tope == nullptr;
}

// Push 
void Pila::push(int valor) {
    Nodo* nuevo    = new Nodo(valor);  
    nuevo->setSiguiente(tope);         
    tope           = nuevo;            
    cantidad++;
    std::cout << "  [+] Push: " << valor << "\n";
}

// Pop
void Pila::pop() {
    if (estaVacia()) {
        std::cout << "  [!] Pila vacia, no se puede hacer pop\n";
        return;
    }
    Nodo* temp = tope;                 
    std::cout << "  [-] Pop: " << temp->getDato() << "\n";
    tope       = tope->getSiguiente(); 
    delete temp;                       
    cantidad--;
}

int Pila::verTope() const {
    if (estaVacia()) {
        std::cout << "  [!] Pila vacia\n";
        return -1;
    }
    return tope->getDato();
}


void Pila::mostrar() const {
    if (estaVacia()) {
        std::cout << "  [!] Pila vacia\n";
        return;
    }
    Nodo* actual = tope;
    std::cout << "  Tope -> ";
    while (actual != nullptr) {
        std::cout << actual->getDato();
        if (actual->getSiguiente() != nullptr)
            std::cout << " | ";
        actual = actual->getSiguiente();
    }
    std::cout << " <- Fondo\n";
}

int Pila::getTamano() const {
    return cantidad;
}