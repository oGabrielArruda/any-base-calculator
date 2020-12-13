#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>

class Utils
{
    public:
        static std::string* AdaptarValores(std::string, std::string);
        static std::string* AdaptarValoresDivisao(std::string, std::string);
        static int GetQtdDepoisDaVirgula(std::string);
        static std::string TirarVirgula(std::string);
        static bool EhMenor(std::string, std::string);
        static bool Contem(std::string, char);
        static std::string RetirarZerosDaEsquerda(std::string);
        static bool isSinaisIguais(char, char);
};

#endif // UTILS_H_INCLUDED
