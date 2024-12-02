#ifndef VARIANTE_H
#define VARIANTE_H

#include <string>
#include <iostream>
using namespace std;

class Variante {

public:
    static long globalId;
    Variante();
    Variante(string nombre, string especificacion, long idProducto);

    string getNombre();
    string getEspecificacion();
    long getId();
    long getIdProducto();

    void setNombre(string pNombre);
    void setEspecificacion(string pEspecificacion);
    void setId(long pId);
    void setIdProducto(long pid);


private:
    long id;
    string nombre;
    string especificacion;
    long idProducto;

};
#endif //VARIANTE_H
