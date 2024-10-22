#ifndef COLA_H
#define COLA_H

class Cola {
private:
    static const int MAX_SIZE = 100;  // Tamaño máximo de la cola
    int datos[MAX_SIZE];              // Arreglo para almacenar los elementos
    int frente;                       // Índice del frente de la cola
    int final;                        // Índice del final de la cola
    int longitud;                     // Cantidad de elementos en la cola

public:
    Cola();                          // Constructora: Construye una cola vacía
    bool esVaciaCola() const;         // Analizadora: Retorna si la cola está vacía
    Cola insertarElem(int elemento);  // Modificadora: Inserta un nuevo elemento
    Cola atender(int &elemento);      // Modificadora: Extrae el primer elemento de la cola
    Cola eliminarElem(int posicion);  // Modificadora: Elimina un elemento por su posición
    int ultimoElem() const;           // Analizadora: Retorna el último elemento de la cola
    int getLongitud() const;          // Analizadora: Retorna la cantidad de elementos
    void destruirCola();              // Destructora: Elimina todos los elementos de la cola
};

#endif
