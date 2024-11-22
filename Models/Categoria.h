#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string nombre;

public:
    // Constructor
    Categoria(const std::string& nombre);

    // Getter y setter
    std::string getNombre() const;
    void setNombre(const std::string& nuevoNombre);
};

#endif // CATEGORIA_H