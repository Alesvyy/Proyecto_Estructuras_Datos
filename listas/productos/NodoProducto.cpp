//
// Created by Bryan Ramirez Campos on 11/23/24.
//

#include "NodoProducto.h"

NodoProducto::NodoProducto(Producto *producto) {
    setProducto(producto);
    setSiguiente(nullptr);
}

Producto *NodoProducto::getProducto() {
    return producto;
}
void NodoProducto::setProducto(Producto *producto) {
    this->producto = producto;
}
NodoProducto *NodoProducto::getSiguiente() {
    return siguienteProducto;
}
void NodoProducto::setSiguiente(NodoProducto *siguiente) {
    siguienteProducto = siguiente;
}
