#ifndef SOMA_H_INCLUDED
#define SOMA_H_INCLUDED
#include <string>

using namespace std;

class Soma
{
    private:
        string valorUm;
        string valorDois;
        int base;
    public:
        Soma(string, string, int);
        string calcular();

};

#endif // SOMA_H_INCLUDED
