#ifndef DERIVADOR_H
#define DERIVADOR_H

#include "CircuitoSISO.h"

class Derivador : public CircuitoSISO {
public: 
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* SinalIN);
};

#endif // DERIVADOR.H