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


    if(lenUmAntesDaVirgula != lenDoisAntesDaVirgula)
        if(lenUmAntesDaVirgula > lenDoisAntesDaVirgula)
            valorDoisAntesDaVirgula = inserirZerosAntesDaVirgula(valorDoisAntesDaVirgula, lenUmAntesDaVirgula - lenDoisAntesDaVirgula);
        else
            valorUmAntesDaVirgula = inserirZerosAntesDaVirgula(valorUmAntesDaVirgula, lenDoisAntesDaVirgula - lenUmAntesDaVirgula);

    string valorUmDpsDaVirgula = getDepoisDaVirgula(nmrUm);
    int lenUmDepoisDaVirgula = valorUmDpsDaVirgula.length();

    string valorDoisDpsDaVirgula = getDepoisDaVirgula(nmrDois);
    int lenDoisDepoisDaVirgula = valorDoisDpsDaVirgula.length();

    if(lenUmDepoisDaVirgula != lenDoisDepoisDaVirgula)
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

    bool temVirgula = false;
    for(int i = 0; i< lenNmr && temVirgula == false; i++)
    {
        if(nmr.at(i) == ',' || nmr.at(i) == '.')
            temVirgula = true;
    }

    if(temVirgula == false)
    {
        nmr+=",";
        limite--;
    }

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
        return nmr.substr(posVirgula, lenNmr);
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
        if(c == ',' || c == '.')
            break;
        ret += c;
    }

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

int Utils::GetQtdDepoisDaVirgula(string nmr)
{
    int i = 0;
    int qtd = 0;
    int len = nmr.length();

    for(i = 0; i < len; i++)
        if(nmr.at(i) == ',' || nmr.at(i) == '.')
            break;

    if(i == len)
        return 0;
    else
        return len - 1 - i;
}

