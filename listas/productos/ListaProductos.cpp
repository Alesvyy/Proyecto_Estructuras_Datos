//
// Created by Bryan Ramirez Campos on 11/23/24.
//
using namespace std;
#include <iostream>
#include "ListaProductos.h"

ListaProductos::ListaProductos() {
     head = nullptr;
}

ListaProductos::~ListaProductos() {
     NodoProducto* current = head;
     NodoProducto* next;
     while (current != nullptr) {
         next = current->getSiguiente();
         delete current;
         current = next;
     }
     head = nullptr;
}

void ListaProductos::setHead(NodoProducto *nuevoHead) {
 head = nuevoHead;
}

void ListaProductos::agregarProducto(Producto* producto) {
    if (!hayRepetidos(producto->getNombre())) {
        NodoProducto* nodoProductoNuevo = new NodoProducto(producto);
        if (head == nullptr) {
            head = nodoProductoNuevo;
        } else {
            NodoProducto* temp = head;
            while (temp->getSiguiente() != nullptr) {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nodoProductoNuevo);
        }
        std::cout << "Producto agregado exitosamente: " << producto->getNombre() << "\n";
    } else {
        std::cout << "Ya existe un producto con el nombre \"" << producto->getNombre() << "\".\n";
    }
}

NodoProducto* ListaProductos::buscarProducto(string nombreProducto) {
     NodoProducto* temp = head;
     while (temp != nullptr) {
         if (temp->getProducto()->getNombre() == nombreProducto) {
             return temp;
         }
         temp = temp->getSiguiente();
     }
     return temp;
}

NodoProducto* ListaProductos::buscarNodoAnterior(string nombreProducto) {
     if (head == nullptr) {
         return nullptr;
     }
     NodoProducto* temp = head;
     while (temp->getSiguiente() != nullptr) {
         if (temp->getSiguiente()->getProducto()->getNombre() == nombreProducto) {
             return temp;
         }
         temp = temp->getSiguiente();
     }
     return nullptr;
}

NodoProducto* ListaProductos::obtenerNodoPorNumero(int numero) {
    if (head == nullptr) {
        return nullptr;
    }
    NodoProducto* temp = head;
    int contador = 1;

    while (temp != nullptr) {
        if (contador == numero) {
            return temp;
        }
        temp = temp->getSiguiente();
        contador++;
    }
    return nullptr;
}



void ListaProductos::eliminarProducto(string nombreProducto) {
     if (head == nullptr) {
         cout << "La lista esta vacia" << endl;
         return;
     }
     if (head->getProducto()->getNombre() == nombreProducto) {
         NodoProducto* temp = head;
         head = head->getSiguiente();
         delete temp;
         cout << "El producto " << nombreProducto << " se ha eliminado" << endl;
         return;
     }
     NodoProducto* temp = buscarNodoAnterior(nombreProducto);
     if (temp != nullptr) {
         NodoProducto* nodoObjetivo = temp->getSiguiente();
         temp->setSiguiente(nodoObjetivo->getSiguiente());
         delete nodoObjetivo;
         cout << "El producto " << nombreProducto << " se ha eliminado" << endl;
     } else {
         cout << "No se encontro el producto " << nombreProducto << endl;
     }
}

void ListaProductos::display() {
    if (head == nullptr) {
        std::cout << "La lista esta vacia.\n";
        return;
    }

    NodoProducto* temp = head;
    int contador = 1;
    while (temp != nullptr) {
        std::cout << contador << ". "
                  << temp->getProducto()->getNombre()
                  << " - Precio: " << temp->getProducto()->getPrecio()
                  << " Colones\n";
        std::cout << "   Descripcion: " << temp->getProducto()->getDescripcion() << "\n";
        temp = temp->getSiguiente();
        contador++;
    }
}



bool ListaProductos::hayRepetidos(const std::string& nombre) {
    NodoProducto* temp = head;
    while (temp != nullptr) {
        if (temp->getProducto()->getNombre() == nombre) {
            return true;
        }
        temp = temp->getSiguiente();
    }
    return false;
}

int ListaProductos::contarProductos() const {
    int contador = 0;
    NodoProducto* temp = head;
    while (temp != nullptr) {
        contador++;
        temp = temp->getSiguiente();
    }
    return contador;
}

void ListaProductos::modificarProducto(const std::string& nombreActual, const std::string& nuevoNombre, double nuevoPrecio) {
    NodoProducto* nodo = buscarProducto(nombreActual);

    if (nodo == nullptr) {
        std::cout << "El producto con el nombre \"" << nombreActual << "\" no existe." << std::endl;
        return;
    }

    if (hayRepetidos(nuevoNombre)) {
        std::cout << "Ya existe un producto con el nombre \"" << nuevoNombre << "\". No se puede modificar." << std::endl;
        return;
    }

    nodo->getProducto()->setNombre(nuevoNombre);
    nodo->getProducto()->setPrecio(nuevoPrecio);

    std::cout << "El producto ha sido modificado correctamente a:\n"
           << "Nombre: \"" << nuevoNombre << "\"\n"
           << "Precio: " << nuevoPrecio << " Colones" << std::endl;
}

void ListaProductos::modificarProductoPorNumero(int numeroProducto, const std::string& nuevoNombre, double nuevoPrecio, const std::string& nuevaDescripcion) {
    NodoProducto* nodo = obtenerNodoPorNumero(numeroProducto);

    if (nodo == nullptr) {
        std::cout << "El numero ingresado no corresponde a ningun producto.\n";
        return;
    }

    if (hayRepetidos(nuevoNombre)) {
        std::cout << "Ya existe un producto con el nombre \"" << nuevoNombre << "\". No se puede modificar.\n";
        return;
    }

    nodo->getProducto()->setNombre(nuevoNombre);
    nodo->getProducto()->setPrecio(nuevoPrecio);
    nodo->getProducto()->setDescripcion(nuevaDescripcion);

    std::cout << "El producto ha sido modificado correctamente:\n"
              << "Nombre: \"" << nuevoNombre << "\"\n"
              << "Precio: " << nuevoPrecio << " Colones\n"
              << "Descripción: \"" << nuevaDescripcion << "\"\n";
}

