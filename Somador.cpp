#include "Somador.h"

Somador::Somador() {
}

Somador::~Somador() {
}

Sinal* Somador::processar(Sinal* sinalIn1, Sinal* sinalIn2){
    this->SinalIn1 = sinalIn1;
    this->SinalIn2 = sinalIn2;

    int tamanhoSequencia = 0;
    double *sequenciaSomada = new double[sinalIn1->getComprimento()];

    if (sinalIn1->getComprimento() > sinalIn2->getComprimento()){
        tamanhoSequencia = sinalIn2->getComprimento();
        sequenciaSomada = sinalIn2->getSequencia();
    } else {
        tamanhoSequencia = sinalIn1->getComprimento();
        sequenciaSomada = sinalIn1->getSequencia();
    }

    for(int i = 0; i < tamanhoSequencia; i++){
        sequenciaSomada[i] = sinalIn1->getSequencia()[i] + sinalIn2->getSequencia()[i];
    }
    Sinal *sinalOut = new Sinal(sequenciaSomada, tamanhoSequencia);
    
    return sinalOut;
}

