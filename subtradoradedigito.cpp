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

char SubtradoraDeDigito::getValorUm()
{
    return this -> valorUm;
}

char SubtradoraDeDigito::getValorDois()
{
    return this -> valorDois;
}
