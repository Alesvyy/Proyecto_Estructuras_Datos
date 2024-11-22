#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "Categoria.h"

class Menu {
private:
    std::vector<Categoria> categorias;

public:
    Menu();

    void mostrarMenu();
    void manejarOpciones();
    void agregarCategoria();
    void mostrarCategorias();
    void modificarCategoria();
    void eliminarCategoria();

    int obtenerNumeroCategoria();
    std::string obtenerNuevoNombre();

};

#endif // MENU_H