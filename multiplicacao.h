#ifndef MULTIPLICACAO_H_INCLUDED
#define MULTIPLICACAO_H_INCLUDED
#include <string>

using namespace std;
class Multiplicacao {
    private:
        string valorUm;
        string valorDois;
        int base;
    public:
        Multiplicacao(string, string, int);
        string calcular();

};

#endif // MULTIPLICACAO_H_INCLUDED
