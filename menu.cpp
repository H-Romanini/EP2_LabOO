#include <cmath>
#include <iostream>
#include <string>

#include "Amplificador.h"
#include "Circuito.h"
#include "CircuitoMISO.h"
#include "CircuitoSISO.h"
#include "Derivador.h"
#include "Integrador.h"
#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"
#include "PersistenciaDeModulo.h"

using namespace std;


Sinal* novoSinal() {
    int escolhaSinal = 0;
    double* sequencia = new double[60]; 
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?\n1) 5+3*cos(n*pi/8)\n2) constante\n3) rampa \nEscolha: ";
    cin >> escolhaSinal;

    if (escolhaSinal == 1) {
        int i = 0;
        while(i < 60) {
            sequencia[i] = 5+3*cos(i*M_PI/8);
            i++;
        }
    } else if (escolhaSinal == 2) {
        double constante;
        cout << endl;
        cout << "Qual o valor dessa constante?" << endl << "C = ";
        cin >> constante;
        cout << endl;
        for (int i = 0; i < 60 ; i++) {
            sequencia[i] = constante;
        }
    } else if (escolhaSinal == 3) {
        double inclinacao;
        cout << endl;
        cout << "Qual a inclinacao dessa rampa?" << endl << "a = ";
        cin >> inclinacao;
        cout << endl;
        for (int i = 0; i < 60 ; i++) {
            sequencia[i] = i*inclinacao;
        }
    }
    Sinal* novoSinal = new Sinal(sequencia,60);

    return novoSinal;
};

CircuitoSISO* novaOperacao() {
    CircuitoSISO* operacao;
    int escolhaOperacao;
    cout << "Qual operacao voce gostaria de fazer?\n1) Amplificar\n2) Derivar\n3) Integrar\nEscolha: ";
    cin >> escolhaOperacao;
    cout << endl;
    if (escolhaOperacao == 1) {
        double ganho;
        cout << "Qual o ganho dessa amplificacao?\ng = ";
        cin >> ganho;
        cout << endl;
        operacao = new Amplificador(ganho);
    } else if (escolhaOperacao == 2) {
        operacao = new Derivador();
    } else if (escolhaOperacao == 3) {
        operacao = new Integrador();
    }
    return operacao;
}

void menu() {
    int escolhaSimulacao;
    cout << "Simulink em C++\nQual simulacao voce gostaria de fazer?\n1) Circuito advindo de arquivo\n2) Sua propria sequencia de operacoes\nEscolha: ";
    cin >> escolhaSimulacao;
    cout << endl;

    Modulo* modFinal;
    Sinal* sinalOUT;

    Sinal* sinalIN = novoSinal();

    if (escolhaSimulacao == 1) {
        string nomeDoArquivo;
        cout << "Qual o nome do arquivo a ser lido?\nNome: ";
        cin >> nomeDoArquivo;
        cout << endl;

        PersistenciaDeModulo* arquivo = new PersistenciaDeModulo(nomeDoArquivo);
        modFinal = arquivo->lerDeArquivo();
        sinalOUT = modFinal->processar(sinalIN);
        sinalOUT->imprimir("Resultado final");

    } else if (escolhaSimulacao == 2) {
        int escolhaOperacaoBase;
        cout << "Qual estrutura de operacoes voce deseja ter como base?\n1) Operacoes em serie nao realimentadas\n2) Operacoes em paralelo nao realimentadas\n3) Operacoes em serie realimentadas\nEscolha: ";
        cin >> escolhaOperacaoBase;
        cout << endl;
        
        if (escolhaOperacaoBase == 1) {
            modFinal = new ModuloEmSerie();
        } else if (escolhaOperacaoBase == 2) {
            modFinal = new ModuloEmParalelo();
        } else if (escolhaOperacaoBase == 3) {
            modFinal = new ModuloRealimentado();
        }
        
        modFinal->adicionar(novaOperacao());

        int escollhaContinuar = 1;
        while (escollhaContinuar == 1) {
            cout << "O que voce quer fazer agora?\n1) Inserir mais uma operacao\n2) Imprimir o resultado\nEscolha: ";
            cin >> escollhaContinuar;
            cout << endl;

            if (escollhaContinuar == 1) {
                modFinal->adicionar(novaOperacao());
            } 
        }

        sinalOUT = modFinal->processar(sinalIN);
        sinalOUT->imprimir("Resultado final");
    }

    int salvar;
    cout << "Voce gostaria de salvar o circuito em um novo arquivo?\n1) Sim\n2) Nao\nEscolha: ";
    cin >> salvar;
    cout << endl;

    if (salvar == 1) {
        string nomeDoArquivoSalvo;
        cout << "Qual o nome do arquivo a ser escrito?\nNome: ";
        cin >> nomeDoArquivoSalvo;
        cout << endl;

        PersistenciaDeModulo* arquivoSalvo = new PersistenciaDeModulo(nomeDoArquivoSalvo);
        arquivoSalvo->salvarEmArquivo(modFinal);
        return;
    }
}