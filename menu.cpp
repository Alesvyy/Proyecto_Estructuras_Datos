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
                agregarProducto();
            break;
            case 2:
                verProductos();
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
        std::cout << "4. Eliminar turno especifico\n";  // Nueva opción
        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el numero del turno: ";
                std::cin >> turno;
                cola.insertarElem(turno);
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
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void Menu::agregarProducto() {
    std::string nombre;
    double precio;
    std::string descripcion;

    std::cout << "Ingrese el nombre del producto: ";
    std::cin >> nombre;

    std::cout << "Ingrese el precio del producto: ";
    std::cin >> precio;

    std::cout << "Ingrese la descripcion del producto: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);

    Producto nuevoProducto(nombre, precio, descripcion);
    productos.push_back(nuevoProducto);

    std::cout << "Producto agregado: " << nombre << "\n";
}

void Menu::verProductos() {
    if (productos.empty()) {
        std::cout << "No hay productos disponibles.\n";
        return;
    }

    std::cout << "Lista de Productos:\n";
    for (const auto& producto : productos) {
        std::cout << "Nombre: " << producto.getNombre()
                  << ", Precio: " << producto.getPrecio()
                  << ", Descripcion: " << producto.getDescripcion() << "\n";
    }
}
