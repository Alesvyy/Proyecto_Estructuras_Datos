#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
using namespace std;



class Producto {
public:
    // Constructor
    Producto(const std::string& nombre, double precio, const std::string& descripcion);

    // Getters
    std::string getNombre() const;
    double getPrecio() const;
    std::string getDescripcion() const;

private:
    string nombre;
    string descripcion;
    double precio;
    string categoria;

    void crearProducto(string nombre, string descripcion, double precio, string categoria) {
    }

    void mostrarProducto(){}

    void eliminarProducto(){}

    void modificarProd(){}

};



#endif //PRODUCTO_H
