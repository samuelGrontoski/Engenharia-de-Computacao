/*6) Na matem�tica, o fatorial de um n�mero � o produto de todos os inteiros positivos menores ou iguais ao
n�mero. Exemplo: Fatorial de 5 � 1 * 2 * 3 * 4 * 5 = 120. Elabore um programa que calcule e mostre o fatorial
de um n�mero informado pelo usu�rio. Validar esse n�mero para que esteja em um intervalo de 1 a 20.
Lembrando que fatorial de 1 = 1 e fatorial de 0 = 1.
Obs.: Use uma vari�vel de tipo de dado long long int (%lld) para armazenar o fatorial. */

#include <stdio.h>

int main (void)
{
    int num, i;
    long long int fat=1;

    do
    {
        printf ("Informe um numero: ");
        scanf ("%d", &num);

        if (num < 1 || num > 20)
        {
            printf ("Valor invalido\n");
        }

    } while(num < 1 || num > 20);

    printf ("%d! = ", num);

    for (i=num; i >= 2; i--)
    {
        printf ("%d * ", i);
        fat = fat * i;
    }

    printf ("1 = %lld\n", fat);

    return 0;
}
