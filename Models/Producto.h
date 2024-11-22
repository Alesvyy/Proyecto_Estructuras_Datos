#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using namespace std;
class Producto {
private:
    string nombre;
    string descripcion;
    double precio;
public:
    Producto();
    Producto(string nombre, string descripcion, double precio);
    string getNombre();
    string getDescripcion();
    double getPrecio();
    void setDescripcion(string pDescripcion);
    void setNombre(string pNombre);
    void setPrecio(double pPrecio);
};
#endif //PRODUCTO_H