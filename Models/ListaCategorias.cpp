// ListaCategorias.cpp
#include "ListaCategorias.h"

void ListaCategorias::agregarCategoria(const Categoria& categoria) {
    categorias.push_back(categoria);
}

void ListaCategorias::listarCategorias() const {
    if (categorias.empty()) {
        std::cout << "No hay categorias disponibles\n";
        std::cout << "\n";
    } else {
        for (const auto& categoria : categorias) {
            std::cout << categoria.getNombre() << "\n";
        }
    }
}

std::vector<Categoria> ListaCategorias::getCategorias() const {
    return categorias;
}