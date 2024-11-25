#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
using namespace std;

class Producto {

public:
    Producto();
    Producto(string nombre, string descripcion, double precio);

    string getNombre();
    string getDescripcion();
    double getPrecio();

    void setDescripcion(string pDescripcion);
    void setNombre(string pNombre);
    void setPrecio(double pPrecio);

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
