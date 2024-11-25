#include "menu.h"
#include <iostream>

Menu::Menu() {}

void Menu::mostrarMenu() {
    int opcion;

    do {
        std::cout << "\n";
        std::cout << "1. Agregar Producto\n";
        std::cout << "2. Ver Productos\n";
        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                // agregarProducto();
            break;
            case 2:
                // verProductos();
            break;
            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void Menu::mostrarMenuColas() {
    int opcion;
    string atendido;
    std::string turno;

    do {
        std::cout << "\n";
        std::cout << "1. Insertar Turno\n";
        std::cout << "2. Atender Clientes\n";
        std::cout << "3. Mostrar ultimo turno ingresado\n";
        std::cout << "4. Eliminar turno especifico\n";
        std::cout << "5. Verificar cola\n";
        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion:";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cola.insertarElem();
                    break;
            case 2:
                cola.atenderCliente(atendido);
                    break;
            case 3:
                std::cout << "Ultimo turno ingresado: " << cola.ultimoElem() << "\n";
                break;
            case 4:
                std::cout << "Ingrese el numero del turno a eliminar: ";
                std::cin >> turno;
                int posicion;
                posicion = cola.buscarTurno(turno);
                if (posicion != -1) {
                    cola.eliminarElem(posicion);
                    std::cout << "Turno " << turno << " eliminado.\n";
                } else {
                    std::cout << "Turno no encontrado.\n";
                }
                break;
            case 5:
                if(cola.esVaciaCola()) {
                    cout <<"La cola esta vacia";
                }else {
                    cola.listarCola();
                }
                break;

            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}