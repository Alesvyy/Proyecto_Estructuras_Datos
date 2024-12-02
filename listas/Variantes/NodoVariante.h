#ifndef NODOVARIANTE_H
#define NODOVARIANTE_H
#include "../../Models/Variante.h"

class NodoVariante {


private:
    Variante* variante;
    NodoVariante*siguienteVariante;

public:
    NodoVariante(Variante* variante);
    void setSiguiente(NodoVariante* siguiente);
    NodoVariante* getSiguiente();
    Variante* getVariante();
    void setVariante(Variante* variante);


};
#endif //NODOVARIANTE_H