#include <iostream>
#include <vector>
#include "Persona.h"
#include "Auto.h"

int main() {
    int numPersonas, numAutos;

    // ── Personas ──────────────────────────────────
    std::cout << "¿Cuántas personas deseas registrar? ";
    std::cin >> numPersonas;
    std::vector<Persona> personas(numPersonas);

    for (int i = 0; i < numPersonas; i++) {
        std::cout << "\nPersona " << i + 1 << ":\n";
        personas[i].registrar();
    }

    // ✅ Punteros declarados después de llenar el vector
    std::vector<Persona>* pLista   = &personas;       // puntero al vector
    Persona*              pPrimera = &personas[0];    // puntero al primer elemento
    Persona*              pUltima  = &personas[numPersonas - 1]; // puntero al ultimo

    // ── Autos ─────────────────────────────────────
    std::cout << "\n¿Cuántos autos deseas registrar? ";
    std::cin >> numAutos;
    std::vector<Auto> autos(numAutos);

    for (int i = 0; i < numAutos; i++) {
        std::cout << "\nAuto " << i + 1 << ":\n";
        autos[i].registrar();
    }

    // ── Lista de Personas via puntero ─────────────
    std::cout << "\n--- Lista de Personas ---\n";
    for (int i = 0; i < (int)pLista->size(); i++) {
        pLista->at(i).mostrar();    // acceso indirecto via pLista
    }

    // ── Primera y ultima persona via puntero ──────
    std::cout << "\n--- Primera Persona ---\n";
    pPrimera->mostrar();            // acceso indirecto via pPrimera

    std::cout << "\n--- Ultima Persona ---\n";
    pUltima->mostrar();             // acceso indirecto via pUltima

    // ── Lista de Autos (sin puntero) ──────────────
    std::cout << "\n--- Lista de Autos ---\n";
    for (const auto& a : autos) {
        a.mostrar();
    }

    return 0;
}