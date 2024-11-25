//
// Created by kmq06 on 11/18/2024.
//

#include "NodoCategoria.h"

NodoCategoria::NodoCategoria(Categoria *categoria) {
    setCategoria(categoria);
    setSiguiente(nullptr);
}


Categoria *NodoCategoria::getCategoria() {
    return categoria;
}

void NodoCategoria::setCategoria(Categoria *categoria) {
    this->categoria = categoria;
}


NodoCategoria *NodoCategoria::getSiguiente() {
    return siguienteCategoria;
}

void NodoCategoria::setSiguiente(NodoCategoria *siguiente) {
    siguienteCategoria = siguiente;
}
