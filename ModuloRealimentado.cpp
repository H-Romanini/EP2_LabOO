#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado(){
   this->moduloInterno = new ModuloEmSerie();
}

ModuloRealimentado::~ModuloRealimentado() {
    delete moduloInterno;
}

Sinal* ModuloRealimentado::processar(Sinal* sinal){
    //Criando a constante vInicial, somador e a sequencia invertida:
    double vInicial = 0;
    double *sequenciaInvertida = new double [sinal->getComprimento()];
    sequenciaInvertida[0] = vInicial;
    Somador* somador = new Somador();

    Sinal* diferenca = new Sinal(sinal->getSequencia()[0], 1);
    Sinal* saidaFinal = moduloInterno->processar(diferenca);
    delete diferenca;

    //Criando a sequencia invertida:
    for (int i = 1; i < sinal->getComprimento(); i++) {
        sequenciaInvertida[i] = sinal->getSequencia()[i-1] * -1;
        Sinal* saidaInvertida = new Sinal(sequenciaInvertida, i + 1);
        diferenca = somador->processar(sinal, saidaInvertida);
        delete saidaFinal;
        saidaFinal = moduloInterno->processar(diferenca);
        delete diferenca;
        delete saidaInvertida;
    }
    delete sequenciaInvertida;
    return saidaFinal;
}

void ModuloRealimentado::adicionar(CircuitoSISO* circ) {
    this->moduloInterno->adicionar(circ);
    return;
}

list <CircuitoSISO*>* ModuloRealimentado::getCircuitos() {
    return this->moduloInterno->getCircuitos();
}