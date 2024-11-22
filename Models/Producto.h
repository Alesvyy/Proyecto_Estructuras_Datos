#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
using namespace std;



class Producto {
public:
    // Constructor
    Producto(const std::string& nombre, double precio, const std::string& descripcion);
    Producto(int id, const std::string& nombre, const std::string& descripcion, double precio, const std::string& categoria)
: id(id), nombre(nombre), descripcion(descripcion), precio(precio), categoria(categoria), siguiente(nullptr) {}

    // Getters
    std::string getNombre() const;
    double getPrecio() const;
    std::string getDescripcion() const;


    int id;
    std::string nombre;
    std::string descripcion;
    double precio;
    std::string categoria;
    Producto* siguiente;
private:

    void crearProducto(string nombre, string descripcion, double precio, string categoria) {
    }

    void mostrarProducto(){}

    void eliminarProducto(){}

    void modificarProd(){}

};




#endif //PRODUCTO_H
