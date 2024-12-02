//
// Created by Bryan Ramirez Campos on 11/23/24.
//

#ifndef LISTAVARIANTES_H
#define LISTAVARIANTES_H

#include "NodoVariante.h"
#include "../../Models/Variante.h"

class ListaVariantes {
public:
    ListaVariantes();
    ~ListaVariantes();

    void agregarVariante(Variante* variante);
    NodoVariante* buscarVariante(string nombreVariante);
    NodoVariante* buscarNodoAnterior(string nombreVariante);
    void eliminarVariante(string nombreVariante);
    NodoVariante* getHead();
    void display();
    void modificarVariante(const std::string& nombreActual, const std::string& nuevoNombre,
        const std::string& nuevaEspecificacion);

    NodoVariante * obtenerNodoPorNombre();

    NodoVariante * obtenerNodoPorNombre(const string & string);

    void modificarVariantePorNombre(const std::string& nuevoNombre,const std::string& nuevaEspecificacion);
    int contarVariantes() const;
    NodoVariante* obtenerNodoPorNumero(int numero);
    bool hayRepetidos(const std::string& variante);


private:
    NodoVariante* head;
    void setHead(NodoVariante* nuevoHead);

};



#endif //LISTAVARIANTES_H