#include <iostream>
#include <string>
#include "soma.h"
#include "subtracao.h"
#include "multiplicacao.h"
#include "divisao.h"

using namespace std;

int main() {
    int continuar = 0;

    do
    {
        string operacoesValidas = "+-/*";
        string nmrUm, nmrDois;
        char operacao;
        int base;

        cout << "CALCULADORA DE DIFERENTES BASES ";

        cout << "\n Digite a base em que os numeros estao: ";
        cin >> base;

        cout << "\n Digite o valor do primeiro numero: ";
        cin >> nmrUm;

        cout << "\n Digite a operacao desejada: ";
        cin >> operacao;

        cout << "\n Digite o valor do segundo numero: ";
        cin >> nmrDois;

        if(operacoesValidas.find(operacao) < 4)
        {
            string resultado;

            switch(operacao)
            {
                case '+':
                {
                    Soma s(nmrUm, nmrDois, base);
                    resultado = s.calcular();
                    break;
                }
                case '-':
                {
                    Subtracao s(nmrUm, nmrDois, base);
                    resultado = s.calcular();
                    break;
                }
                case '*':
                {
                    Multiplicacao m(nmrUm, nmrDois, base);
                    resultado = m.calcular();
                    break;
                }
                case '/':
                {
                    Divisao d(nmrUm, nmrDois, base);
                    resultado = d.calcular();
                    break;
                }
            }

            cout << "\nO resultado eh: \n" << resultado;
        }
        else
        {
            cout << "Insira uma operacao valida!";
            continue;
        }

        cout << "\nDigite 99 para sair.";
        cin >> continuar;
    }
    while(continuar != 99);

    return 0;
}
