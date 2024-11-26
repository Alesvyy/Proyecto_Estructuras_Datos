#include "menu.h"
#include <iostream>
#include <vector>
#include <limits>

Menu::Menu() {}

void Menu::mostrarMenu() {
    int opcion;

    do {
        std::cout << "\n";
        std::cout << "1. Agregar Producto\n";
        std::cout << "2. Ver Productos\n";
        std::cout << "3. Modificar Producto\n";
        std::cout << "4. Eliminar Producto\n";
        std::cout << "5. Agregar Categoria\n";
        std::cout << "6. Ver Categorias\n";
        std::cout << "7. Modificar Categoria\n";
        std::cout << "8. Eliminar Categoria\n";

        std::cout << "0. Salir\n";
        std::cout << "\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, intentelo mas tarde.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                agregarProducto();
            break;
            case 2:
                verProductos();
            break;
            case 3:
                modificarProducto();
            break;
            case 4:
                eliminarProducto();
            break;
            case 5:
                agregarCategoria();
            break;
            case 6:
                verCategoria();
            break;
            case 7:
                modificarCategoria();
            break;
            case 8:
                eliminarCategoria();
            break;
            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}



void Menu::agregarProducto() {
    std::string nombre, descripcion;
    double precio;

    std::cout << "Ingrese el nombre del producto: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la descripcion del producto: ";
    std::getline(std::cin, descripcion);

    std::cout << "Ingrese el precio del producto: ";
    std::cin >> precio;

    Producto* nuevoProducto = new Producto(nombre, descripcion, precio);
    listaProductos.agregarProducto(nuevoProducto); // Asegúrate de que listaProductos está inicializado

    std::cout << "\nProducto agregado exitosamente:\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Descripcion: " << descripcion << "\n";
    std::cout << "Precio: " << precio << " Colones\n";
}

void Menu::verProductos() {
    listaProductos.display();
}
void Menu::agregarCategoria() {
    std::string nombre;
    std::string descripcion;

    std::cout << "Ingrese el nombre de la categoria: ";
    std::cin >> nombre;

    std::cout << "Ingrese la descripcion de la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, descripcion);

    Categoria* categoria = new Categoria(nombre, descripcion);
    listaCategorias.agregarCategoria(categoria);

}

void Menu::eliminarCategoria() {
    string nombre;

    cout << "Ingrese el nombre de la categoria a eliminar: ";
    cin >> nombre;

    listaCategorias.eliminarCategoria(nombre);
}

void Menu::verCategoria() {
    listaCategorias.display();
}

void Menu::eliminarProducto() {
    string nombre;

    cout << "Ingrese el nombre del Producto a eliminar: ";
    cin >> nombre;

    listaProductos.eliminarProducto(nombre);
}


void Menu::modificarCategoria() {
    std::string nombre,nuevoNombre;

    std::cout << "Ingrese el nombre de la categoria a modificar: ";
    std::cin >> nombre;

    std::cout << "Ingrese el nuevo nombre de la categoria: ";
    std::cin >> nuevoNombre;

    listaCategorias.modificarCategoria(nombre,nuevoNombre);

}

void Menu::modificarProducto() {
    std::string nombreActual, nuevoNombre;
    double nuevoPrecio;

    std::cout << "Ingrese el nombre del producto a modificar: ";
    std::cin >> nombreActual;

    std::cout << "Ingrese el nuevo nombre del producto: ";
    std::cin >> nuevoNombre;

    while (true) {
        std::cout << "Ingrese el nuevo precio del producto: ";
        std::cin >> nuevoPrecio;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido para el precio.\n";
        } else {
            break;
        }
    }

    listaProductos.modificarProducto(nombreActual, nuevoNombre, nuevoPrecio);
}