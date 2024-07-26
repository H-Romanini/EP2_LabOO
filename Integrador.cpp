#include "Integrador.h"

Integrador::Integrador() {
}

Integrador::~Integrador() {
}

Sinal* Integrador::processar(Sinal *sinalIN){
    double *sequenciaIntegrada = sinalIN->getSequencia();
    // Fazendo a integral
    double acumulador = 0;
    for (int i = 0; i < sinalIN->getComprimento(); i++) {
        acumulador = acumulador + sinalIN->getSequencia()[i];
        sequenciaIntegrada[i] = acumulador;
    }

    Sinal *sinalIntegrado = new Sinal(sequenciaIntegrada, sinalIN->getComprimento());

    
    return sinalIntegrado;
}

// Funcao pronta
