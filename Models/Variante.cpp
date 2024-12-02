//
// Created by jl568 on 11/30/2024.
//
#include "Variante.h"

long Variante::globalId = 1;

Variante::Variante(string nombre, string especificacion, long idProducto) {
    setNombre(nombre);
    setEspecificacion(especificacion);
    setIdProducto(idProducto);
    setId(globalId);
    globalId += 1;
}

string Variante::getNombre() {
    return nombre;
}
string Variante::getEspecificacion() {
    return especificacion;
}

long Variante::getId() {
    return id;
}

long Variante::getIdProducto() {
    return idProducto;
}

void Variante::setId(long pId) {
    id = pId;
}

void Variante::setIdProducto(long pid) {
    idProducto = pid;
}

void Variante::setNombre(string pNombre) {
    nombre = pNombre;
}
void Variante::setEspecificacion(string pEspecificacion) {
    especificacion = pEspecificacion;
}


