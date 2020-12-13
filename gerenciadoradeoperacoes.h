#ifndef GERENCIADORADEOPERACOES_H_INCLUDED
#define GERENCIADORADEOPERACOES_H_INCLUDED
#include "soma.h"
#include "subtracao.h"
#include "multiplicacao.h"
#include "divisao.h"

class GerenciadoraDeOperacoes
{
    private:
        string somar();
        string multiplicar();
        string subtrair();
        string dividir();

        string valorUm;
        string valorDois;
        int base;

    public:
        GerenciadoraDeOperacoes(string, string, int);
        GerenciadoraDeOperacoes();
        string requisitarSoma();
        string requisitarSubtracao();
        string requisitarMultiplicacao();
        string requisitarDivisao();
};

#endif // GERENCIADORADEOPERACOES_H
