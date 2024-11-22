#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H
#include "Producto.h"
#include "NodoProducto.h"
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
private:
 NodoProducto* head;
 bool hayRepetidos(string nombreProducto);
 void setHead(NodoProducto* nuevoHead);
};
#endif //LISTAPRODUCTOS_H