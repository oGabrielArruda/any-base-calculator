#ifndef DIVISAO_H_INCLUDED
#define DIVISAO_H_INCLUDED
#include <string>
#include <queue>

using namespace std;

class Divisao {
    private:
        string dividendo;
        string divisor;
        string quociente;
        string arco;
        queue<char> escorrega;

        int base;
        bool parteFracionaria;
        int qtdDepoisDaVirgula;

        void dividirExpressao();
        void prepararArco(bool);
        void prepararArcoPrimeiraVez();
        void aumentarArco();
        void incrementarQuociente();
    public:
        Divisao(string, string , int);
        string calcular();
};


#endif // DIVISAO_H_INCLUDED
