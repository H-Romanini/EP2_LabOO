#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "CircuitoSISO.h"

class Amplificador : public CircuitoSISO {
    public:
        Amplificador(double ganho);
        virtual ~Amplificador();
        Sinal* processar(Sinal* sinalIN);
        void setGanho(double ganho);
        double getGanho();
    private:
        double ganho;
        
};

#endif