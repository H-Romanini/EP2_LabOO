#ifndef SINAL_H
#define SINAL_H

#include <iostream>

using namespace std;

class Sinal {
private:
    int comprimento;
    double *sequencia;
    double constante;

public:
    Sinal(double *sequencia, int comprimento);
    Sinal(double constante, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
    void imprimir();
    void imprimir(int tamanho);
};

#endif // SINAL_H