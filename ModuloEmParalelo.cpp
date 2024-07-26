#include "ModuloEmParalelo.h"

ModuloEmParalelo::ModuloEmParalelo(){
}

ModuloEmParalelo::~ModuloEmParalelo() {
}

Sinal* ModuloEmParalelo::processar(Sinal* sinal) {
    Somador* somador = new Somador();
    list<CircuitoSISO*>::iterator it = this->getCircuitos()->begin();
    if ((*it) == nullptr){
        throw new logic_error("Nao é SISO");
    }
    Sinal* sinalOut = (*it)->processar(sinal);
    it++;
    
    while (it != this->getCircuitos()->end()) {
        sinalOut = somador->processar(sinal, (*it)->processar(sinal));
        it++;
    }

    return sinalOut;
}
