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
    if (listaCategorias.getHead() == nullptr) {
        std::cout << "No hay categorias disponibles. Agregue una categoria primero.\n";
        return;
    }

    std::cout << "Seleccione una categoria para agregar el producto:\n";
    listaCategorias.display();

    int numeroCategoria;
    std::cout << "Ingrese el numero de la categoria: ";
    while (true) {
        std::cin >> numeroCategoria;

        if (std::cin.fail() || numeroCategoria < 1 || numeroCategoria > listaCategorias.contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias.contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaSeleccionada = listaCategorias.obtenerNodoPorNumero(numeroCategoria);
    if (!categoriaSeleccionada) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    std::string nombre, descripcion;
    double precio;

    std::cin.ignore();
    std::cout << "Ingrese el nombre del producto: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la descripcion del producto: ";
    std::getline(std::cin, descripcion);

    std::cout << "Ingrese el precio del producto: ";
    while (true) {
        std::cin >> precio;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido para el precio.\n";
        } else {
            break;
        }
    }

    Producto* nuevoProducto = new Producto(nombre, descripcion, precio);
    categoriaSeleccionada->getCategoria()->getListaProductos()->agregarProducto(nuevoProducto);

    std::cout << "\nProducto agregado exitosamente a la categoria \""
              << categoriaSeleccionada->getCategoria()->getNombre() << "\":\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Descripcion: " << descripcion << "\n";
    std::cout << "Precio: " << precio << " Colones\n";
}


void Menu::verProductos() {
    if (listaCategorias.getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    NodoCategoria* tempCategoria = listaCategorias.getHead();
    int contadorCategoria = 1;

    while (tempCategoria != nullptr) {
        std::cout << "\nCategoria " << contadorCategoria << ": " << tempCategoria->getCategoria()->getNombre() << "\n";
        tempCategoria->getCategoria()->getListaProductos()->display();
        tempCategoria = tempCategoria->getSiguiente();
        contadorCategoria++;
    }
}


void Menu::modificarProducto() {
    if (listaCategorias.getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    // Selección de categoría
    std::cout << "Seleccione una categoria para modificar productos:\n";
    listaCategorias.display();

    int numeroCategoria;
    std::cout << "Ingrese el numero de la categoria: ";
    while (true) {
        std::cin >> numeroCategoria;

        if (std::cin.fail() || numeroCategoria < 1 || numeroCategoria > listaCategorias.contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias.contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaSeleccionada = listaCategorias.obtenerNodoPorNumero(numeroCategoria);
    if (!categoriaSeleccionada) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    // Mostrar productos de la categoría seleccionada
    std::cout << "Productos en la categoria \"" << categoriaSeleccionada->getCategoria()->getNombre() << "\":\n";
    categoriaSeleccionada->getCategoria()->getListaProductos()->display();

    // Selección de producto
    std::string nombreActual;
    std::cout << "Ingrese el nombre del producto que desea modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreActual);

    // Nuevos datos
    std::string nuevoNombre, nuevaDescripcion;
    double nuevoPrecio;

    std::cout << "Ingrese el nuevo nombre del producto: ";
    std::getline(std::cin, nuevoNombre);

    std::cout << "Ingrese el nuevo precio del producto: ";
    while (true) {
        std::cin >> nuevoPrecio;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido para el precio.\n";
        } else {
            break;
        }
    }

    std::cin.ignore(); // Limpiar el buffer para la descripción
    std::cout << "Ingrese la nueva descripcion del producto: ";
    std::getline(std::cin, nuevaDescripcion);

    // Modificar producto
    categoriaSeleccionada->getCategoria()->getListaProductos()->modificarProducto(nombreActual, nuevoNombre, nuevoPrecio, nuevaDescripcion);


    std::cout << "Producto modificado exitosamente.\n";
}



void Menu::eliminarProducto() {
    if (listaCategorias.getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    // Selección de categoría
    std::cout << "Seleccione una categoria para eliminar productos:\n";
    listaCategorias.display();

    int numeroCategoria;
    std::cout << "Ingrese el numero de la categoria: ";
    while (true) {
        std::cin >> numeroCategoria;

        if (std::cin.fail() || numeroCategoria < 1 || numeroCategoria > listaCategorias.contarCategorias()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Por favor, ingrese un numero valido entre 1 y "
                      << listaCategorias.contarCategorias() << ".\n";
        } else {
            break;
        }
    }

    NodoCategoria* categoriaSeleccionada = listaCategorias.obtenerNodoPorNumero(numeroCategoria);
    if (!categoriaSeleccionada) {
        std::cout << "Numero de categoria invalido. Operacion cancelada.\n";
        return;
    }

    // Mostrar productos de la categoría seleccionada
    std::cout << "Productos en la categoria \"" << categoriaSeleccionada->getCategoria()->getNombre() << "\":\n";
    categoriaSeleccionada->getCategoria()->getListaProductos()->display();

    // Selección de producto
    std::string nombreProducto;
    std::cout << "Ingrese el nombre del producto que desea eliminar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreProducto);

    // Eliminar producto
    categoriaSeleccionada->getCategoria()->getListaProductos()->eliminarProducto(nombreProducto);
}



////Categorias

void Menu::agregarCategoria() {
    std::string nombre, descripcion;

    std::cout << "Ingrese el nombre de la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la descripcion de la categoria: ";
    std::getline(std::cin, descripcion);

    Categoria* nuevaCategoria = new Categoria(nombre, descripcion);
    listaCategorias.agregarCategoria(nuevaCategoria);

    std::cout << "\nCategoria agregada exitosamente:\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Descripcion: " << descripcion << "\n";
}


void Menu::verCategoria() {
    listaCategorias.display();
}

void Menu::modificarCategoria() {
    if (listaCategorias.getHead() == nullptr) {
        std::cout << "No hay categorias disponibles.\n";
        return;
    }

    std::string nombreActual, nuevoNombre, nuevaDescripcion;

    std::cout << "Ingrese el nombre de la categoria a modificar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreActual);

    std::cout << "Ingrese el nuevo nombre de la categoria: ";
    std::getline(std::cin, nuevoNombre);

    std::cout << "Ingrese la nueva descripcion de la categoria: ";
    std::getline(std::cin, nuevaDescripcion);

    listaCategorias.modificarCategoria(nombreActual, nuevoNombre, nuevaDescripcion);
}


void Menu::eliminarCategoria() {
    string nombre;

    cout << "Ingrese el nombre de la categoria a eliminar: ";
    cin >> nombre;

    listaCategorias.eliminarCategoria(nombre);
}

