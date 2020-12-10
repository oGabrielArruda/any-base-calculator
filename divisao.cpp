#include "divisao.h"
#include "utils.h"
#include "multiplicacao.h"
#include "subtracao.h"
#include "caracteres.h"
#include <iostream>

Divisao::Divisao(string dividendo, string divisor, int base)
{
    this -> dividendo = Utils::TirarVirgula(dividendo);
    this -> divisor = Utils::TirarVirgula(divisor);
    this -> parteFracionaria = false;
    this -> base = base;
}

string Divisao::calcular() {
    string dividendo = this -> dividendo;
    string divisor = this -> divisor;

    while(this -> dividendo != "0")
    {
        if(this -> parteFracionaria)
            this -> dividendo += "0";

        bool a = Utils::EhMenor(dividendo, divisor);
        while(Utils::EhMenor(dividendo, divisor))
            adaptarExpressoes();
        dividirExpressao();
    }

    return this -> quociente;
}

void Divisao::adaptarExpressoes()
{
    if(this -> quociente == "")
        this -> quociente += "0,";
    else
        if(Utils::Contem(this -> quociente, ',') || Utils::Contem(this -> quociente, '.'))
            this -> quociente += "0";
        else
            this -> quociente += ",";

    this -> dividendo += "0";
    this -> arco = this -> dividendo;
    this -> parteFracionaria = true;
}

void Divisao::dividirExpressao() {
    Caracteres caracteres;
    string ultimaMultiplicacao = "0";
    string saveMultiplicador;

    gerarArco();
    while(Utils::EhMenor(dividendo, divisor))
        adaptarExpressoes();

    char a;
    std::cout << "Dividendo: ";
    std::cout<< this-> dividendo <<"\n";
    std::cout << "Divisor: ";
    std::cout<< this-> divisor <<"\n";
    std::cout << "Arco: ";
    std::cout<< this -> arco <<"\n";

    for(int i = 0; i < this -> base; i++)
    {
        string multiplicador(1,caracteres.getChar(i));
        std::cout<<multiplicador<<"\n";
        Multiplicacao m(this -> divisor, multiplicador, this -> base);
        string resultado = m.calcular();

        std::cout << "resultado da multiplicacao: ";
        std::cout << resultado << "\n";
        std::cin >> a;

        if(Utils::EhMenor(this -> arco, resultado))
            break;
        else
        {
            ultimaMultiplicacao = resultado;
            saveMultiplicador = multiplicador;
        }

    }

    std::cout << "Subtracao: ";
    std::cout << this -> arco << "  -  ";
    std::cout << ultimaMultiplicacao << "\n";
    std::cin >> a;

    Subtracao s(arco, ultimaMultiplicacao, this -> base);
    string subtracao = s.calcular();
    this -> dividendo = subtracao + this->dividendo.substr(this->divisor.length() + 1, this->dividendo.length() - this->divisor.length());

    std::cout << "valor da subtracao: ";
    std::cout << subtracao << "\n";
    std::cin >> a;

    this -> quociente += saveMultiplicador;
    std::cout << "quociente: ";
    std::cout << quociente << "\n";
}


string Divisao::gerarArco()
{
    this -> dividendo = Utils::RetirarZerosDaEsquerda(this -> dividendo);

    if(this -> divisor.length() < this -> dividendo.length())
        this -> arco = this -> dividendo.substr(0, this->divisor.length()+1);
    else
    {
        this -> arco = this -> dividendo;
    }
}


