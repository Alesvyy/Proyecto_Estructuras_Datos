using namespace std;
#include <iostream>
#include "ListaVariantes.h"

ListaVariantes::ListaVariantes() {
    head = nullptr;
}

ListaVariantes::~ListaVariantes() {
    NodoVariante* current = head;
    NodoVariante* next;
    while (current != nullptr) {
        next = current->getSiguiente();
        delete current;
        current = next;
    }
    head = nullptr;
}
void ListaVariantes::setHead(NodoVariante *nuevoHead) {
    head = nuevoHead;
}

void ListaVariantes::agregarVariante(Variante* variante) {
    if (!hayRepetidos(variante->getNombre())) {
        NodoVariante* nodoVarianteNuevo = new NodoVariante(variante);
        if (head == nullptr) {
            head =  nodoVarianteNuevo;
        } else {
            NodoVariante* temp = head;
            while (temp->getSiguiente() != nullptr) {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nodoVarianteNuevo);
        }
        std::cout << "La variante se agrego exitosamente: " << variante->getNombre() << "\n";
    }
}

NodoVariante* ListaVariantes::buscarVariante(string nombreVariante) {
    NodoVariante* temp = head;
    while (temp != nullptr) {
        if (temp->getVariante()->getNombre() == nombreVariante) {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return temp;
}

NodoVariante* ListaVariantes::buscarNodoAnterior(string nombreVariante) {
    if (head == nullptr) {
        return nullptr;
    }
    NodoVariante* temp = head;
    while (temp->getSiguiente() != nullptr) {
        if (temp->getSiguiente()->getVariante()->getNombre() == nombreVariante) {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return nullptr;
}


void ListaVariantes::eliminarVariante(string nombreVariante) {
    if (head->getVariante()->getNombre() == nombreVariante) {
        NodoVariante* temp = head;
        head = head->getSiguiente();
        delete temp;
        cout << "La Variante" << nombreVariante << " se ha eliminado" << endl;
        return;
    }
    NodoVariante* temp = buscarNodoAnterior(nombreVariante);
    if (temp != nullptr) {
        NodoVariante* nodoObjetivo = temp->getSiguiente();
        temp->setSiguiente(nodoObjetivo->getSiguiente());
        delete nodoObjetivo;
        cout << "La Variante " << nombreVariante << " se ha eliminado" << endl;
    } else {
        cout << "La Variante del Producto no se encontro " << nombreVariante<< endl;
    }
}

void ListaVariantes::display() {
    if (head == nullptr) {
        std::cout << "La lista esta vacia.\n";
        return;
    }
}


bool ListaVariantes::hayRepetidos(const std::string& nombre) {
    NodoVariante* temp = head;
    while (temp != nullptr) {
        if (temp->getVariante()->getNombre() == nombre) {
            return true;
        }
        temp = temp->getSiguiente();
    }
    return false;
}

int ListaVariantes::contarVariantes() const {
    int contador = 0;
    NodoVariante* temp = head;
    while (temp != nullptr) {
        contador++;
        temp = temp->getSiguiente();
    }
    return contador;
}

void ListaVariantes::modificarVariante(const std::string& nombreActual, const std::string& nuevoNombre,const std::string& nuevaEspecificacion) {
    NodoVariante* nodo = buscarVariante(nombreActual);

    if (nodo == nullptr) {
        std::cout << "La Variante del Producto \"" << nombreActual << "\" no existe.\n";
        return;
    }

    if (hayRepetidos(nuevoNombre) && nombreActual != nuevoNombre) {
        std::cout << "Ya existe una variante con ese nombre \"" << nuevoNombre << "\". No se puede modificar.\n";
        return;
    }

    nodo->getVariante()->setNombre(nuevoNombre);
    nodo->getVariante()->setEspecificacion(nuevaEspecificacion);

    std::cout << "La variante ha sido modificado correctamente:\n"
              << "Nombre: \"" << nuevoNombre << "\"\n"
              << "Especificacion: " << nuevaEspecificacion << "\n";

}


void ListaVariantes::modificarVariantePorNombre(const std::string& nuevoNombre,const std::string& nuevaEspecificacion) {
    NodoVariante* nodo = obtenerNodoPorNombre(nuevoNombre);

    if (nodo == nullptr) {
        std::cout << "El nombre ingresado no corresponde a ninguna variante.\n";
        return;
    }

    if (hayRepetidos(nuevoNombre)) {
        std::cout << "Ya existe una variante con el nombre \"" << nuevoNombre << "\". No se puede modificar.\n";
        return;
    }

    nodo->getVariante()->setNombre(nuevoNombre);
    nodo->getVariante()->setEspecificacion(nuevaEspecificacion);

    std::cout << "La variante ha sido modificado correctamente:\n"
              << "Nombre: \"" << nuevoNombre << "\"\n"
              << "Especificacion: " << nuevaEspecificacion << "\n";
}

