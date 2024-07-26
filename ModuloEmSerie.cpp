#include "ModuloEmSerie.h"

ModuloEmSerie::ModuloEmSerie() {
}

ModuloEmSerie::~ModuloEmSerie() {

}

Sinal* ModuloEmSerie::processar(Sinal* sinal) {
    for (list<CircuitoSISO*>::iterator it = getCircuitos()->begin(); it != getCircuitos()->end(); it++) {
        CircuitoSISO* verificaCirc = dynamic_cast<CircuitoSISO*>(*it);
        if(verificaCirc == NULL){
            throw new logic_error("Circuito nao e SISO");
            return NULL;
        }
        Sinal *sinalAux = (*it)->processar(sinal);
        sinal = sinalAux;
    }
    return sinal;
}


