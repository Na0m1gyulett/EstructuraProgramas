#include <iostream>
#include "Lista.h"

int main() {

    Lista lista;
    int opcion, valor, pos;

    do {
        std::cout << "\n====== MENU LISTA ======\n";
        std::cout << "1. Insertar al inicio\n";
        std::cout << "2. Insertar al final\n";
        std::cout << "3. Insertar en posicion\n";
        std::cout << "4. Eliminar del inicio\n";
        std::cout << "5. Eliminar del final\n";
        std::cout << "6. Eliminar por valor\n";
        std::cout << "7. Buscar valor\n";
        std::cout << "8. Mostrar lista\n";
        std::cout << "9. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "  Valor: ";
                std::cin >> valor;
                lista.insertarInicio(valor);
                break;

            case 2:
                std::cout << "  Valor: ";
                std::cin >> valor;
                lista.insertarFinal(valor);
                break;

            case 3:
                std::cout << "  Valor: ";
                std::cin >> valor;
                std::cout << "  Posicion (1-" << lista.getTamano()+1 << "): ";
                std::cin >> pos;
                lista.insertarPos(valor, pos);
                break;

            case 4:
                lista.eliminarInicio();
                break;

            case 5:
                lista.eliminarFinal();
                break;

            case 6:
                std::cout << "  Valor a eliminar: ";
                std::cin >> valor;
                lista.eliminarValor(valor);
                break;

            case 7:
                std::cout << "  Valor a buscar: ";
                std::cin >> valor;
                if (lista.buscar(valor))
                    std::cout << "  [?] Valor " << valor << " encontrado\n";
                else
                    std::cout << "  [?] Valor " << valor << " no encontrado\n";
                break;

            case 8:
                std::cout << "  Lista (" << lista.getTamano()
                          << " elementos):\n";
                lista.mostrar();
                break;

            case 9:
                std::cout << "  Saliendo...\n";
                break;

            default:
                std::cout << "  [!] Opcion invalida\n";
        }

    } while (opcion != 9);

    return 0;
}