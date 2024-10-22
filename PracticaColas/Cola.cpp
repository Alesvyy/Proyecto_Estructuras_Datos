#include "Cola.h"

Cola::Cola() : frente(0), final(-1), longitud(0) {}

bool Cola::esVaciaCola() const {
    return longitud == 0;
}

Cola Cola::insertarElem(int elemento) {
    if (longitud < MAX_SIZE) {
        final = (final + 1) % MAX_SIZE;  // Movimiento circular del final
        datos[final] = elemento;         // Inserta el nuevo elemento
        longitud++;                      // Incrementa la longitud
    }
    return *this;
}

Cola Cola::atender(int &elemento) {
    if (!esVaciaCola()) {
        elemento = datos[frente];        // Toma el elemento del frente
        frente = (frente + 1) % MAX_SIZE; // Movimiento circular del frente
        longitud--;                      // Decrementa la longitud
    }
    return *this;
}

Cola Cola::eliminarElem(int posicion) {
    if (posicion >= 0 && posicion < longitud) {
        for (int i = posicion; i != final; i = (i + 1) % MAX_SIZE) {
            datos[i] = datos[(i + 1) % MAX_SIZE]; // Mueve los elementos hacia adelante
        }
        final = (final - 1 + MAX_SIZE) % MAX_SIZE; // Ajusta el final
        longitud--;                                // Decrementa la longitud
    }
    return *this;
}

int Cola::ultimoElem() const {
    if (!esVaciaCola()) {
        return datos[final]; // Retorna el último elemento
    }
    return -1; // Indica que la cola está vacía
}

int Cola::getLongitud() const {
    return longitud; // Retorna la cantidad de elementos
}

void Cola::destruirCola() {
    frente = 0;
    final = -1;
    longitud = 0; // Resetea la cola
}
