#include "multiplicadoradedigito.h"
#include "caracteres.h"
#include <iostream>

void MultiplicadoraDeDigito::Multiplicar(char valorUm, char valorDois, char carga, int base)
{
    Caracteres caracteres;
    int multiplicacao = caracteres.getValor(valorUm) * caracteres.getValor(valorDois) + caracteres.getValor(carga);
    this -> valorDaMultiplicacao = caracteres.getChar(multiplicacao % base);
    this -> resto = caracteres.getChar(multiplicacao / base);
}

char MultiplicadoraDeDigito::getMultiplicacao()
{
    return this -> valorDaMultiplicacao;
}

char MultiplicadoraDeDigito::getResto()
{
    return this -> resto;
}
