/* 6) O Triângulo de Floyd é um triângulo formado com números naturais. O triângulo começa em 1 no canto
superior esquerdo e continua a escrever a sequÊncia de nÚmeros naturais de tal modo que cada linha contém
um número a mais do que a linha anterior. Escreva um programa que leia um número inteiro positivo n e em
seguida imprima n linhas do Triângulo de Floyd. */

/*
O programa precisa ler um numero, mostrar a primeira linha como 1, a segunda como 2 e 3... Para isso, ir somando
1 no numero que deve ser mostrado, e identificar quantos dí­gitos deve mostrar por linha, até o número de linhas ser igual ao
numero informado
*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int num, linha, count, countLinha, i;
    char opcao;

    do
    {
        do
        {
            printf("\nInforme um número positivo: ");
            scanf("%d", &linha);

            if (linha <= 0)
            {
                printf("\nValor invalido\n");
            }
        } while (linha <= 0);

        countLinha = 1;
        count = 0;

        for (num = 1; countLinha <= linha; num++)
        {
            printf("%d\t", num);
            count++;
            if (count == countLinha)
            {
                printf("\n");
                count = 0;
                countLinha++;
            }
        }

        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}
