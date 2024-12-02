//
// Created by Bryan Ramirez Campos on 11/23/24.
//

#ifndef LISTAVARIANTES_H
#define LISTAVARIANTES_H

#include "nodoVariante.h"
#include "../../Models/Variante.h"

class listaVariantes {
public:
    listaVariantes();
    ~listaVariantes();

    void agregarVariante(Variante* variante);
    void eliminarVariante(string nombreProducto);
    NodoVariante* getHead();
    void display();
    void modificarVariante(const std::string& colorActual, const std::string& nuevoColor,
        const std::string& materialActual,const std::string& nuevoMaterial, double nuevaTalla);
    bool hayRepetidos(const std::string& variante);


private:
    NodoVariante* head;
    void setHead(NodoVariante* nuevoHead);

};



#endif //LISTAVARIANTES_H