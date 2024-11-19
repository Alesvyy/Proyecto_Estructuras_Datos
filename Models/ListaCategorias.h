//
// Created by kmq06 on 11/18/2024.
//

#ifndef LISTACATEGORIAS_H
#define LISTACATEGORIAS_H
#include "Categoria.h"
#include "NodoCategoria.h"


class ListaCategorias {
    public:
        ListaCategorias();
        ~ListaCategorias();

        void agregarCategoria(Categoria* categoria);
        void eliminarCategoria(string nombreCategoria);
        NodoCategoria* getHead();

    private:
        NodoCategoria* head;
        bool hayRepetidos(string nombreCategoria);
        void setHead(NodoCategoria* nuevoHead);



};



#endif //LISTACATEGORIAS_H
