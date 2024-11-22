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
void ListaProductos::agregarProducto(Producto *producto) {
 if (!hayRepetidos(producto->getNombre())) {
 NodoProducto* nodoProductoNuevo = new NodoProducto(producto);
 if (head == nullptr) {
 setHead(nodoProductoNuevo);
 } else {
 NodoProducto* temp = head;
 while (temp->getSiguiente() != nullptr) {
 temp = temp->getSiguiente();
 }
 temp->setSiguiente(nodoProductoNuevo);
 }
 cout << "Se ha agregado el producto " << producto->getNombre() << endl;
 } else {
 cout << "Ya existe este producto" << endl;
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
 cout << "La lista esta vacia.\n";
 return;
 }
 NodoProducto* temp = head;
 while (temp != nullptr) {
 cout << temp->getProducto()->getNombre() << " -> ";
 temp = temp->getSiguiente();
 }
 cout << "nullptr\n";
}
bool ListaProductos::hayRepetidos(string nombreProducto) {
 bool repetido = false;
 NodoProducto* temp = head;
 while (temp != nullptr && !repetido) {
 if (temp->getProducto()->getNombre() == nombreProducto) {
 repetido = true;
 }
 temp = temp->getSiguiente();
 }
 return repetido;
}