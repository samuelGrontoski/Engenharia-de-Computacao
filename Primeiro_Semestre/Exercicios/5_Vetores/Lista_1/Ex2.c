#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    char opcao;
    int tamanho = 15, limInf = 1, limSup = 25, i, countPar, countImpar, indicePar, indiceImpar;
    int vetor[tamanho];

    do
    {
        printf("\n=== VETOR ===\n");
        gerarVetorInteiroDe1a25(vetor, tamanho, limSup);
        mostrarVetorInteiros (vetor, tamanho);

        countPar = 0;
        countImpar = 0;
        for (i = 0; i < tamanho; i++)
        {
            if (vetor[i] % 2 == 0)
            {
                countPar++;
            }
            else
            {
                countImpar++;
            } 
        }
        int pares[countPar], impares[countImpar];

        indicePar = 0;
        indiceImpar = 0;
        for (i = 0; i < tamanho; i++)
        {
            if (vetor[i] % 2 == 0)
            {
                pares[indicePar] = vetor[i];
                indicePar++;
            }
            else
            {
                impares[indiceImpar] = vetor[i];
                indiceImpar++;
            } 
        }

        printf ("\n=== VETOR DE PARES ===\n");
        for (i = 0; i < countPar; i++)
        {
                printf ("%d\t", pares[i]);
        }

        printf ("\n=== VETOR DE IMPARES ===\n");
        for (i = 0; i < countImpar; i++)
        {
                printf ("%d\t", impares[i]);
        }
        
        printf("\nDeseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}