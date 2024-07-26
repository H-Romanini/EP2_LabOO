#include "Derivador.h"

Derivador::Derivador() {
}

Derivador::~Derivador() {
}

Sinal* Derivador::processar(Sinal* sinalIN) {

    double *sequenciaDerivada = new double[sinalIN->getComprimento()];
    sequenciaDerivada[0] = sinalIN->getSequencia()[0];

    for (int i = 0; i < (sinalIN->getComprimento() - 1); i++) {
        sequenciaDerivada[i + 1] = sinalIN->getSequencia()[i + 1] - sinalIN->getSequencia()[i];
    }

    Sinal *sinalDerivado = new Sinal(sequenciaDerivada, sinalIN->getComprimento());
    
    return sinalDerivado;

}
