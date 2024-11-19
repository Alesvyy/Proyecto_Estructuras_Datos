//
// Created by kmq06 on 11/18/2024.
//

#include "AgregarProducto.h"
#include "PIM.h"
void AgregarProducto::agregarProducto(PIM& sistemaPIM) {
    std::string nombre, descripcion, categoria;
    double precio;
    std::cout << "Ingrese el nombre del producto: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese la descripcion del producto: ";
    std::getline(std::cin, descripcion);
    std::cout << "Ingrese el precio del producto: ";
    std::cin >> precio;
    std::cout << "Ingrese la categoria del producto: ";
    std::cin.ignore();
    std::getline(std::cin, categoria);
    sistemaPIM.agregarProducto(nombre, descripcion, precio, categoria);
}