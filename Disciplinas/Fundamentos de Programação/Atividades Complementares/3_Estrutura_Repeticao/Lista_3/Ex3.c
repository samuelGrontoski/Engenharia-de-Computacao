/* 3) Escreva um programa que imprima todas as possibilidades de que no lançamento de dois dados a soma
das faces seja um valor informado pelo usuário. O usuário deve informar um valor válido entre 2 a 12. Repetir
a leitura até que o usuário informe um valor válido. */

#include <stdio.h>

int main(void)
{
    int resultado, dado1, dado2, controle, possibilidades;
    char opcao;

    do
    {
        possibilidades = 0;
        
        do
        {
            printf("\nInforme um valor entre 2 e 12: ");
            scanf("%d", &resultado);

            if (resultado < 2 || resultado > 12)
            {
                printf("\nInforme um valor valido\n");
            }

        } while (resultado < 2 || resultado > 12);

        for (dado1 = 1; dado1 <= 6; dado1++)
        {
            for (dado2 = 1; dado2 <= 6; dado2++)
            {
                controle = dado1 + dado2;

                if (controle == resultado)
                {
                    printf("%d + %d = %d\n", dado1, dado2, resultado);
                    possibilidades++;
                }
            }
        }

        printf("\nNumero de possibilidades: %d\n", possibilidades);

        printf("\nDeseja informar outro valor (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
