#include "divisao.h"
#include "utils.h"
#include "multiplicacao.h"
#include "subtracao.h"
#include "caracteres.h"
#include <iostream>

Divisao::Divisao(string dividendo, string divisor, int base)
{
    string* valores = Utils::AdaptarValoresDivisao(dividendo, divisor);
    this -> dividendo = valores[0];
    this -> divisor = valores[1];
    cout << this -> dividendo << "    ";
    cout << this -> divisor << "   ";
    this -> parteFracionaria = false;
    this -> base = base;
}

string Divisao::calcular() {
    this -> arco = "1";
    bool primeiraVez = true;

    while(arco != "")
    {
        prepararArco(primeiraVez);
        primeiraVez = false;

        dividirExpressao();
    }

    // preenche o quociente com zeros, caso o resultado tenha batido
    while(!this->escorrega.empty())
    {
        quociente +="0";
        this->escorrega.pop();
    }


    return this -> quociente;
}


void Divisao::prepararArco(bool primeiraVez)
{
    if(primeiraVez)
    {
        prepararArcoPrimeiraVez();
    }
    else
    {
        this -> arco = Utils::RetirarZerosDaEsquerda(arco);
        if(this -> parteFracionaria)
            this -> arco += "0";
    }


    while(Utils::EhMenor(this -> arco, divisor))
    {
        aumentarArco();
    }
}

void Divisao::prepararArcoPrimeiraVez()
{
    int divisorSize = this -> divisor.length();
    int dividendoSize = this -> dividendo.length();

    // se o tamanho do divisor for menor ou igual ao do dividendo
    if(divisorSize < dividendoSize)
        this -> arco = this -> dividendo.substr(0, divisorSize); // setamos o arco com o tamanho do divisor
    else
        this -> arco = this -> dividendo;


    // colocamos os caracteres do dividendo na fila para futuramente esccorrega-los
    for(int j = divisorSize; j < dividendoSize; j++)
        this -> escorrega.push(this -> dividendo.at(j));


    // aumentamos o arco, enquanto ele for menor que o divisor
    while(Utils::EhMenor(this -> arco, divisor))
    {
        aumentarArco();
    }
}

void Divisao::aumentarArco()
{
    // se não houver números para "escorregar" do dividendo
    if(this -> escorrega.empty())
    {
        this -> arco += "0";
        incrementarQuociente();
    }
    else
    {
        char caractereParaDescer = this -> escorrega.front();
        this -> arco += caractereParaDescer;
        this -> escorrega.pop();
    }
}


void Divisao::incrementarQuociente()
{
    // se o quociente está vazio, inserimos 0 e vírgula
    if(this -> quociente == "")
        this -> quociente += "0,";
    else
    {
        // se já há vírgula, inserimos apenas mais um zero
        if(Utils::Contem(this -> quociente, ',') || Utils::Contem(this -> quociente, '.'))
            this -> quociente += "0";
        else
            this -> quociente += ",";
            // se ainda não há vírgula, inserimos
    }

    this -> parteFracionaria = true;
}


void Divisao::dividirExpressao() {
    Caracteres caracteres;
    string ultimaMultiplicacao = "0";
    string saveMultiplicador;


    for(int i = 0; i < this -> base; i++)
    {
        string multiplicador(1,caracteres.getChar(i));
        Multiplicacao m(this -> divisor, multiplicador, this -> base);
        string resultado = m.calcular();

        if(Utils::EhMenor(this -> arco, resultado))
            break;
        else
        {
            ultimaMultiplicacao = resultado;
            saveMultiplicador = multiplicador;
        }
    }

    Subtracao s(arco, ultimaMultiplicacao, this -> base);
    string subtracao = s.calcular();
    this -> arco = Utils::RetirarZerosDaEsquerda(subtracao);
    this -> quociente += saveMultiplicador;

    cout << "Quociente: " << this -> quociente;
    cout << "\nArco:: " << this -> arco;
    cout << "\n";
    char z;
    cin >> z;
}



