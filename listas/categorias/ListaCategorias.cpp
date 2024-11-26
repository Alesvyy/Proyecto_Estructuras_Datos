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

void ListaCategorias::agregarCategoria(Categoria* categoria) {
    if (!hayRepetidos(categoria->getNombre())) {
        NodoCategoria* nodoCategoriaNuevo = new NodoCategoria(categoria);
        if (head == nullptr) {
            head = nodoCategoriaNuevo;
        } else {
            NodoCategoria* temp = head;
            while (temp->getSiguiente() != nullptr) {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nodoCategoriaNuevo);
        }
        std::cout << "Categoria agregada exitosamente: " << categoria->getNombre() << "\n";
    } else {
        std::cout << "Ya existe una categoria con el nombre \"" << categoria->getNombre() << "\".\n";
    }
}


void ListaCategorias::modificarCategoria(const string& nombreActual, const string& nuevoNombre) {

    NodoCategoria* nodo = buscarCategoria(nombreActual);

    if (nodo == nullptr) {
        cout << "La categoria con el nombre \"" << nombreActual << "\" no existe." << endl;
        return;
    }

    nodo->getCategoria()->setNombre(nuevoNombre);
    cout << "El nombre de la categoria ha sido modificado correctamente a \"" << nuevoNombre << "\"." << endl;
}



NodoCategoria* ListaCategorias::buscarCategoria(string nombreCategoria) {
    NodoCategoria* temp = head;

    while (temp != nullptr) {
        if(temp->getCategoria()->getNombre() == nombreCategoria) {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return temp;
}
NodoCategoria* ListaCategorias::buscarNodoAnterior(string nombreCategoria) {
    if(head == nullptr) {
        return nullptr;
    }
    NodoCategoria* temp = head;

    while (temp->getSiguiente() != nullptr) {
        if(temp->getSiguiente()->getCategoria()->getNombre() == nombreCategoria) {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return nullptr;
}


void ListaCategorias::eliminarCategoria(string nombreCategoria) {
    if(head == nullptr){
        cout << "La lista esta vacia" << endl;
        return;
    }
    if (head->getCategoria()->getNombre() == nombreCategoria){
        NodoCategoria* temp = head;
        head = head->getSiguiente();
        delete temp;
        cout << "La categoria " << nombreCategoria << " se ha eliminado" << endl;
        return;
    }
    NodoCategoria* temp = buscarNodoAnterior(nombreCategoria);
    if (temp != nullptr) {
        NodoCategoria* nodoObjetivo = temp->getSiguiente();
        temp->setSiguiente(nodoObjetivo->getSiguiente());
        delete nodoObjetivo;
        cout << "La categoria " << nombreCategoria << " se ha eliminado" << endl;

    } else {
        cout << "No se encontro la categoria " << nombreCategoria << endl;
    }

}

void ListaCategorias::display() {
    if (head == nullptr) {
        cout << "La lista esta vacia.\n";
        return;
    }

    NodoCategoria* temp = head;
    int contador = 1;
    while (temp != nullptr) {
        cout  << contador << ". " << "Categoria: " << temp->getCategoria()->getNombre() << "\n";
        cout << "   Descripcion: " << temp->getCategoria()->getDescripcion() << "\n";
        temp = temp->getSiguiente();
        contador++;
    }
}

bool ListaCategorias::hayRepetidos(const std::string& nombreCategoria) {
    NodoCategoria* temp = head;
    while (temp != nullptr) {
        if (temp->getCategoria()->getNombre() == nombreCategoria) {
            return true;
        }
        temp = temp->getSiguiente();
    }
    return false;
}


