#ifndef LISTACATEGORIAS_H
#define LISTACATEGORIAS_H
#include "../../Models/Categoria.h"
#include "NodoCategoria.h"


class ListaCategorias {
public:
    ListaCategorias();
    ~ListaCategorias();

    void agregarCategoria(Categoria* categoria);
    NodoCategoria* buscarCategoria(string nombreCategoria);
    NodoCategoria* buscarNodoAnterior(string nombreCategoria);
    void eliminarCategoria(string nombreCategoria);
    NodoCategoria* getHead();
    void display();
    void modificarCategoria(const std::string& nombreActual, const std::string& nuevoNombre);
    void modificarCategoriaPorNumero(int numeroCategoria, const std::string& nuevoNombre);
    int contarCategorias() const;
    NodoCategoria* obtenerNodoPorNumero(int numero);

private:
    NodoCategoria* head;
    bool hayRepetidos(const std::string& nombreCategoria);
    void setHead(NodoCategoria* nuevoHead);
};

#endif //LISTACATEGORIAS_H