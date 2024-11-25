//
// Created by kmq06 on 11/18/2024.
//

#ifndef LISTACATEGORIAS_H
#define LISTACATEGORIAS_H
#include "../../Models/Categoria.h"
#include "NodoCategoria.h"


class ListaCategorias {
    public:
        ListaCategorias();
        ~ListaCategorias();

        void agregarCategoria(Categoria* categoria);
        NodoCategoria* buscarCategoria(string nombreCategoria);
        NodoCategoria* buscarNodoAnterior(string nombreCategoria);
        void modificarCategoria(const std::string& nombreActual, const std::string& nuevoNombre);
        void eliminarCategoria(string nombreCategoria);
        NodoCategoria* getHead();
        void display();

    private:
        NodoCategoria* head;
        bool hayRepetidos(string nombreCategoria);
        void setHead(NodoCategoria* nuevoHead);



};



#endif //LISTACATEGORIAS_H
