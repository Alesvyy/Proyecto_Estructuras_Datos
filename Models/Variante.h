#ifndef VARIANTE_H
#define VARIANTE_H

#include <string>
#include <iostream>
using namespace std;

class Variante {

public:
    Variante();
    Variante(string color, string material,double talla);

    string getColor();
    string getMaterial();
    double getTalla();

    void setColor(string pColor);
    void setMaterial(string pMaterial);
    void setTalla(double pTalla);

private:
    string color;
    string material;
    double talla;

    void crearVariante(string color, string material, double talla) {
    }

    void mostrarVariante(){}

    void eliminarVariante(){}

    void modificarVariante(){}

};

#endif //VARIANTE_H
