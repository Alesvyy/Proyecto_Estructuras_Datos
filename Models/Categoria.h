//
// Created by jl568 on 10/14/2024.
//

#ifndef CATEGORIA_H
#define CATEGORIA_H
#include<string>
using namespace std;



class Categoria {
    string descricion;
    string nombre;

public:
    Categoria();

    string getDescripcion();
    void setDescripcion(string pDescripcion);

    string getNombre();
    void setNombre(string pNombre);



};



#endif //CATEGORÍA_H