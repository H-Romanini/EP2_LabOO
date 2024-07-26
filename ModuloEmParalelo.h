#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include "Somador.h"

class ModuloEmParalelo : public Modulo {
public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    virtual Sinal* processar(Sinal* sinal);
private:
    Somador *somador;
};

#endif // MODULOEMPARALELO_H
