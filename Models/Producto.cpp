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

Producto::Producto(string nombre, string descripcion, double precio, string sku, long categoriaId) {
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
    setSku(sku);
    setIdCategoria(categoriaId);
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
long Producto::getIdCategoria() {
    return idCategoria;
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
void Producto::setIdCategoria(long pidCategoria) {
    idCategoria = pidCategoria;
}

