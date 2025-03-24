#include <stdio.h>
#include <locale.h>
#include "Minhas_funcoes.h"

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int num, resultado;

    do
    {
        printf("\nInforme um n�mero entre 0 e 12: ");
        scanf("%d", &num);

        if (num<0 || num >12)
        {
            printf ("\nValor inv�lido\n");
        }
        
    } while (num<0 || num >12); 

    resultado = calculaFat (num);
    printf ("Fatorial de %d: %d\n", num, resultado);

    mostraFat (num, resultado);
    
    return 0;
}