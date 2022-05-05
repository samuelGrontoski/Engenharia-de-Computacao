/*2) Faça um programa que apresente o menu a seguir e permita ao usuário escolher a opção desejada,
receba os dados necessários para executar a operação e mostre o resultado.*/

#include <stdio.h>

int main(void)
{
    int opcao, a, b, c;

    printf("\nMenu de opcoes:\n1 - Mostra os numeros em ordem crescente\n2 - Mostra os numeros em ordem decrescente\n3 - Mostra os numeros que sao multiplos de 2\n");
    printf("\nDigite a opcao desejada: \n");
    scanf("%d", &opcao);

    if (opcao == 1 || opcao == 2 || opcao == 3)
    {
        printf("\nInforme um valor para a: ");
        scanf("%d", &a);
        printf("\nInforme um valor para b: ");
        scanf("%d", &b);
        printf("\nInforme um valor para c: ");
        scanf("%d", &c);

        // ordem crescente
        if (opcao == 1)
        {
            // a sendo o menor
            if (a < b && a < c)
            {
                printf("\nVoce informou os numeros: %d", a);
                if (b < c)
                {
                    printf(", %d", b);
                    printf(" e %d", c);
                }
                if (c < b)
                {
                    printf(", %d", c);
                    printf(" e %d", b);
                }
            }
            // b sendo o menor
            if (b < a && b < c)
            {
                printf("\nVoce informou os numeros: %d", b);
                if (a < c)
                {
                    printf(", %d", a);
                    printf(" e %d", c);
                }
                if (c < a)
                {
                    printf(", %d", c);
                    printf(" e %d", a);
                }
            }
            // c sendo o menor
            if (c < b && c < a)
            {
                printf("\nVoce informou os numeros: %d", c);
                if (a < b)
                {
                    printf(", %d", a);
                    printf(" e %d", b);
                }
                if (b < a)
                {
                    printf(", %d", b);
                    printf(" e %d", a);
                }
            }
        }

        // ordem decrescente
        if (opcao == 2)
        {
            // a sendo o maior
            if (a > b && a > c)
            {
                printf("\nVoce informou os numeros: %d", a);
                if (b > c)
                {
                    printf(", %d", b);
                    printf(" e %d", c);
                }
                if (c > b)
                {
                    printf(", %d", c);
                    printf(" e %d", b);
                }
            }
            // b sendo o maior
            if (b > a && b > c)
            {
                printf("\nVoce informou os numeros: %d", b);
                if (a > c)
                {
                    printf(", %d", a);
                    printf(" e %d", c);
                }
                if (c > a)
                {
                    printf(", %d", c);
                    printf(" e %d", a);
                }
            }
            // c sendo o maior
            if (c > b && c > a)
            {
                printf("\nVoce informou os numeros: %d", c);
                if (a > b)
                {
                    printf(", %d", a);
                    printf(" e %d", b);
                }
                if (b > a)
                {
                    printf(", %d", b);
                    printf(" e %d", a);
                }
            }
        }

        // multiplos de 2
        if (opcao == 3)
        {
            if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
            {
                    // a sendo o menor
                    if (a < b && a < c)
                {
                    printf("\nOs numeros %d", a);
                    if (b < c)
                    {
                        printf(", %d", b);
                        printf(" e %d", c);
                    }
                    if (c < b)
                    {
                        printf(", %d", c);
                        printf(" e %d sao multiplos de 2", b);
                    }
                }
                // b sendo o menor
                if (b < a && b < c)
                {
                    printf("\nOs numeros %d", b);
                    if (a < c)
                    {
                        printf(", %d", a);
                        printf(" e %d", c);
                    }
                    if (c < a)
                    {
                        printf(", %d", c);
                        printf(" e %d sao multiplos de 2", a);
                    }
                }
                // c sendo o menor
                if (c < b && c < a)
                {
                    printf("\nOs numero %d", c);
                    if (a < b)
                    {
                        printf(", %d", a);
                        printf(" e %d", b);
                    }
                    if (b < a)
                    {
                        printf(", %d", b);
                        printf(" e %d sao multiplos de 2", a);
                    }
                }
            }
            // a e b multiplos de 2
            if (a % 2 == 0 && b % 2 == 0 && c % 2 != 0)
            {
                    // a sendo o menor
                    if (a < b)
                {
                    printf("\nApenas os numeros %d e %d sao multiplos de 2", a, b);
                }
                // b sendo o menor
                if (b < a)
                {
                    printf("\nApenas os numeros %d e %d sao multiplos de 2", b, a);
                }
            }
            // a e c multiplos de 2
            if (a % 2 == 0 && b % 2 != 0 && c % 2 == 0)
            {
                    // a sendo o menor
                    if (a < c)
                {
                    printf("\nApenas os numeros %d e %d sao multiplos de 2", a, c);
                }
                // b sendo o menor
                if (c < a)
                {
                    printf("\nApenas os numeros %d e %d sao multiplos de 2", c, a);
                }
            }
            // b e c multiplos de 2
            if (a % 2 != 0 && b % 2 == 0 && c % 2 == 0)
            {
                    // a sendo o menor
                    if (b < c)
                {
                    printf("\nApenas os numeros %d e %d sao multiplos de 2", b, c);
                }
                // b sendo o menor
                if (c < b)
                {
                    printf("\nApenas os numeros %d e %d sao multiplos de 2", c, b);
                }
            }
            // a multiplo de 2
            if (a % 2 == 0 && b % 2 != 0 && c % 2 != 0)
            {
                printf ("\nApenas o numero %d eh multiplo de 2", a);
            }
            // b multiplo de 2
            if (a % 2 != 0 && b % 2 == 0 && c % 2 != 0)
            {
                printf ("\nApenas o numero %d eh multiplo de 2", b);
            }
            // c multiplo de 2
            if (a % 2 != 0 && b % 2 != 0 && c % 2 == 0)
            {
                printf ("\nApenas o numero %d eh multiplo de 2", c);
            }
            // nenhum multiplo
            if (a % 2 != 0 && b % 2 != 0 && c % 2 != 0)
            {
                printf ("Nenhum numero eh multiplo de 2");
            }
        }
    }
    else
    {
        printf("\nOpcao invalida\n");
    }
    return 0;
}