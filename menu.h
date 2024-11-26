#ifndef MENU_H
#define MENU_H
#include "PracticaColas/Cola.h"
#include "Models/Producto.h"
#include <vector>
#include "listas/categorias/ListaCategorias.h"
#include "listas/productos/ListaProductos.h"

class Menu {
public:
    Menu();

    void mostrarMenu();
    void mostrarMenuColas();
    void agregarProducto();
    void verProductos();
    void agregarCategoria();
    void eliminarCategoria();
    void verCategoria();
    void modificarProducto();
    void eliminarProducto();
    void modificarCategoria();

private:
    Cola cola;
    ListaCategorias listaCategorias;
    ListaProductos listaProductos;

};

#endif // MENU_H
