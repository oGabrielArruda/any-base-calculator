#ifndef SOMA_H_INCLUDED
#define SOMA_H_INCLUDED

using namespace std;

class Soma
{
    private:
        string valorUm;
        string valorDois;
        int base;
        void adaptarValores(string, string);
    public:
        Soma(string, string, int);
        string calcular();

};

#endif // SOMA_H_INCLUDED
