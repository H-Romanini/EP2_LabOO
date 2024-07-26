#include "Sinal.h"
#include "Grafico.h"


Sinal::Sinal(double *sequencia, int comprimento): sequencia(sequencia), comprimento(comprimento) {
    if(comprimento <= 0){
        throw new invalid_argument("O comprimento deve ser maior que zero.");
    }
}

Sinal::Sinal(double constante, int comprimento): constante(constante), comprimento(comprimento) {
    double *sequenciaCte = new double[comprimento];
    for (int i = 0; i < comprimento; i++) {
        sequenciaCte[i] = constante;
    }
    this->sequencia = sequenciaCte;
}

Sinal::~Sinal() {}

double* Sinal::getSequencia() {
    return sequencia;
}

int Sinal::getComprimento() {
    return comprimento;
}

void Sinal::imprimir(string nome) {
    Grafico *grafico = new Grafico(nome, this->sequencia, this->comprimento);
    grafico->plot();
}

void Sinal::imprimir() {
    for (int i = 0; i < comprimento; i++) {
        cout << i << "- " << sequencia[i] << endl;
    }
}

void Sinal::imprimir(int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << i << "- " << sequencia[i] << endl;
    }
}




