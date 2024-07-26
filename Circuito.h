#ifndef CIRCUTO_H
#define CIRCUTO_H

#include "Sinal.h"

class Circuito {
protected:
    static int id;
    int idProprio;
public:
    Circuito();
    virtual ~Circuito();
    int getID();
    virtual void imprimir();
    static int getUltimoID();
};

#endif // CIRCUTO_H