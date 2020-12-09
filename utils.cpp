#include <string>
#include "utils.h"
#include  <iostream>

using namespace std;

string getAntesDaVirgula(string nmr);
string inserirZerosDepoisDaVirgula(string nmr, int limite);
string getDepoisDaVirgula(string nmr);
string inserirZerosAntesDaVirgula(string nmr, int qtd);

string* Utils::AdaptarValores(string nmrUm, string nmrDois)
{
    string valorUmAdaptado = "";
    string valorDoisAdaptado = "";

    string valorUmAntesDaVirgula = getAntesDaVirgula(nmrUm);
    int lenUmAntesDaVirgula = valorUmAntesDaVirgula.length();

    string valorDoisAntesDaVirgula = getAntesDaVirgula(nmrDois);
    int lenDoisAntesDaVirgula = valorDoisAntesDaVirgula.length();


    if(lenUmAntesDaVirgula > lenDoisAntesDaVirgula)
        valorDoisAntesDaVirgula = inserirZerosAntesDaVirgula(valorDoisAntesDaVirgula, lenUmAntesDaVirgula - lenDoisAntesDaVirgula);
    else
        valorUmAntesDaVirgula = inserirZerosAntesDaVirgula(valorUmAntesDaVirgula, lenDoisAntesDaVirgula - lenUmAntesDaVirgula);

    string valorUmDpsDaVirgula = getDepoisDaVirgula(nmrUm);
    int lenUmDepoisDaVirgula = valorUmDpsDaVirgula.length();

    string valorDoisDpsDaVirgula = getDepoisDaVirgula(nmrDois);
    int lenDoisDepoisDaVirgula = valorDoisDpsDaVirgula.length();

    if(lenUmDepoisDaVirgula > lenDoisDepoisDaVirgula)
        valorDoisDpsDaVirgula = inserirZerosDepoisDaVirgula(valorDoisDpsDaVirgula, lenUmDepoisDaVirgula);
    else
        valorUmDpsDaVirgula = inserirZerosDepoisDaVirgula(valorUmDpsDaVirgula, lenDoisDepoisDaVirgula);

    string *ret = new string[2];
    ret[0] = valorUmAntesDaVirgula + valorUmDpsDaVirgula;
    ret[1] = valorDoisAntesDaVirgula + valorDoisDpsDaVirgula;
    return ret;
}

string inserirZerosDepoisDaVirgula(string nmr, int limite)
{
    int lenNmr = nmr.length();

    while(lenNmr < limite) {
        nmr += "0";
        lenNmr++;
    }
    return nmr;
}

string getDepoisDaVirgula(string nmr)
{
    int lenNmr = nmr.length();
    int posVirgula = -1;

    for(int i = 0; i < lenNmr; i++)
        if(nmr.at(i) == ','|| nmr.at(i) == '.')
        {
            posVirgula = i;
            break;
        }

    if(posVirgula == -1)
        return "";
    else
        return nmr.substr(posVirgula + 1, lenNmr);
}

string inserirZerosAntesDaVirgula(string nmr, int qtd)
{
    string ret = "";
    int i = 0;

    while(i < qtd) {
        ret += "0";
        i++;
    }
    ret = ret + nmr;
    return ret;
}

string getAntesDaVirgula(string nmr)
{
    string ret = "";
    int i;
    int len = nmr.length();

    for(i = 0; i < len; i++)
    {
        char c = nmr.at(i);
        ret += c;
        if(c == ',' || c == '.')
            break;
    }

    if(i == len)
        ret += ",";

    return ret;
}

int getLengthAntesDaVirgula(string nmr)
{
    int index = 0;
    int len = nmr.length();

    for(index = 0; index < len; index++)
    {
        if(nmr.at(index) == ',' || nmr.at(index) == '.')
            break;
    }
    return index-1;
}

