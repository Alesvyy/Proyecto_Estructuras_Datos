//
// Created by jl568 on 10/14/2024.
//

#include "Categoria.h"

Categoria::Categoria(string nombre, string descripcion) {
    setNombre(nombre);
    setDescripcion(descripcion);
}

string Categoria::getNombre() {
    return nombre;
}

void Categoria::setDescripcion(string pDescripcion) {
    descricion = pDescripcion;
}

void Categoria::setNombre(string pNombre) {
    nombre = pNombre;
}
