#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H


#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include "Derivador.h"
#include <iostream>
#include <fstream>

using namespace std;

class PersistenciaDeModulo {
public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
private:
    string nomeDoArquivo;
    string verificaTipo(CircuitoSISO* circuito);
    void salvarRecursivo(Modulo* mod);
    CircuitoSISO* lerRecursivo(ifstream& input, string tipo);
    ofstream output;
};

#endif /* PERSISTENCIADEMODULO_H */

