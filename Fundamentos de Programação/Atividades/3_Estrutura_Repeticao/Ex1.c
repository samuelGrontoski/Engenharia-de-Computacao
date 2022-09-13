/*1) Ler um número e ler um dígito. Contar quantos dígitos o número possui*/

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
            printf("\nDigite um dígito: ");
            scanf("%d", &digito);

            if (digito < 0 || digito > 9)
            {
                printf("\n%d não é um dígito válido.\n", digito);
            }

        } while (digito < 0 || digito > 9);

        do
        {
            countDig = 0;
            j = 1;

            printf("\nDigite um número: ");
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

            printf("O número possui %d dígitos iguais a %d", countDig, digito);

        } while (num > 0);

        printf("\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}