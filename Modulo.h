#ifndef MODULO_H
#define MODULO_H

#include "CircuitoSISO.h"
#include <list>

class Modulo : public CircuitoSISO {
public:
    Modulo();
    virtual ~Modulo();
    virtual void adicionar(CircuitoSISO* circ);
    virtual list <CircuitoSISO*>* getCircuitos();
    void imprimir();
private:
    list <CircuitoSISO*>* circuitos = new list<CircuitoSISO*>();
};

#endif // MODULO_H