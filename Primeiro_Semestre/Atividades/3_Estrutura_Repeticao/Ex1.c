/*1) Ler um n�mero e ler um d�gito. Contar quantos d�gitos o n�mero possui*/

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int digito, num, i, j, countDig, div;
    char opcao;
    do
    {
        do
        {
            printf("\nDigite um d�gito: ");
            scanf("%d", &digito);

            if (digito < 0 || digito > 9)
            {
                printf("\n%d n�o � um d�gito v�lido.\n", digito);
            }

        } while (digito < 0 || digito > 9);

        do
        {
            countDig = 0;
            j = 1;

            printf("\nDigite um n�mero: ");
            scanf("%d", &num);

            for (i = 10; j < num; i * 1)
            {
                div = (num % i) / j;

                if (div == digito)
                {
                    countDig++;
                }

                if (j == 1)
                {
                    i = i * 10;
                    j = j + 9;
                }
                else
                {
                    i = i * 10;
                    j = j * 10;
                }
            }

            printf("O n�mero possui %d d�gitos iguais a %d", countDig, digito);

        } while (num > 0);

        printf("\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}