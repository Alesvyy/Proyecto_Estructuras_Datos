#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

#include "../listas/Variantes/ListaVariantes.h"
using namespace std;

class Producto {

public:
    static long globalId;
    Producto();
    Producto(string nombre, string descripcion, double precio);
    Producto(string nombre, string descripcion, double precio, string sku);
    Producto(string nombre, string descripcion, double precio, string sku, long categoriaId);

    string getNombre();
    string getDescripcion();
    double getPrecio();
    string getSku();
    long getIdCategoria();
    long getId();

    void setDescripcion(string pDescripcion);
    void setNombre(string pNombre);
    void setPrecio(double pPrecio);
    void setSku(string pSku);
    void setIdCategoria(long pidCategoria);
    void setId(long id);

private:
    long id;
    string nombre;
    string descripcion;
    double precio;
    long idCategoria;
    string sku;
    ListaVariantes* variantes;

};

#endif //PRODUCTO_H
