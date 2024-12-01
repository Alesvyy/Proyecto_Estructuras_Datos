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
    void modificarProducto(const std::string& nombreActual, const std::string& nuevoNombre, double nuevoPrecio, const std::string& nuevaDescripcion);
    void modificarProductoPorNumero(int numeroProducto, const std::string& nuevoNombre, double nuevoPrecio, const std::string& nuevaDescripcion);
    int contarProductos() const;
    NodoProducto* obtenerNodoPorNumero(int numero);
    bool hayRepetidos(const std::string& nombre);
    void filtrarPPrecio(double pMin, double pMax);


private:
    NodoProducto* head;
    void setHead(NodoProducto* nuevoHead);

};



#endif //LISTAPRODUCTOS_H
