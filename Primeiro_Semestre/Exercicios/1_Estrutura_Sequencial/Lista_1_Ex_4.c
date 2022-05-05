/*4) Tendo como entrada dois valores inteiros, elaborar um algoritmo para calcular e mostrar:
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    float valor1, valor2, soma, subtracao, multiplicacao, divisao;
    int resto;

    printf ("Informe um valor inteiro: ");
    scanf ("%f", &valor1);
    printf ("Agora informe outro: ");
    scanf ("%f", &valor2);

    soma = valor1 + valor2;
    subtracao = valor1 - valor2;
    multiplicacao = valor1 * valor2;
    divisao = valor1 / valor2;
    resto = (int)valor1 % (int)valor2;

    printf ("%.0f + %.0f = %.0f\n", valor1, valor2, soma);
    printf ("%.0f - %.0f = %.0f\n", valor1, valor2, subtracao);
    printf ("%.0f * %.0f = %.0f\n", valor1, valor2, multiplicacao);
    printf ("%.0f / %.0f = %.0f\n", valor1, valor2, trunc(divisao));
    printf ("%.0f / %.0f = %.2f\n", valor1, valor2, divisao);
    printf ("%.0f %% %.0f = %d\n", valor1, valor2, resto);

    return 0;
}
