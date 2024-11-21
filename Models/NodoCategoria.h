//
// Created by kmq06 on 11/18/2024.
//

#ifndef NODOCATEGORIA_H
#define NODOCATEGORIA_H
#include "Categoria.h"


class NodoCategoria {
private:
    Categoria* categoria;
    NodoCategoria *siguienteCategoria;

public:
    NodoCategoria(Categoria* categoria);
    void setSiguiente(NodoCategoria* siguiente);
    NodoCategoria* getSiguiente();
    Categoria* getCategoria();
    void setCategoria(Categoria* categoria);

};



#endif //NODOCATEGORIA_H
