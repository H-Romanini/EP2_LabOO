#ifndef SOMADOR_H
#define SOMADOR_H

#include "CircuitoMISO.h"

class Somador : public CircuitoMISO {
public: 
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* SinalIn1, Sinal* SinalIn2);
private:
    Sinal* SinalIn1;
    Sinal* SinalIn2;
};

#endif // SOMADOR_H