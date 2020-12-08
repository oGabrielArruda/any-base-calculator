#include <cctype>
#include "caracteres.h"

static const char charArray[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F',
'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
static const int ARR_SIZE = 36;

int Caracteres::getValor(char c)
{
    int valor = -1;
    c = toupper(c);

    for(int i = 0; i < ARR_SIZE; i++)
        if(charArray[i] == c)
            valor = i;

    return valor;
}


char Caracteres::getChar(int v)
{
    return charArray[v];
}
