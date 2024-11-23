#ifndef LISTACATEGORIAS_H
#define LISTACATEGORIAS_H

#include <vector>
#include <string>
#include "Categoria.h"

class ListaCategorias {
private:
    std::vector<Categoria> categorias;

public:
    void agregarCategoria(const Categoria& categoria);
    void listarCategorias() const;
    std::vector<Categoria> getCategorias() const;
};

#endif // LISTACATEGORIAS_H
