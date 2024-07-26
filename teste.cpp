#include "Sinal.h"
#include "Circuito.h"
#include "CircuitoSISO.h"
#include "CircuitoMISO.h"
#include "Somador.h"
#include "Modulo.h"
#include "PersistenciaDeModulo.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void TesteSinal();
void TesteCircuito();
void TesteSomador();
void TesteModulo();

void TesteSinal() {
    double sequencia[5] = { 1,2,3,4,5 };
    int comprimento = 5;

    Sinal* sinal = new Sinal(sequencia, comprimento);
    sinal->imprimir();
    delete sinal;
}

void TesteCircuito() {
    Circuito* c1 = new Circuito();
    Circuito* c2 = new Circuito();
    Circuito* c3 = new Circuito();
    c1->imprimir();
    c2->imprimir();
    c3->imprimir();

    cout << c3->getUltimoID() << endl;
}

void TesteSomador() {
    double seq[4] = { 1,2,3,5 };
    int comprimento = 4;
    Somador* s1 = new Somador();
    Sinal* sinal = new Sinal(seq, comprimento);
    Sinal* saida = s1->processar(sinal, sinal);
    saida->imprimir();
}

void TesteModulo() {
    CircuitoSISO* c1 = new CircuitoSISO();
    CircuitoSISO* c2 = new CircuitoSISO();
    CircuitoSISO* c3 = new CircuitoSISO();
    ModuloEmSerie* m = new ModuloEmSerie();

    m->adicionar(c2);
    m->adicionar(c1);
    m->adicionar(c3);
    m->imprimir();
    list<CircuitoSISO*>* l = m->getCircuitos();
}

void TesteArquivo() {
    PersistenciaDeModulo* p1 = new PersistenciaDeModulo("entrada.txt");
    PersistenciaDeModulo* p2 = new PersistenciaDeModulo("saida.txt");

    Modulo* m1 = p1->lerDeArquivo();
    p2->salvarEmArquivo(m1);
}