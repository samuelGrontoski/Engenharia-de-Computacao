/*2) Uma empresa deseja calcular a depreciação de seus bens. Para tanto, desenvolver um programa que
obtenha a taxa de depreciação anual para os bens, o valor do bem a ser depreciado e o período em anos.
Valor depreciado = valor do bem * (taxa de depreciação / 100)
Valor do bem depreciado = valor do bem ? valor depreciado
Considere que a taxa de depreciação tem valor fixo de 1.5.*/

#include <stdio.h>
#include <locale.h>

int main (void)
{
    float valorBem,valorDepre, depre, depreAcum;
    int anos, i;

    setlocale (LC_ALL, "PORTUGUESE");

    do
    {
        printf ("\nInforme o valor do bem a ser depreciado: R$ ");
        scanf ("%f", &valorBem);

        if (valorBem <= 0)
        {
            printf ("\nValor inválido\n");
        }
        
    } while (valorBem <= 0);

    do
    {
        printf ("\nInforme o período da depreciação (em anos): ");
        scanf ("%d", &anos);

        if (depre <= 0)
        {
            printf ("\nValor inválido\n");
        }
        
    } while (anos <= 0);
    
    printf ("\n\nAno\t Valor do Bem\t Depreciação\t Valor Depreciado");
    printf ("\n==========================================================");

    depreAcum = 0;
    
    for (i = 1; i <= anos; i++)
    {
        depre = valorBem * (1.5/100);
        valorDepre = valorBem - depre;

        printf ("\n%d\t R$ %.2f\t R$ %.2f\t R$%.2f", i, valorBem, depre, valorDepre);

        valorBem = valorDepre;
         depreAcum = depreAcum + depre;
    }

    printf ("\n==========================================================");
    printf ("\nDepreciação acumulada: R$ %.2f", depreAcum);
    
    return 0;
}