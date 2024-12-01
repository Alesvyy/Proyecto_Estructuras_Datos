#ifndef NODOCATEGORIA_H
#define NODOCATEGORIA_H
#include "../../Models/Categoria.h"


class NodoCategoria {
private:
    Categoria* categoria;
    NodoCategoria *siguienteCategoria;

public:
    NodoCategoria(Categoria* categoria);
    void setSiguiente(NodoCategoria* siguiente);
    NodoCategoria* getSiguiente();  // Este es el getter que vamos a utilizar
    Categoria* getCategoria();
    void setCategoria(Categoria* categoria);
};

#endif //NODOCATEGORIA_H
