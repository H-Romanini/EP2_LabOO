#include "Circuito.h"

int Circuito::id = 1;

Circuito::Circuito() {
    idProprio = id;
    id = id + 1;
}

Circuito::~Circuito() {}

int Circuito::getID() {
    return idProprio;
}

void Circuito::imprimir() {
    cout << "Circuito com ID " << idProprio << endl;
}

int Circuito::getUltimoID() {
    return id - 1;
}