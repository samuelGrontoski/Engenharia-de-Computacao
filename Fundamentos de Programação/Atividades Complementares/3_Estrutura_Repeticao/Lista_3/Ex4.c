/* 4) Escreva um programa que leia o valor de uma aplicação, o percentual de rendimento mensal obtido por
esta aplicação e o período do investimento; e retorne o valor da aplicação ao final do período de investimento.
Obs.: A cada 12 meses o percentual de rendimento deve ser aumentado em 0,25%. Validar o valor da
aplicação para que seja positivo. Validar o percentual de rendimento para que seja um número entre 0 e 1.
Validar o período para que seja um valor positivo. */

#include <stdio.h>

int main(void)
{
    float aplicacao, rendimentoMensal;
    int periodo, mes;
    char opcao;

    do
    {
        do //validação do valor de aplicação
        {
            printf ("\nInforme o valor da aplicacao: R$");
            scanf ("%f", &aplicacao);

            if (aplicacao < 0)
            {
                printf ("\nInforme um valor positivo\n");
            }
        } while (aplicacao <= 0);
        
        do //validação do valor do rendimento mensal
        {
            printf ("\nInforme o percentual de rendimento mensal (10%% = 0.1): ");
            scanf ("%f", &rendimentoMensal);

            if (rendimentoMensal < 0 && rendimentoMensal > 1)
            {
                printf ("\nInforme um valor entre 0 e 1\n");
            }
        } while (rendimentoMensal < 0 && rendimentoMensal > 1);

        do //validação do período
        {
            printf ("\nInforme o periodo (em meses): ");
            scanf ("%d", &periodo);

            if (periodo <= 0)
            {
                printf ("\nInforme um valor positivo\n");
            }
        } while (periodo <= 0);
        
        printf ("MES\t%% DE RENDIMENTO\t\tVALOR APLICACAO\n");

        for (mes = 1; mes < periodo+1; mes++)
        {
            if (mes < 12)
            {
                aplicacao = aplicacao + (aplicacao * rendimentoMensal);
                printf ("%d\t%.2f\t\t\tR$%.2f\n", mes, rendimentoMensal, aplicacao);
            }
            if (mes >= 12)
            {
                aplicacao = aplicacao + (aplicacao * (rendimentoMensal + 0.25));
                printf ("%d\t%.2f\t\t\tR$%.2f\n", mes, rendimentoMensal + 0.25, aplicacao);
            }
            
            
        }
        
        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');
    
    return 0;
}