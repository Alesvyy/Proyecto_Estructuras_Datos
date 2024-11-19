#ifndef PIM_H
#define PIM_H
#include "Producto.h"
#include <iostream>
class PIM {
private:
    Producto* cabeza;
    int contadorID; // Contador para asignar IDs únicos a los productos
public:
    PIM() : cabeza(nullptr), contadorID(1) {}
    // Agregar un producto a la lista
    void agregarProducto(const std::string& nombre, const std::string& descripcion, double precio, const std::string& categoria);
    // Eliminar un producto por ID
    void eliminarProducto(int id);
    // Mostrar todos los productos
    void mostrarProductos();
    // Modificar un producto
    void modificarProducto(int id, const std::string& nombre, const std::string& descripcion, double precio, const std::string& categoria);
    // Consultar un producto
    void consultarProducto(int id);
    // Liberar memoria usada por los productos
    ~PIM();
};
#endif // PIM_H