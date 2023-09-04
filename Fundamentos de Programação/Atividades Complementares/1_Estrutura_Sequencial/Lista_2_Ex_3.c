/*3) Leia um valor double que representa o troco a ser fornecido por um caixa. Separe a parte inteira (reais) da
parte decimal (centavos) e apresente na forma: 123 reais e 18 centavos. Use a função round, da biblioteca
math.h, para o arredondamento da parte decimal).*/

#include <math.h>

int main (void) {

    double troco, cents;
    int reais;

    printf ("Informe o valor do troco: R$ ");
    scanf ("%lf", &troco);

    reais = (int)troco;
    cents = (troco - reais) * 100;
    round(cents);

    printf ("O valor informado eh %d reais e %.0lf centavos.", reais, cents);

    return 0;
}
