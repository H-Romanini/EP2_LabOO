#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Sinal.h"
#include "Somador.h"
#include "Integrador.h"
#include "Modulo.h"
#include "Amplificador.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "Derivador.h"


class ModuloRealimentado : public Modulo {
public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    void adicionar(CircuitoSISO* circ);
    Sinal* processar(Sinal* sinal);
    list <CircuitoSISO*>* getCircuitos();
private:
    ModuloEmSerie *moduloInterno = new ModuloEmSerie();
};

#endif /* "MODULOREALIMENTADO_H" */

    