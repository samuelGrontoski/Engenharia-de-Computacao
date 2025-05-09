/* 1) Ler um número positivo, validar a entrada repetindo a leitura até que seja informado um número que
atende essa condição. Esse número representa a quantidade de números primos a serem mostrados. */

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");

    int quantidade, i, j, countDiv, contPrimos;
    char opcao;

    do
    {
        i = 2;
        contPrimos = 0;

        do
        {
            printf("Informe a quantidade de numeros primos que deseja mostrar: ");
            scanf("%d", &quantidade);

            if (quantidade <= 0)
            {
                printf("\nInforme um numero positivo\n\n");
            }
        } while (quantidade <= 0);

        do
        {
            countDiv = 0;

            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    countDiv++;
                    break;
                }
            }
            if (countDiv == 0)
            {
                printf("%d\t", i);
                contPrimos++;
            }
            i++;
        } while (contPrimos < quantidade);

        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}