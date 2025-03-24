#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    char opcao;
    int limInf, limSup, i, j, count, countNum, countPares;

    do
    {
        do
        {
            printf("Informe um valor maior que 0 para o limite inferios do intervalo: ");
            scanf("%d", &limInf);

            if (limInf <= 0)
            {
                printf("\nValor de entrada inválido\n\n");
            }
        } while (limInf <= 0);

        do
        {
            printf("Informe um valor maior que o limite inferior para o limite superior do intervalo: ");
            scanf("%d", &limSup);

            if (limSup <= limInf)
            {
                printf("\nValor de entrada inválido\n\n");
            }
        } while (limSup <= limInf);

        count = limInf;

        do
        {
            j = 1;
            i = 1;
            countPares = 0;
            printf("%d ==> 1   ", count);

            for (countNum = 1; countNum <= count; countNum++)
            {
                printf("%d\t", i);
                i = i + j;
                j = i - j;

                if (j % 2 == 0)
                {
                    countPares++;
                }
            }
            printf("==> %d pares", countPares);
            printf("\n");
            count++;
        } while (count <= limSup);

        printf("Deseja continuar no programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}