#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Sinal.h"
#include "Circuito.h"

class CircuitoSISO : public Circuito {
public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    virtual Sinal* processar(Sinal* SinalIN);
private:
    Sinal *SinalIN;
};

#endif // CIRCUITOSISO_H