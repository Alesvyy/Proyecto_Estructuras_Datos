#include "ListaCategorias.h"
#include <iostream>

void ListaCategorias::agregarCategoria(const Categoria& categoria) {
    categorias.push_back(categoria);
}

void ListaCategorias::listarCategorias() const {
    if (categorias.empty()) {
        std::cout << "No hay categorias disponibles\n";
        std::cout << "\n";
    } else {
        for (const auto& categoria : categorias) {
            std::cout << "Nombre: " << categoria.getNombre() << ", ";
            std::cout << "Descripcion: " << categoria.getDescripcion() << "\n";
        }
    }
}

std::vector<Categoria> ListaCategorias::getCategorias() const {
    return categorias;
}