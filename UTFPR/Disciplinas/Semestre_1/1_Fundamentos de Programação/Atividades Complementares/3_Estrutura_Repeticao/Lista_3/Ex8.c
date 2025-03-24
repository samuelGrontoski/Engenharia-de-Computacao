/*8) Fazer um programa para mostrar os divisores, calcular a quantidade deles e mostrar essa quantidade para
os n�meros compreendidos entre o valor ?x? (informado pelo usu�rio) e ?x+10?, inclusive. Validar a entrada, o
usu�rio dever� fornecer um n�mero positivo entre 2 e 100. Ao final, mostrar a maior quantidade de divisores.*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int num, i, countDiv, divisor;
    char opcao;

    do
    {
        do
        {
            printf("\nInforme um n�mero entre 2 e 100: ");
            scanf("%d", &num);

            if (num < 2 || num > 100)
            {
                printf("\nValor inv�lido\n");
            }
        } while (num < 2 || num > 100);

        for (i = num; i <= num + 10; i++)
        {
            divisor = 1;
            countDiv = 0;

            printf ("%d ==> ", i);

            for (divisor = 1; divisor <= num + 10; divisor++)
            {
                if (i % divisor == 0)
                {
                    printf ("%d, ", divisor);
                    countDiv++;
                }
            }
            printf ("%d divisores\n", countDiv);
        }

        printf("\nDeseja digitar outro numero (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}