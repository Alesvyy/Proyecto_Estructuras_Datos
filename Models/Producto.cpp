//
// Created by Bryan Ramirez Campos on 14/10/24.
//

#include "Producto.h"

// Constructor
Producto::Producto(const std::string& nombre, double precio, const std::string& descripcion)
    : nombre(nombre), precio(precio), descripcion(descripcion) {}

// Getters
std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

std::string Producto::getDescripcion() const {
    return descripcion;
}
