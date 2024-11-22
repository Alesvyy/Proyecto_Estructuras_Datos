#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string descricion;
    std::string nombre;

public:
    Categoria();
    Categoria(std::string nombre, std::string descripcion);

    std::string getDescripcion() const;
    void setDescripcion(const std::string& pDescripcion);

    std::string getNombre() const;
    void setNombre(const std::string& pNombre);
};

#endif // CATEGORIA_H
