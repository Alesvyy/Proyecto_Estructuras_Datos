#ifndef MENU_H
#define MENU_H
#include "PracticaColas/Cola.h"
#include "db/SQLiteManager.h"
#include "listas/categorias/ListaCategorias.h"
#include "listas/productos/ListaProductos.h"

class Menu {
public:
    Menu();

    SQLiteManager* dbManager;
    void cargarDatosDB();
    void mostrarMenu();
    void mostrarMenuColas();
    void agregarProducto();
    void verProductos();
    void buscarProducto();
    void agregarCategoria();
    void eliminarCategoria();
    void verCategoria();
    void modificarProducto();
    void eliminarProducto();
    void modificarCategoria();
    void filtrarPorLetra();
    void filtrarCategoriasPorLetra();
    void filtrarPPrecio();

private:
    Cola cola;
    ListaCategorias* listaCategorias;
};

#endif // MENU_H
