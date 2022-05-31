#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int i, limite, tamanho, somaPares, count, menor, indice;
    float media;
    char opcao;

    do
    {
        do
        {
            printf("\nInforme o tamanho do vetor: ");
            scanf("%d", &tamanho);

            if (tamanho <= 0)
            {
                printf("\nValor inv�lido!\n");
            }
        } while (tamanho <= 0);

        int vetor[tamanho];

        do
        {
            printf("\nInforme o valor do limite: ");
            scanf("%d", &limite);

            if (limite <= 0)
            {
                printf("\nValor inv�lido!\n");
            }
        } while (limite <= 0);

        gerarVetorInteiroDe0aLimite(vetor, tamanho, limite);

        printf ("=== VETOR GERADO ===\n");

        mostrarVetorInteiros(vetor, tamanho);

        printf ("\n");

        somaPares = 0;
        count = 0;
        menor = vetor[0];
        indice = 0;

        for (i = 0; i < tamanho; i++)
        {
            if (vetor[i] % 2 == 0)
            {
                somaPares = somaPares + vetor[i];
                count++;
            }
            if (vetor[i] < menor)
            {
                menor = vetor[i];
                indice = i;
            }
        }

        printf ("\nO menor valor � %d e est� no �ndice %d\n", menor, indice);
        
        if (count == 0)
        {
            printf ("\nN�o foram encontrados n�meros pares.\n");
        }
        else
        {
            media = (float)somaPares / count;
            printf ("\nM�dia dos pares: %.2f\n", media);
        }
        
        printf("Deseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}