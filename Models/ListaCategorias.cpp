//
// Created by kmq06 on 11/18/2024.
//
using namespace std;
#include <iostream>
#include "ListaCategorias.h"

ListaCategorias::ListaCategorias() {
    head = nullptr;
}

ListaCategorias::~ListaCategorias() {
    NodoCategoria* current = head;
    NodoCategoria* next;
    while (current != nullptr) {
        next = current->getSiguiente();
        delete current;
        current = next;
    }
    head = nullptr;
}

void ListaCategorias::setHead(NodoCategoria *nuevoHead) {
    head = nuevoHead;
}

void ListaCategorias::agregarCategoria(Categoria *categoria) {
    if (!hayRepetidos(categoria->getNombre())) {
        NodoCategoria* nodoCategoriaNueva = new NodoCategoria(categoria);

        if (head == nullptr) {
            setHead(nodoCategoriaNueva);
        } else {
            NodoCategoria* temp = head;
            while (temp-> getSiguiente() != nullptr) {
                temp = temp-> getSiguiente();
            }
            temp->setSiguiente(nodoCategoriaNueva);
        }
    } else {
        cout <<"Ya existe esta categoria"<< endl;
    }

}

bool ListaCategorias::hayRepetidos(string nombreCategoria) {
    bool repetido = false;
    NodoCategoria* temp = head;

    while (temp != nullptr && !repetido) {
        if (temp->getCategoria()->getNombre() == nombreCategoria) {
            repetido = true;
        }
        temp = temp->getSiguiente();
    }
    return repetido;
}


