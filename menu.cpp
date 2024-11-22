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
    std::string nombre;
    std::cout << "\nIngrese el nombre de la categoria: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    for (const auto& categoria : categorias) {
        if (categoria.getNombre() == nombre) {
            std::cout << "Error: La categoria '" << nombre << "' ya existe.\n";
            return;
        }
    }

    Categoria nuevaCategoria(nombre);
    categorias.push_back(nuevaCategoria);
    std::cout << "Categoria '" << nombre << "' agregada correctamente.\n";
}


void Menu::mostrarCategorias() {
    if (categorias.empty()) {
        std::cout << "\n";
        std::cout << "No hay categorias disponibles.\n";
    } else {
        std::cout << "\n";
        std::cout << "Categorias disponibles:\n";
        std::cout << "\n";
        std::cout << "---------------\n";
        for (size_t i = 0; i < categorias.size(); ++i) {
            std::cout << i + 1 << ". " << categorias[i].getNombre() << "\n";
            std::cout << "---------------\n";
        }

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

    std::string nuevoNombre = obtenerNuevoNombre();

    if (numeroCategoria >= 1 && numeroCategoria <= categorias.size()) {
        categorias[numeroCategoria - 1].setNombre(nuevoNombre);
        std::cout << "\nCategoria modificada correctamente.\n";
    } else {
        std::cout << "\nIndice fuera de rango.\n";
    }
}


int Menu::obtenerNumeroCategoria() {
    int numeroCategoria;
    std::cout << "\nIngrese el numero de la categoria que desea eliminar: ";
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