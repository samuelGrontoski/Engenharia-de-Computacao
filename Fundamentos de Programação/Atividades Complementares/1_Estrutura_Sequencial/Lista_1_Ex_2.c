/*2) Escreva um algoritmo que leia o valor de uma prestação e da taxa de juros cobrada pelo atraso da prestação. Calcule o valor a ser pago por meio da fórmula:
Valor com juros = Prestação + (Prestação * Taxa /100)
*/

#include <stdio.h>

int main (void) {
    float prestacao, juros, valorJuros;

    printf ("Informe o valor da prestacao: ");
    scanf ("%f", &prestacao);
    printf ("Informe a taxa de juros: ");
    scanf ("%f", &juros);

    valorJuros = prestacao + (prestacao*juros/100);

    printf ("o valor com juros eh R$%.2f", valorJuros);

    return 0;
}
