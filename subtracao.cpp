#include "subtracao.h"
#include "subtradoradedigito.h"
#include "utils.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

Subtracao::Subtracao(string valorUm, string valorDois, int base)
{
    string* valores = Utils::AdaptarValores(valorUm, valorDois);
    this -> valorUm = valores[0];
    this -> valorDois = valores[1];
    this -> base = base;
}

string Subtracao::calcular()
{
    string resultado = "";
    stack<SubtradoraDeDigito> pilha;
    bool emprestando = false;
    int len = this -> valorUm.length();

    for(int i = len - 1; i >= 0; i--)
    {
        char a = valorUm.at(i);
        char b = valorDois.at(i);
        SubtradoraDeDigito s(a, b, this -> base);

        if(a == ',' || b == '.')
        {
            resultado = "," + resultado;
            continue;
        }

        if(emprestando)
        {
            if(a != '0')
            {
                int qtd = pilha.size();
                while(!pilha.empty())
                {
                    s.perderUnidade();
                    SubtradoraDeDigito topo = pilha.top();
                    topo.receberBase();
                    topo.Subtrair();

                    pilha.pop();
                    qtd--;
                    if(qtd == 0)
                        resultado = topo.getSubtraido() + resultado;
                }
            }
            else
                pilha.push(s);


        }

        if(!s.Subtrair())
        {
            pilha.push(s);
            emprestando = true;
        }
        else
            resultado = s.getSubtraido() + resultado;
    }
    return resultado;
}
