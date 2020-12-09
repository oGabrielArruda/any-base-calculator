#ifndef SUBTRADORADEDIGITO_H_INCLUDED
#define SUBTRADORADEDIGITO_H_INCLUDED

class SubtradoraDeDigito {
    private:
        char valorUm;
        char valorDois;
        int base;
        char valorDaSubtracao;
    public:
        SubtradoraDeDigito(char, char, int);
        bool Subtrair();
        void perderUnidade();
        void receberBase();
        char getSubtraido();

};

#endif // SUBTRADORADEDIGITO_H_INCLUDED
