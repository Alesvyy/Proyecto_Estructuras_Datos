#include "NodoCategoria.h"

NodoCategoria::NodoCategoria(Categoria categoria) : categoria(categoria), siguiente(nullptr) {}

Categoria NodoCategoria::getCategoria() const {
    return categoria;
}

NodoCategoria* NodoCategoria::getSiguiente() const {
    return siguiente;
}

void NodoCategoria::setSiguiente(NodoCategoria* siguiente) {
    this->siguiente = siguiente;
}