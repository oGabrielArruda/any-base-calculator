#include <iostream>
#include <string>
#include "gerenciadoradeoperacoes.h"
#include "soma.h"
#include "subtracao.h"
#include "multiplicacao.h"
#include "divisao.h"

using namespace std;

int main() {
    string operacoesValidas = "+-/*";
    string nmrUm, nmrDois;
    char operacao;
    int base;

    cout << "CALCULADORA DE DIFERENTES BASES ";

    cout << "\n Digite a base em que os numeros estao: ";
    cin >> base;

    cout << "\n Digite o valor do primeiro numero: ";
    cin >> nmrUm;

    cout << "\n Digite a operacao desejada (+ - * /): ";
    cin >> operacao;

    cout << "\n Digite o valor do segundo numero: ";
    cin >> nmrDois;

    if(base > 0 && base <= 36)
    {
        if(operacoesValidas.find(operacao) < 4)
        {
            GerenciadoraDeOperacoes gerenciadoraDeOperacoes(nmrUm, nmrDois, base);
            string resultado;

            switch(operacao)
            {
                case '+':
                {
                    resultado = gerenciadoraDeOperacoes.requisitarSoma();
                    break;
                }
                case '-':
                {
                    resultado = gerenciadoraDeOperacoes.requisitarSubtracao();
                    break;
                }
                case '*':
                {
                    resultado = gerenciadoraDeOperacoes.requisitarMultiplicacao();
                    break;
                }
               case '/':
                {
                    resultado = gerenciadoraDeOperacoes.requisitarDivisao();
                    break;
                }
            }

            cout << "\nO resultado eh: " << resultado;
        }
        else
            cout << "Insira uma operacao valida!\n";

    }
    else
        cout << "Insira uma base valida!\n";


    return 0;
}
