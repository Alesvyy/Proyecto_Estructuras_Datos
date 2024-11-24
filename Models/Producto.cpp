#include "Producto.h"

Producto::Producto(string nombre, string descripcion, double precio) {
    setNombre(nombre);
    setDescripcion(descripcion);
    setPrecio(precio);
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
void Producto::setDescripcion(string pDescripcion) {
    descripcion = pDescripcion;
}
void Producto::setNombre(string pNombre) {
    nombre = pNombre;
}
void Producto::setPrecio(double pPrecio) {
    precio = pPrecio;
}