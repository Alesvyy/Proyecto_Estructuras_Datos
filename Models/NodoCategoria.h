#ifndef NODOCATEGORIA_H
#define NODOCATEGORIA_H

#include "Categoria.h"

class NodoCategoria {
private:
    Categoria categoria;
    NodoCategoria* siguiente;
public:
    NodoCategoria(Categoria categoria);
    Categoria getCategoria() const;
    NodoCategoria* getSiguiente() const;
    void setSiguiente(NodoCategoria* siguiente);
};

#endif // NODOCATEGORIA_H