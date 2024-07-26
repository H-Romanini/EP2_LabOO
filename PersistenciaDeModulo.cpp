#include "PersistenciaDeModulo.h"

using namespace std;

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo): nomeDoArquivo(nomeDoArquivo){
}

PersistenciaDeModulo::~PersistenciaDeModulo() {}

string PersistenciaDeModulo::verificaTipo(CircuitoSISO* circ) {
    ModuloEmSerie* verificaSerie = dynamic_cast<ModuloEmSerie*>(circ);
    ModuloEmParalelo* verificaParalelo = dynamic_cast<ModuloEmParalelo*>(circ);
    ModuloRealimentado* verificaRealimentado = dynamic_cast<ModuloRealimentado*>(circ);
    Amplificador* verificaAmplificador = dynamic_cast<Amplificador*>(circ);
    Derivador* verificaDerivador = dynamic_cast<Derivador*>(circ);
    Integrador* verificaIntegrador = dynamic_cast<Integrador*>(circ);

    if (verificaSerie != NULL) {
        return "S";
    } else if (verificaParalelo != NULL) {
        return "P";
    } else if (verificaRealimentado != NULL) {
        return "R";
    } else if (verificaAmplificador != NULL) {
        return "A";
    } else if (verificaDerivador != NULL) {
        return "D";
    } else if (verificaIntegrador != NULL) {
        return "I";
    }
    return nullptr;
}

void PersistenciaDeModulo::salvarRecursivo(Modulo* mod) {
    if (verificaTipo(mod) == "S") {
        output << "S" << endl;

    } else if (verificaTipo(mod) == "P") {
        output << "P" << endl;

    } else if (verificaTipo(mod) == "R") {
        output << "R" << endl;
    }
    
    for (list<CircuitoSISO*>::iterator it = mod->getCircuitos()->begin(); it != mod->getCircuitos()->end(); it++) {
        if (dynamic_cast<Modulo*>(*it) != NULL) {
            salvarRecursivo(static_cast<Modulo*>(*it));  
        } if (dynamic_cast<Amplificador*>(*it) != NULL) {
            output << "A " << dynamic_cast<Amplificador*>(*it)->getGanho() << endl;
        } if (dynamic_cast<Derivador*>(*it) != NULL) {
            output << "D" << endl;
        } if (dynamic_cast<Integrador*>(*it) != NULL) {
            output << "I" << endl;
        }
    }
    output << "f" << endl;
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod) {
    this->output.open(nomeDoArquivo, ios::out);
    salvarRecursivo(mod);
    output.close();
    return;
}

CircuitoSISO* PersistenciaDeModulo::lerRecursivo(ifstream& input, string tipo) {
    Modulo* moduloSaida;
    if (tipo == "S") {
        moduloSaida = new ModuloEmSerie();
    } else if (tipo == "P") {
        moduloSaida = new ModuloEmParalelo();
    } else if (tipo == "R") {
        moduloSaida = new ModuloRealimentado();
    } 
    
    if(tipo == "A") {
        double ganho;
        input >> ganho;
        return new Amplificador(ganho);
    }
    else if(tipo == "D") {
        return new Derivador();
    }
    else if(tipo == "I") {
        return new Integrador();
    }
    else if(tipo == "f") {
        return NULL;
    }
    while (input) {
        input >> tipo;
        auto* circuitoAdicionado = lerRecursivo(input, tipo);

        if (circuitoAdicionado != NULL) {
            moduloSaida->adicionar(circuitoAdicionado);
        }
    }
    return moduloSaida;
}

Modulo* PersistenciaDeModulo::lerDeArquivo() {
    ifstream input;
    input.open(nomeDoArquivo);
    Modulo* mod;
    string tipo;
    input >> tipo;

    if (input.fail()) {
        throw new invalid_argument("erro ao abrir o arquivo");
        input.close();
        return nullptr;
    }
    
    if (tipo == "S") {
        mod = new ModuloEmSerie();
    } 
    else if (tipo == "P") {
        mod = new ModuloEmParalelo();
    }
    else if (tipo == "R") {
        mod = new ModuloRealimentado();
    } 
    else {
        throw new logic_error("erro de formatacao");
    }

    while (input) {
        input >> tipo;
        CircuitoSISO* circuitoAdicionado = lerRecursivo(input, tipo);
        if (circuitoAdicionado != NULL) {
            mod->adicionar(circuitoAdicionado);
        }
    }

    if (!input.eof()) {
    throw new invalid_argument("Mensagem de erro");
    input.close();
    }
    input.close();
    return mod;
}