// ListaCategorias.h
#ifndef LISTACATEGORIAS_H
#define LISTACATEGORIAS_H

#include "Categoria.h"
#include <vector>
#include <iostream>

class ListaCategorias {
public:
    void agregarCategoria(const Categoria& categoria);

    void listarCategorias() const;

    std::vector<Categoria> getCategorias() const;

private:
    std::vector<Categoria> categorias;
};

#endif