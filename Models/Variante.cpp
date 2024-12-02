//
// Created by jl568 on 11/30/2024.
//
#include "Variante.h"

Variante::Variante(string color, string material, double talla) {
    setColor(color);
    setMaterial(material);
    setTalla(talla);
}

string Variante::getColor() {
    return color;
}
string Variante::getMaterial() {
    return material;
}
double Variante::getTalla() {
    return talla;
}

void Variante::setColor(string pColor) {
    color = pColor;
}
void Variante::setMaterial(string pMaterial) {
    material = pMaterial;
}

void Variante::setTalla(double pTalla) {
    talla = pTalla;
}
