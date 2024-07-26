#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H

#include "Sinal.h"
#include "Circuito.h"

class CircuitoMISO : public Circuito {
protected:
    Sinal *SinalIN1;
    Sinal *SinalIN2;
public:
    CircuitoMISO();
    virtual ~CircuitoMISO();
    virtual Sinal* processar(Sinal* SinalIN1, Sinal* SinalIN2);
};


#endif // "CIRCUITOMISO_H"