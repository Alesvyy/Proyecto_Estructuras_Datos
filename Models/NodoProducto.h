#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H
#include "Producto.h"
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