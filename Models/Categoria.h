//
// Created by jl568 on 10/14/2024.
//

#ifndef CATEGORIA_H
#define CATEGORIA_H
#include<string>
#include "../listas/productos/ListaProductos.h"
using namespace std;

class Categoria {
private:
    long id;
    string descricion;
    string nombre;
    ListaProductos* listaProductos;

public:
    static long globalId;
    Categoria();
    Categoria(string nombre, string descripcion);
    Categoria(string nombre, string descripcion, long idCategoria);

    long getId();
    void setId(long pid);

    string getDescripcion();
    void setDescripcion(string pDescripcion);

    string getNombre();
    void setNombre(string pNombre);

    ListaProductos* getListaProductos();

    void setListaProductos(ListaProductos* lista);
};
#endif //CATEGORIA_H