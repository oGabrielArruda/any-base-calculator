#include "subtradoradedigito.h"
#include "somadoradedigito.h"
#include "caracteres.h"
#include <iostream>

Caracteres caracteres;

SubtradoraDeDigito::SubtradoraDeDigito(char valorUm, char valorDois, int base)
{
    this -> valorUm = valorUm;
    this -> valorDois = valorDois;
    this -> base = base;
}

bool SubtradoraDeDigito::Subtrair()
{
    int a = this -> valorUm;
    int b = this -> valorDois;
    int subtracao = caracteres.getValor(a) - caracteres.getValor(b);
    std::cout << "Valor um: ";
    std::cout << caracteres.getValor(a) << "\n";
    std::cout << "Valor dois: ";
    std::cout << caracteres.getValor(b) << "\n";
    std::cout << "Resultado:";
    std::cout << subtracao << "\n\n";
    if(subtracao < 0) return false;

    this -> valorDaSubtracao = caracteres.getChar(subtracao);
    return true;
}

char SubtradoraDeDigito::getSubtraido() {
    return this -> valorDaSubtracao;
}

void SubtradoraDeDigito::receberBase()
{
    int valor = caracteres.getValor(this -> valorUm);
    char novoValor = caracteres.getChar(valor + this -> base);
    this -> valorUm = novoValor;
}

void SubtradoraDeDigito::perderUnidade()
{
    if(this -> valorUm == '0')
        return;

    int novoValor = caracteres.getValor(this -> valorUm);
    novoValor--;
    this -> valorUm = caracteres.getChar(novoValor);
}
