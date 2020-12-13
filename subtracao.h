#ifndef SUBTRACAO_H_INCLUDED
#define SUBTRACAO_H_INCLUDED

#include <string>
#include <stack>
#include <subtradoradedigito.h>

using namespace std;

class Subtracao
{
    private:
        string valorUm;
        string valorDois;
        stack<SubtradoraDeDigito> pilhaExpressao;
        int base;

        SubtradoraDeDigito pegarTopo();
        SubtradoraDeDigito emprestar(SubtradoraDeDigito);

    public:
        Subtracao(string, string, int);
        stack<SubtradoraDeDigito> getPilhaExpressao(string, string);
        string calcular();

};

#endif // SUBTRACAO_H_INCLUDED
