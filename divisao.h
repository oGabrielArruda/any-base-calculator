#ifndef DIVISAO_H_INCLUDED
#define DIVISAO_H_INCLUDED
#include <string>

using namespace std;

class Divisao {
    private:
        string dividendo;
        string divisor;
        string quociente;
        string arco;
        int base;
        bool parteFracionaria;

        void adaptarExpressoes();
        void dividirExpressao();
        string gerarArco();
    public:
        Divisao(string, string , int);
        string calcular();
};

#endif // DIVISAO_H_INCLUDED
