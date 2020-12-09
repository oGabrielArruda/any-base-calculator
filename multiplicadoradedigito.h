#ifndef MULTIPLICADORADEDIGITO_H_INCLUDED
#define MULTIPLICADORADEDIGITO_H_INCLUDED

class MultiplicadoraDeDigito {
    private:
        char resto;
        char valorDaMultiplicacao;
        char multiplicacaoBruta;
    public:
        void Multiplicar(char, char, char, int);
        char getResto();
        char getMultiplicacao();
        char getMultiplicacaoBruta();
};

#endif // MULTIPLICADORADEDIGITO_H_INCLUDED
