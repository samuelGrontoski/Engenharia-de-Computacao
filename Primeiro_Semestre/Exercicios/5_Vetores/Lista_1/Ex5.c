#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int main(void)
{
    setlocale (LC_ALL,"PORTUGUESE");

    char opcao;
    int tamanhoA = 100, tamanhoB = 0, vetorA[tamanhoA], vetorB[tamanhoB], i,countZeros;

    do
    {
        printf("\n=== VETOR A ===\n");
        gerarVetorInteiroDe0a1(vetorA, tamanhoA, 1);
        mostrarVetorInteiros(vetorA, tamanhoA);

        countZeros = 0;
        tamanhoB = 0;
        for (i = 0; i < tamanhoA; i++)
        {
            if (vetorA[i] == 0)
            {
                countZeros++;
            }
            if (vetorA[i] == 1 || i == 99)
            {
                vetorB[tamanhoB] = countZeros;
                countZeros = 0;
                tamanhoB++;
            }     
        }

        printf("\n\n=== VETOR B ===\n");
        mostrarVetorInteiroDosZeros(vetorB, tamanhoB);

        printf("\n\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}