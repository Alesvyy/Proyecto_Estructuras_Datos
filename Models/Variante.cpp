//
// Created by jl568 on 11/30/2024.
//
#include "Variante.h"

Variante::Variante(string nombre, string especificacion) {
    setNombre(nombre);
    setEspecificacion(especificacion);
}

string Variante::getNombre() {
    return nombre;
}
string Variante::getEspecificacion() {
    return especificacion;
}

void Variante::setNombre(string pNombre) {
    nombre = pNombre;
}
void Variante::setEspecificacion(string pEspecificacion) {
    especificacion = pEspecificacion;
}


