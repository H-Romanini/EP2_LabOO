#ifndef MODULOEMSERIE_H
#define MODULOEMSERIE_H

#include "Modulo.h"

class ModuloEmSerie : public Modulo {
public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    virtual Sinal* processar(Sinal* sinal);
};

#endif // MODULOEMSERIE_H