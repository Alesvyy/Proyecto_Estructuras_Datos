#ifndef VARIANTE_H
#define VARIANTE_H

#include <string>
#include <iostream>
using namespace std;

class Variante {

public:
    static long globalId;
    Variante();
    Variante(string nombre, string especificacion);

    string getNombre();
    string getEspecificacion();
    long getId();

    void setNombre(string pNombre);
    void setEspecificacion(string pEspecificacion);
    void setId(long pId);


private:
    long id;
    string nombre;
    string especificacion;

};
#endif //VARIANTE_H
