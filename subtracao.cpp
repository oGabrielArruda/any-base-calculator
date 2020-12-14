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
    this -> pilhaExpressao = getPilhaExpressao(valores[0], valores[1]);
}

string Subtracao::calcular()
{
    string resultado = "";
    int tamPilha = this -> pilhaExpressao.size();
    bool emprestando = false;

    // enquanto ainda há contas a se fazer
    while(tamPilha > 0)
    {
        SubtradoraDeDigito contaDigito = pegarTopo();

        if(contaDigito.getValorUm() == ',' || contaDigito.getValorUm() == '.')
        {
            resultado = "," + resultado;
            tamPilha--;
            continue;
        }


        if(contaDigito.Subtrair())
        {
            resultado = contaDigito.getSubtraido() + resultado;
        }
        else
        {
            // se nao conseguimos fazer a subtracao, emprestamos os números
            SubtradoraDeDigito emprestado = emprestar(contaDigito);
            emprestado.Subtrair();
            resultado = emprestado.getSubtraido() + resultado;
        }

        tamPilha--;
    }

    return resultado;
}


SubtradoraDeDigito Subtracao::emprestar(SubtradoraDeDigito contaDigito)
{
    bool terminou = false;
    stack<SubtradoraDeDigito> pilhaEmprestimo;

    while(!terminou)
    {
        // pegamos o próximo valor da expressão, para tentarmos realizar o empréstimo
        SubtradoraDeDigito topo = this -> pilhaExpressao.top();
        char valorUmTopo = topo.getValorUm();

        // caso seja possível emprestar
        if(valorUmTopo != '0' && valorUmTopo != ',' && valorUmTopo != '.')
        {
            // "cortamos o número"
            topo.perderUnidade();
            this -> pilhaExpressao.pop();
            this -> pilhaExpressao.push(topo);

            // e vamos passando o empréstimo para a frente
            int qtdPilhaEmprestimo = pilhaEmprestimo.size();
            while(qtdPilhaEmprestimo > 0)
            {
                // pegamos o valor que receberá o empréstimo
                SubtradoraDeDigito paraEmprestar = pilhaEmprestimo.top();
                pilhaEmprestimo.pop();
                qtdPilhaEmprestimo--;

                // se o valor nao for vírgula nem ponto
                if(paraEmprestar.getValorUm() != ',' && paraEmprestar.getValorUm() != '.')
                {
                    // emprestamos a ele
                    paraEmprestar.receberBase();

                    // e logo em seguida o cortamos, pois estamos emprestando para os próximos valores (que são 0)
                    paraEmprestar.perderUnidade();
                }

                // voltamos o valor já adaptado para a pilha da expressao
                this -> pilhaExpressao.push(paraEmprestar);
            }

            SubtradoraDeDigito s = this -> pilhaExpressao.top();

            // após emprestarmos para todos os antecedentes (se houverem), emprestamos a nossa conta requesitada
            contaDigito.receberBase();
            terminou = true;
        }
        else // caso o empréstimo não seja possível, temos que buscar outro número anterior para faze-lo
        {
            // empilhamos a conta na pilha de emprestimos a serem feitos
            pilhaEmprestimo.push(topo);

            // o retiramos da pilha expressao
            this -> pilhaExpressao.pop();
        }
    }

    return contaDigito;
}

SubtradoraDeDigito Subtracao::pegarTopo()
{
    SubtradoraDeDigito s = this -> pilhaExpressao.top();
    this -> pilhaExpressao.pop();
    return s;
}

stack<SubtradoraDeDigito> Subtracao::getPilhaExpressao(string valorUm, string valorDois)
{
    int len = this -> valorUm.length();
    stack<SubtradoraDeDigito> pilha;

    for(int i = 0; i < len; i++)
    {
        char a = valorUm.at(i);
        char b = valorDois.at(i);

        SubtradoraDeDigito s(a, b, this -> base);
        pilha.push(s);
    }

    return pilha;
}
