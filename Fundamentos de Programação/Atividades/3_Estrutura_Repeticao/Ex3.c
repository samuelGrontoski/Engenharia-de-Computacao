/* 3) Apresentar os números primos entre dois valores, que representam os limites inferior e superior,
respectivamente, de um intervalo, informados pelo usuário. Apresentá-los com n números por linha. n é
informado pelo usuário. Validar n para que seja maior que 0. Validar o limite inferior para seja maior que 1 e o
limite superior para que seja maior ou igual ao limite inferior. Implementar a repetição de programa.
*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int inf, sup, linha, count, countLinha, countPrimos, j, i;
    char opcao;

    do
    {
        do
        {
            printf("\nInforme o valor do limite inferior do intervalo: ");
            scanf("%d", &inf);

            if (inf < 1)
            {
                printf("\nO valor informado deve ser maior que 1\n");
            }
        } while (inf < 1);

        do
        {
            printf("\nInforme o valor limite superior do intervalo: ");
            scanf("%d", &sup);

            if (sup < inf)
            {
                printf("\nO valor do limite superior deve maior ou igual ao limite inferior\n");
            }
        } while (sup < inf);

        do
        {
            printf("\nInforme quantos números deseja imprimir por linha: ");
            scanf("%d", &linha);

            if (linha <= 0)
            {
                printf("\nInforme um valor positivo\n");
            }

        } while (linha <= 0);

        for (i = inf; i <= sup; i++)
        {
            count = 1;

            for (j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    count = 0;
                }
            }

            if (count == 1)
            {
                printf("%d\t", i);
                countLinha++;
            }

            if (countLinha % linha == 0)
            {
                printf("\n");
            }
        }

        printf("\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}