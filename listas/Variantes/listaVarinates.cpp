using namespace std;
#include <iostream>
#include "listaVariantes.h"

listaVariantes::listaVariantes() {
    head = nullptr;
}

listaVariantes::~listaVariantes() {
    NodoVariante* current = head;
    NodoVariante* next;
    while (current != nullptr) {
        next = current->getSiguiente();
        delete current;
        current = next;
    }
    head = nullptr;
}
void listaVariantes::setHead(NodoVariante *nuevoHead) {
    head = nuevoHead;
}

