#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int a[10], i, pares, impares;
    char opcao;

    do
    {
        pares = 0;
        impares = 0;

        for (i = 0; i < 10; i++)
        {
            printf("Informe um valor para a posi��o %d do vetor A: ", i + 1);
            scanf("%d", &a[i]);
        }

        printf("\n==== PARES =====\n");
        for (i = 0; i < 10; i++)
        {
            if (a[i] % 2 == 0)
            {
                printf("A[%d] = %2d <--- %d� nro par\n", i, a[i], pares + 1);
                pares++;
            }
        }

        printf("\n==== IMPARES =====\n");
        for (i = 0; i < 10; i++)
        {
            if (a[i] % 2 != 0)
            {
                printf("A[%d] = %2d <--- %d� nro par\n", i, a[i], impares + 1);
                impares++;
            }
        }

        printf ("\nExistem %d n�meros pares no vetor, ou seja, %.2f%%", pares, (float)pares * 10);
        printf ("\nExistem %d n�meros impares no vetor, ou seja, %.2f%%", impares, (float)impares * 10);

        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}