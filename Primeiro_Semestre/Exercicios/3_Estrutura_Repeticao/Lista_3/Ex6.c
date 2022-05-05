/* 6) O Triângulo de Floyd é um triângulo formado com números naturais. O triângulo começa em 1 no canto
superior esquerdo e continua a escrever a sequência de números naturais de tal modo que cada linha contém
um número a mais do que a linha anterior. Escreva um programa que leia um número inteiro positivo n e em
seguida imprima n linhas do Triângulo de Floyd. */

/*
O programa precisa ler um numero, mostrar a primeira linha como 1, a segunda como 2 e 3... Para isso, ir somando
1 no numero que deve ser mostrado, e identificar quantos dígitos deve mostrar por linha, até o número de linhas ser igual ao
numero informado
*/

#include <stdio.h>

int main(void)
{
    int num;
    char opcao;

    do
    {
        do
        {
            printf ("\nInforme um numero positivo: ");
            scanf ("%d", &num);

            if (num <= 0)
            {
                printf ("\nValor invalido\n");
            }
        } while (num <= 0);

        

        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf ("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}