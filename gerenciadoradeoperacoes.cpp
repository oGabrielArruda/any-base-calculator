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
    char sinalValorUm = this -> valorUm.at(0);
    char sinalValorDois = this -> valorDois.at(0);

    if(Utils::isSinaisIguais(sinalValorUm, sinalValorDois))
    {
        string valorSoma = this -> somar();

        if(sinalValorUm == '-')
            return '-' + valorSoma;
        else
            return valorSoma;
    }

    return this -> requisitarSubtracao();
}

string GerenciadoraDeOperacoes::requisitarSubtracao()
{
    char sinalValorUm = this -> valorUm.at(0);
    char sinalValorDois = this -> valorDois.at(0);
    // pega o sinal dos dois valores

    if(Utils::isSinaisIguais(sinalValorUm, sinalValorDois)) // se os sinais forem iguais
    {
        if(sinalValorUm == '-' && sinalValorDois == '-') // os dois sinais sao negativos mas iguais
        {
            this -> valorUm = valorUm.substr(1, valorUm.size() - 1);
            this -> valorDois = valorDois.substr(1, valorDois.size() - 1);
            // pega o valor das variaveis sem os sinais

            if(Utils::EhMenor(valorUm, valorDois)){ // se o primeiro for menor que o segundo, inverte as variaveis
                string valorAux = this -> valorUm;
                this -> valorUm = this -> valorDois;
                this -> valorDois = valorAux;

                return this -> subtrair();
            }
            return "-" + this -> subtrair();
        }

        if(Utils::EhMenor(valorUm, valorDois)){
            string valorAux = this -> valorUm;
            this -> valorUm = this -> valorDois;
            this -> valorDois = valorAux;

            return "-" + this -> subtrair();
        }
        return this -> subtrair();
    }

    // se só um sinal for negativo
    if(sinalValorUm == '-'){
        this -> valorUm = valorUm.substr(1, valorUm.size() - 1);

        if(Utils::EhMenor(valorUm, valorDois)){
            string valorAux = this -> valorUm;
            this -> valorUm = this -> valorDois;
            this -> valorDois = valorAux;
        }
        return "-" + this -> somar();
    }

    else{
        this -> valorDois = valorDois.substr(1, valorDois.size() - 1);
        return this -> somar();
    }
}

string GerenciadoraDeOperacoes::requisitarMultiplicacao()
{
    char sinalValorUm = this -> valorUm.at(0);
    char sinalValorDois = this -> valorDois.at(0);

    if(Utils::isSinaisIguais(sinalValorUm, sinalValorDois))
    {
        if(sinalValorUm == '-' && sinalValorDois == '-')
        {
            this -> valorUm = valorUm.substr(1, valorUm.size() - 1);
            this -> valorDois = valorDois.substr(1, valorDois.size() - 1);
        }

        return this -> multiplicar();
    }

    if(sinalValorUm == '-')
        this -> valorUm = valorUm.substr(1, valorUm.size() - 1);

    else
        this -> valorDois = valorDois.substr(1, valorDois.size() - 1);

    return "-" + this -> multiplicar();
}

string GerenciadoraDeOperacoes::requisitarDivisao()
{
    char sinalValorUm = this -> valorUm.at(0);
    char sinalValorDois = this -> valorDois.at(0);

    if(Utils::isSinaisIguais(sinalValorUm, sinalValorDois))
    {
        if(sinalValorUm == '-' && sinalValorDois == '-')
        {
            this -> valorUm = valorUm.substr(1, valorUm.size() - 1);
            this -> valorDois = valorDois.substr(1, valorDois.size() - 1);
        }

        return this -> dividir();
    }

    if(sinalValorUm == '-')
        this -> valorUm = valorUm.substr(1, valorUm.size() - 1);

    else
        this -> valorDois = valorDois.substr(1, valorDois.size() - 1);

    return "-" + this -> dividir();
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

string GerenciadoraDeOperacoes::dividir()
{
    Divisao divisao(valorUm, valorDois, base);
    return divisao.calcular();
}

