#ifndef VARIANTE_H
#define VARIANTE_H

#include <string>
#include <iostream>
using namespace std;

class Variante {

public:
    Variante();
    Variante(string nombre, string especificacion);

    string getNombre();
    string getEspecificacion();

    void setNombre(string pNombre);
    void setEspecificacion(string pEspecificacion);


private:
    string nombre;
    string especificacion;

};
#endif //VARIANTE_H
