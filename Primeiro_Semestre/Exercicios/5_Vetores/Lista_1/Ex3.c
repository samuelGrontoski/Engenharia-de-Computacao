#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int main (void)
{
    setlocale (LC_ALL,"PORTUGUESE");

    char opcao;
    int tamanho = 10, limInf = 1, vetorA[tamanho], vetorB[tamanho], limSup = 10, i, i2;

    do
    {
        printf("\n=== VETOR A ===\n");
        gerarVetorInteiroDe1a10(vetorA, tamanho, limSup);
        mostrarVetorInteiros(vetorA, tamanho);

        i2 = 9;
        for (i = 0; i < tamanho; i++)
        {
            vetorB[i2] = vetorA[i];
            i2--;
        }
        
        printf("\n=== VETOR B ===\n");
        mostrarVetorInteiros(vetorB, tamanho);

        printf("\nDeseja repetir o programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}