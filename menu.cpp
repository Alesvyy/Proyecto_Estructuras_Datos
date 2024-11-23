#include "Menu.h"
#include "Categoria.h"
#include <limits>

Menu::Menu() = default;

void Menu::mostrarMenu() {
    std::cout << "Bienvenido al Proyecto de Estructuras de Datos\n";
    manejarOpciones();
}

void Menu::manejarOpciones() {
    int opcion;
    do {
        std::cout << "\n";
        std::cout << "1. Agregar Categoria\n";
        std::cout << "2. Modificar Categoria\n";
        std::cout << "3. Mostrar Categoria\n";
        std::cout << "4. Eliminar Categoria\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                agregarCategoria();
            break;
            case 2:
                modificarCategoria();
            break;
            case 3:
                mostrarCategorias();
            break;
            case 4:
                eliminarCategoria();
            break;
            case 0:
                std::cout << "Saliendo...\n";
            break;
            default:
                std::cout << "Opcion no valida\n";
        }
    } while(opcion != 0);
}

void Menu::eliminarCategoria() {
    if (categorias.empty()) {
        std::cout << "\nNo hay categorias disponibles para eliminar.\n";
        return;
    }

    int numeroCategoria = obtenerNumeroCategoria();

    while (numeroCategoria < 1 || numeroCategoria > categorias.size()) {
        std::cout << "\nError: Indice de categoria fuera de rango. Ingrese un numero entre 1 y "
                  << categorias.size() << ".\n";
        numeroCategoria = obtenerNumeroCategoria();
    }

    categorias.erase(categorias.begin() + (numeroCategoria - 1));
    std::cout << "\nCategoria eliminada correctamente.\n";
}

void Menu::agregarCategoria() {
    std::string nombre, descripcion;

    std::cout << "\nIngrese el nombre de la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    for (const auto& categoria : categorias) {
        if (categoria.getNombre() == nombre) {
            std::cout << "Error: La categoria '" << nombre << "' ya existe.\n";
            return;
        }
    }

    std::cout << "Ingrese la descripcion de la categoria: ";
    std::getline(std::cin, descripcion);

    Categoria nuevaCategoria(nombre, descripcion);
    categorias.push_back(nuevaCategoria);
    std::cout << "Categoria '" << nombre << "' agregada correctamente.\n";
}

void Menu::mostrarCategorias() {
    if (categorias.empty()) {
        std::cout << "\nNo hay categorias disponibles.\n";
    } else {
        std::cout << "\nCategorias disponibles:\n";
        for (size_t i = 0; i < categorias.size(); ++i) {
            std::cout << "---------------\n";
            std::cout << i + 1 << ". Nombre: " << categorias[i].getNombre() << "\n";
            std::cout << "   Descripcion: " << categorias[i].getDescripcion() << "\n";
        }
        std::cout << "---------------\n";
    }
}

void Menu::modificarCategoria() {
    if (categorias.empty()) {
        std::cout << "\nNo hay categorias disponibles para modificar.\n";
        return;
    }

    int numeroCategoria = obtenerNumeroCategoria();

    while (numeroCategoria < 1 || numeroCategoria > categorias.size()) {
        std::cout << "\nError: Indice de categoria fuera de rango. Ingrese un numero entre 1 y "
                  << categorias.size() << ".\n";
        numeroCategoria = obtenerNumeroCategoria();
    }

    std::cout << "\nCategoria seleccionada:\n";
    std::cout << "Nombre: " << categorias[numeroCategoria - 1].getNombre() << "\n";
    std::cout << "Descripcion: " << categorias[numeroCategoria - 1].getDescripcion() << "\n";

    std::string nuevoNombre = obtenerNuevoNombre();
    categorias[numeroCategoria - 1].setNombre(nuevoNombre);

    std::cout << "\nNombre modificado correctamente.\n";

    std::string respuesta;
    std::cout << "\nDeseas modificar la descripcion? (Y/N): ";
    std::cin >> respuesta;

    if (respuesta == "Y" || respuesta == "y" || respuesta == "S" || respuesta == "s" ||
        respuesta == "Yes" || respuesta == "yes" || respuesta == "Si" || respuesta == "si") {

        std::cin.ignore();
        std::string nuevaDescripcion;
        std::cout << "\nIngrese la nueva descripcion: ";
        std::getline(std::cin, nuevaDescripcion);

        categorias[numeroCategoria - 1].setDescripcion(nuevaDescripcion);

        std::cout << "\nDescripcion modificada correctamente.\n";
        } else {
            std::cout << "\nDescripcion no modificada.\n";
        }
}

int Menu::obtenerNumeroCategoria() {
    int numeroCategoria;
    std::cout << "\nIngrese el numero de la categoria que desea usar: ";
    std::cin >> numeroCategoria;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nEntrada invalida. Por favor ingrese un numero valido: ";
        std::cin >> numeroCategoria;
    }

    return numeroCategoria;
}

std::string Menu::obtenerNuevoNombre() {
    std::string nuevoNombre;
    std::cout << "\nIngrese el nuevo nombre para la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, nuevoNombre);
    return nuevoNombre;
}
