#ifndef MENU_H
#define MENU_H

#include "Models/Producto.h"
#include <vector>

class Menu {
public:
    Menu();
    void mostrarMenu();
    void agregarProducto();
    void verProductos();

private:
    std::vector<Producto> productos;
};

#endif // MENU_H
