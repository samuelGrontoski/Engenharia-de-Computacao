/*5) (DESAFIO) Obter o resto da divisão de dois valores inteiros informados pelo usuário, sem usar o operador
de resto.*/

#include <stdio.h>

int main (void) {

    int num1, num2, divisao, resto;

    printf ("Informe o primeiro valor: ");
    scanf ("%d", &num1);
    printf ("Informe o segundo valor: ");
    scanf ("%d", &num2);

    divisao = num1 / num2;
    resto = num1 - (divisao * num2);

    printf ("\nResto da divisao: %d\n", resto);

    return 0;
}
