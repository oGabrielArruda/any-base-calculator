#include "multiplicacao.h"
#include "multiplicadoradedigito.h"
#include "utils.h"
#include "soma.h"
#include <stack>
#include <iostream>

Multiplicacao::Multiplicacao(string valorUm, string valorDois, int base)
{
    this -> valorUm = valorUm;
    this -> valorDois = valorDois;
    this -> base = base;
}

string Multiplicacao::calcular()
{
    MultiplicadoraDeDigito m;
    int lenCima = this -> valorUm.length();
    int lenBaixo = this -> valorDois.length();
    int totalVirgulas = 0;

    char resto = '0';

    stack<string> pilha;
    int qtsLinhas = 0;

    for(int i = lenBaixo-1; i >= 0; i--)
    {
        char b = valorDois.at(i);
        if(b == ',' || b == '.')
        {
            totalVirgulas += lenBaixo - i - 1;
            continue;
        }

        qtsLinhas++;

        string linha = "";
        for(int j = lenCima-1; j >= 0; j--)
        {
            char a = valorUm.at(j);
            if(a == ',' || a == '.')
            {
                totalVirgulas += lenCima - i - 1;
                continue;
            }


            m.Multiplicar(a, b, resto, this -> base);
            linha = m.getMultiplicacao() + linha;
            resto = m.getResto();
        }

        if(resto != '0')
            linha = resto + linha;
        resto = '0';
        for(int k = 0; k < qtsLinhas-1; k++)
            linha = linha + "0";
        pilha.push(linha);
    }


    // somatória das multiplicações
    string linhaDeCima = pilha.top();
    pilha.pop();
    int qtdLinhas = pilha.size();

    while(qtdLinhas > 0)
    {
        string linhaDeBaixo = pilha.top();
        pilha.pop();

        Soma s(linhaDeCima, linhaDeBaixo, this -> base);
        linhaDeCima = s.calcular();
        qtdLinhas--;
    }

    int len = linhaDeCima.length();
    string result = "";
    for(int i = 0; i < len; i++)
    {
        if(i == len - totalVirgulas)
        {
            result += ",";
            result += linhaDeCima.at(i);
        }
        else {
            result += linhaDeCima.at(i);
        }

    }

    return result;
}
