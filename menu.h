#ifndef MENU_H
#define MENU_H
#include "PracticaColas/Cola.h"
#include "Models/Producto.h"
#include <vector>

class Menu {
public:
    Menu();
    void mostrarMenu();
    void mostrarMenuColas();
    void agregarProducto();
    void verProductos();

private:
    Cola cola;
};

#endif // MENU_H
