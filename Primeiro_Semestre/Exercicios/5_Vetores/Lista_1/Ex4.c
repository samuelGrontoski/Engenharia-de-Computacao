#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int main (void)
{
    setlocale (LC_ALL,"PORTUGUESE");

    char opcao;
    int tamanho, i;

    do
    {
        do
        {
            printf ("\nInforme o tamanho dos vetores A e B: ");
            scanf ("%d", &tamanho);
        } while (tamanho <= 0);
        int vetorA[tamanho];
        int vetorB[tamanho];
        int vetorC[tamanho];

        printf("\n=== VETOR A ===\n");
        gerarVetorInteiroDe1a20(vetorA, tamanho, 20);
        mostrarVetorInteiros(vetorA, tamanho);

        printf("\n\n=== VETOR B ===\n");
        gerarVetorInteiroDe1a15(vetorB, tamanho, 15);
        mostrarVetorInteiros(vetorB, tamanho);

        for (i = 0; i < tamanho; i++)
        {
            if (vetorA[i] > vetorB[i])
            {
                vetorC[i] = 1;
            }
            if (vetorA[i] == vetorB[i])
            {
                vetorC[i] = 0;
            }
            if (vetorA[i] < vetorB[i])
            {
                vetorC[i] = -1;
            }
        }
        
        printf("\n\n=== VETOR C ===\n");
        mostrarVetorInteiros(vetorC, tamanho);

        printf("\n\nDeseja repetir o programa (S/s): ");
        setbuf(stdin,NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}