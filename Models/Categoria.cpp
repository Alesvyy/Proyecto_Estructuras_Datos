#include "Categoria.h"

// Constructor
Categoria::Categoria(const std::string& nombre) : nombre(nombre) {}

// Getter
std::string Categoria::getNombre() const {
    return nombre;
}

// Setter
void Categoria::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}
