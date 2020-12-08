#include <ctype.h>
#include "somadoradedigito.h"
#include "caracteres.h"

Caracteres caractetes;

void SomadoraDeDigito::Somar(char valorA, char valorB, char carga, int base)
{
    int soma = caractetes.getValor(valorA) + caractetes.getValor(valorB) + caractetes.getValor(carga);

    this -> valorDaSoma = caractetes.getChar(soma % base);
    this -> resto = caractetes.getChar(soma / base);
}


char SomadoraDeDigito::getResto()
{
    return this -> resto;
}

char SomadoraDeDigito::getSoma()
{
    return this -> valorDaSoma;
}


