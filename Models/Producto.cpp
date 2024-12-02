#include "Producto.h"

long Producto::globalId = 1;

Producto::Producto(string nombre, string descripcion, double precio) {
    setVariantes(new ListaVariantes());
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
    setId(globalId);
    globalId += 1;
}

Producto::Producto(string nombre, string descripcion, double precio, string sku) {
    setVariantes(new ListaVariantes());
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
    setSku(sku);
    setId(globalId);
    globalId += 1;
}

Producto::Producto(string nombre, string descripcion, double precio, string sku, long categoriaId) {
    setVariantes(new ListaVariantes());
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
    setSku(sku);
    setIdCategoria(categoriaId);
    setId(globalId);
    globalId += 1;
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

long Producto::getId() {
    return id;
}

ListaVariantes *Producto::getVariantes() {
    return variantes;
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

void Producto::setId(long pid) {
    id = pid;
}

void Producto::setVariantes(ListaVariantes* pvariantes) {
    variantes = pvariantes;
}


