//
// Created by kmq06 on 11/18/2024.
//

#include "EliminarProducto.h"
#include "PIM.h"

void EliminarProducto::eliminarProducto(PIM& sistemaPIM) {
    int id;
    std::cout << "Ingrese el ID del producto a eliminar: ";
    std::cin >> id;
    sistemaPIM.eliminarProducto(id);
}
