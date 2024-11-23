#include "Categoria.h"

Categoria::Categoria() = default;

Categoria::Categoria(std::string nombre, std::string descripcion)
    : nombre(std::move(nombre)), descricion(std::move(descripcion)) {}

std::string Categoria::getDescripcion() const {
    return descricion;
}

void Categoria::setDescripcion(const std::string& pDescripcion) {
    descricion = pDescripcion;
}

std::string Categoria::getNombre() const {
    return nombre;
}

void Categoria::setNombre(const std::string& pNombre) {
    nombre = pNombre;
}
