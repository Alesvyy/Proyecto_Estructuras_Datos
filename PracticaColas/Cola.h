#ifndef COLA_H
#define COLA_H
#include <string>
using namespace std;

class Cola {
private:
    static const int MAX_SIZE = 100;
    string datos[MAX_SIZE];
    int frente;
    int final;
    int longitud;

    string generarAlphanumericoRandom();

public:
    std::string ultimo() const;
    Cola();
    bool esVaciaCola() const;
    Cola insertarElem();
    Cola atenderCliente(string &elemento);
    Cola eliminarElem(int posicion);
    string ultimoElem() const;
    int getLongitud() const;
    void destruirCola();
    void listarCola();

    int buscarTurno(const string& turno) const;
};

#endif // COLA_H
