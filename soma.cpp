#include <iostream>
#include <string>
#include <stdlib.h>
#include "soma.h"
#include "utils.h"
#include "somadoradedigito.h"

using namespace std;

Soma::Soma(string nmrUm, string nmrDois, int base)
{
    string* valores = Utils::AdaptarValores(nmrUm, nmrDois);
    this -> valorUm = valores[0];
    this -> valorDois = valores[1];
    this -> base = base;
}
string Soma::calcular()
{
    SomadoraDeDigito s;
    int len = this -> valorUm.length();
    char carga = '0';
    string result = "";

    for(int i = len - 1; i >= 0; i--)
    {
        char c1 = this -> valorUm.at(i);
        char c2 = this -> valorDois.at(i);

        if(c1 == ',' || c1 == '.')
            result = ',' + result;
        else
        {
            s.Somar(c1, c2, carga, this->base);
            carga = s.getResto();
            result = s.getSoma() + result;
        }
    }

    return result;
}
