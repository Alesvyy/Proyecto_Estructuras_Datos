//
// Created by jl568 on 11/30/2024.
//
#include "NodoVariante.h"

NodoVariante::NodoVariante(Variante *variante) {
    setVariante(variante);
    setSiguiente(nullptr);
}

Variante *NodoVariante::getVariante() {
    return variante;
}
void NodoVariante::setVariante(Variante *variante) {
    this->variante = variante;
}
NodoVariante *NodoVariante::getSiguiente() {
    return siguienteVariante;
}
void NodoVariante::setSiguiente(NodoVariante *siguiente) {
    siguienteVariante = siguiente;
}
