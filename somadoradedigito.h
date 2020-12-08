#ifndef SOMADORADEDIGITO_H_INCLUDED
#define SOMADORADEDIGITO_H_INCLUDED

class SomadoraDeDigito
{
    private:
        char resto;
        char valorDaSoma;
    public:
        void Somar(char, char, char, int);
        char getResto();
        char getSoma();

};

#endif // SOMADORADEDIGITO_H_INCLUDED
