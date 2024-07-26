#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "CircuitoSISO.h"

class Integrador : public CircuitoSISO {
public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* SinalIN);
};

#endif // INTEGRADOR_H