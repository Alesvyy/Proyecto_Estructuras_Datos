#include "Producto.h"

Producto::Producto(string nombre, string descripcion, double precio) {
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
}

Producto::Producto(string nombre, string descripcion, double precio, string sku) {
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
    setSku(sku);
}

string Producto::getNombre() {
    return nombre;
}

string Producto::getDescripcion() {
    return descripcion;
}

double Producto::getPrecio() {
    return precio;
}

string Producto::getSku() {
    return sku;
}

void Producto::setDescripcion(string pDescripcion) {
    descripcion = pDescripcion;
}

void Producto::setNombre(string pNombre) {
    nombre = pNombre;
}

void Producto::setSku(string pSku) {
    sku = pSku;
}

void Producto::setPrecio(double pPrecio) {
    precio = pPrecio;
}
