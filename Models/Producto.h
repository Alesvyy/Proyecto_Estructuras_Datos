#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
using namespace std;

class Producto {

public:
    Producto();
    Producto(string nombre, string descripcion, double precio);
    Producto(string nombre, string descripcion, double precio, string sku);

    string getNombre();
    string getDescripcion();
    double getPrecio();
    string getSku();

    void setDescripcion(string pDescripcion);
    void setNombre(string pNombre);
    void setPrecio(double pPrecio);
    void setSku(string pSku);

private:
    string nombre;
    string descripcion;
    double precio;
    string categoria;
    string sku;

    void crearProducto(string nombre, string descripcion, double precio, string categoria) {
    }

    void mostrarProducto(){}

    void eliminarProducto(){}

    void modificarProd(){}

};

#endif //PRODUCTO_H
