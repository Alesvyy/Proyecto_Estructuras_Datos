//
// Created by Bryan Ramirez Campos on 11/23/24.
//
#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H
#include "../../Models/Producto.h"

class NodoProducto {
private:
    Producto* producto;
    NodoProducto *siguienteProducto;

public:
    NodoProducto(Producto* producto);
    void setSiguiente(NodoProducto* siguiente);
    NodoProducto* getSiguiente();
    Producto* getProducto();
    void setProducto(Producto* producto);


};
#endif //NODOPRODUCTO_H