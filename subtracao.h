#ifndef SUBTRACAO_H_INCLUDED
#define SUBTRACAO_H_INCLUDED

#include <string>
using namespace std;

class Subtracao
{
    private:
        string valorUm;
        string valorDois;
        int base;
    public:
        Subtracao(string, string, int);
        string calcular();

};

#endif // SUBTRACAO_H_INCLUDED
