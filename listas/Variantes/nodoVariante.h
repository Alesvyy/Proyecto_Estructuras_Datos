//
// Created by Bryan Ramirez Campos on 11/23/24.
//
#ifndef NODOVARIANTE_H
#define NODOVARIANTE_H
#include "../../Models/Variante.h"

class NodoVariante {


private:
    Variante* variante;
    NodoVariante *siguienteVariante;

public:
    NodoVariante(Variante* variante);

    Variante *getVariante();

    void setSiguiente(NodoVariante* siguiente);
    NodoVariante* getSiguiente();
    Variante* get_variante();
    void setVariante(Variante* variante);


};
#endif //NODOVARIANTE_H