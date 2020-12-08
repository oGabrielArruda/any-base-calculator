#include <iostream>
#include <string>
#include <stdlib.h>
#include "soma.h"
#include "utils.h"

using namespace std;

Soma::Soma(string nmrUm, string nmrDois, int base)
{
    Utils u;
    string* valores = u.AdaptarValores(nmrUm, nmrDois);
    this -> valorUm = valores[0];
    this -> valorDois = valores[1];
    this -> base = base;
}
string Soma::calcular()
{
    cout << this -> valorUm << "\n";
    cout << this -> valorDois << "\n";

    cout << "Entrou!";
}
