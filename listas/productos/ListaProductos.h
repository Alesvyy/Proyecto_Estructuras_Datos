//
// Created by Bryan Ramirez Campos on 11/23/24.
//

#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H

#include "NodoProducto.h"
#include "../../Models/Producto.h"

class ListaProductos {
public:
    ListaProductos();
    ~ListaProductos();

    void agregarProducto(Producto* producto);
    NodoProducto* buscarProducto(string nombreProducto);
    NodoProducto* buscarNodoAnterior(string nombreProducto);
    void eliminarProducto(string nombreProducto);
    NodoProducto* getHead();
    void display();
    void modificarProducto(const std::string& nombreActual, const std::string& nuevoNombre, double nuevoPrecio);


    private:
        NodoProducto* head;
    bool hayRepetidos(string nombreProducto);
    void setHead(NodoProducto* nuevoHead);

};



#endif //LISTAPRODUCTOS_H
