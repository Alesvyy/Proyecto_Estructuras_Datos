#include "Cola.h"
#include <string>
#include <random>
#include <iostream>
using namespace std;

Cola::Cola() : frente(0), final(-1), longitud(0) {}

bool Cola::esVaciaCola() const {
    return longitud == 0;
}

Cola Cola::insertarElem() {
    if (longitud < MAX_SIZE) {
        final = (final + 1) % MAX_SIZE;  // Movimiento circular del final
        datos[final] = generarAlphanumericoRandom();         // Inserta el nuevo elemento
        longitud++;                      // Incrementa la longitud
    }
    return *this;
}

Cola Cola::atenderCliente(string &elemento) {
    if (!esVaciaCola()) {
        elemento = datos[frente];        // Toma el elemento del frente
        frente = (frente) % MAX_SIZE; // Movimiento circular del frente
        std::cout << "Elemento atendido: " << elemento << "\n";
        eliminarElem(0);                      // Decrementa la longitud
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

string Cola::ultimoElem() const {
    if (!esVaciaCola()) { // Verifica si la cola no está vacía
        return datos[(final + MAX_SIZE) % MAX_SIZE]; // Retorna el último elemento
    } else {
        return "No hay elementos en la cola"; // Mensaje si la cola está vacía
    }
}

int Cola::getLongitud() const {
    return longitud; // Retorna la cantidad de elementos
}

void Cola::destruirCola() {
    frente = 0;
    final = -1;
    longitud = 0; // Resetea la cola
}

int Cola::buscarTurno(const string& turno) const {
    for (int i = 0; i < longitud; i++) {
        int idx = (frente + i) % MAX_SIZE;
        if (datos[idx] == turno) {
            return idx;  // Retorna el índice si encuentra el turno
        }
    }
    return -1;  // Si no se encuentra, retorna -1
}

string Cola::generarAlphanumericoRandom() {
    const string caracteres = "ABCDEFGHIJKLMNOPQERTUVWXYZ";
    const string caracteresNumericos = "0123456789";

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<> distribution(0, caracteres.size()-1);

    string caracterRandom;

    caracterRandom = caracteres[distribution(generator)];
    uniform_int_distribution<> numeric_distribution(0,caracteresNumericos.size()-1);
    for(int i = 0; i < 3; i++) {
        caracterRandom += caracteresNumericos[numeric_distribution(generator)];
    }



    return caracterRandom;

}
void Cola::listarCola() {
    for (int i = 0; i < longitud; i++) {
        std::cout << datos[i]+"\n";
    }
}

