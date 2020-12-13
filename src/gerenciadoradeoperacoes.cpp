#include "gerenciadoradeoperacoes.h"
#include <iostream>
#include <string>
#include "utils.h"
#include "soma.h"
#include "subtracao.h"
#include "multiplicacao.h"
#include "divisao.h"

GerenciadoraDeOperacoes::GerenciadoraDeOperacoes(string valorUm, string valorDois, int base)
{
    this -> valorUm = valorUm;
    this -> valorDois = valorDois;
    this -> base = base;
}

string GerenciadoraDeOperacoes::requisitarSoma()
{
    /*if(Utils::isSinaisIguais)
        return this -> somar();
    return this -> requisitarSubtracao();*/
}

string GerenciadoraDeOperacoes::requisitarSubtracao()
{
    /*if(Utils::isSinaisIguais)
    {
        if(Utils::EhMenor(valorUm, valorDois)){
            string valorAux = this -> valorUm;
            this -> valorUm = this -> valorDois;
            this -> valorDois = valorAux;

            return "-" + this -> subtrair();
        }
        return "b";
    }
    return "a";*/
}

string GerenciadoraDeOperacoes::requisitarMultiplicacao()
{
    return "aaaaaa";
}

string GerenciadoraDeOperacoes::requisitarDivisao()
{
    return "aaaaa";
}

string GerenciadoraDeOperacoes::somar()
{
    Soma soma(valorUm, valorDois, base);
    return soma.calcular();
}

string GerenciadoraDeOperacoes::multiplicar()
{
    Multiplicacao multiplicacao(valorUm, valorDois, base);
    return multiplicacao.calcular();
}

string GerenciadoraDeOperacoes::subtrair()
{
    Subtracao subtracao(valorUm, valorDois, base);
    return subtracao.calcular();
}

/*string GerenciadoraDeOperacoes::dividir()
{
    Divisao divisao(valorUm, valorDois, base);
    return divisao.calcular();
}*/

