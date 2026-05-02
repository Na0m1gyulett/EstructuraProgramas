#include "MiCola.h"
#include <iostream>

MiCola::MiCola() {}  

bool MiCola::estaVacia() const {
    return cola.empty();
}

// encolar 
void MiCola::encolar(int valor) {
    cola.push(valor);
    std::cout << "  [+] Encolado: " << valor << "\n";
}

// desencolar
void MiCola::desencolar() {
    if (estaVacia()) {
        std::cout << "  [!] Cola vacia, no se puede desencolar\n";
        return;
    }
    std::cout << "  [-] Desencolado: " << cola.front() << "\n";
    cola.pop();
}

// ver el primer elemento sin eliminarlo
int MiCola::verFrente() const {
    if (estaVacia()) {
        std::cout << "  [!] Cola vacia\n";
        return -1;
    }
    return cola.front();
}

// ver el ultimo elemento sin eliminarlo
int MiCola::verFinal() const {
    if (estaVacia()) {
        std::cout << "  [!] Cola vacia\n";
        return -1;
    }
    return cola.back();
}

// mostrar todos los elementos
void MiCola::mostrar() const {
    if (estaVacia()) {
        std::cout << "  [!] Cola vacia\n";
        return;
    }
    std::queue<int> temp = cola;  
    std::cout << "  Frente -> ";
    while (!temp.empty()) {
        std::cout << temp.front();
        temp.pop();
        if (!temp.empty()) std::cout << " | ";
    }
    std::cout << " <- Final\n";
}

int MiCola::getTamano() const {
    return cola.size();
}