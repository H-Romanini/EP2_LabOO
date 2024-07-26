#include "Modulo.h"

Modulo::Modulo() {
}

Modulo::~Modulo() {
    delete this->circuitos;
}

void Modulo::adicionar(CircuitoSISO* circ) {
    circuitos->push_back(circ);
    return;
}

list <CircuitoSISO*>* Modulo::getCircuitos() {
    return this->circuitos;
}

void Modulo::imprimir() {
    cout << "Modulo com ID " << this->getID() << " e" << endl;
    for (list<CircuitoSISO*>::iterator it = circuitos->begin(); it != circuitos->end(); it++) {
        (*it)->imprimir();
    }
    return;
}