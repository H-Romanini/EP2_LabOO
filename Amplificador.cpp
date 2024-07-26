#include "Sinal.h"
#include "Amplificador.h"

Amplificador::Amplificador(double ganho) {
    this->ganho = ganho;
}

Amplificador::~Amplificador() {
}

Sinal* Amplificador::processar(Sinal* sinalIN){
    double *sequenciaAmplificada = new double[sinalIN->getComprimento()];
    double *sequenciaAux = sinalIN->getSequencia(); 
    for(int i = 0; i < sinalIN->getComprimento(); i++){
        sequenciaAmplificada[i] = sequenciaAux[i] * this->ganho;
    }
    Sinal *SinalOut = new Sinal(sequenciaAmplificada, sinalIN->getComprimento());
    return SinalOut;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

double Amplificador::getGanho(){
    return this->ganho;
}

// Funcao Pronta