#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
#include "divisores.h"

int main (void)
{
    setlocale(LC_ALL,"PORTUGUESE");

    char opcao;
    int tamanho = 20, vetorA[tamanho], vetorB[tamanho];

    do
    {
        printf("\n==== VETOR ORIGINAL ====\n");
        gerarVetorInteiroComFaixa(vetorA, tamanho);
        mostrarVetorInteiro(vetorA, tamanho);

        printf("\n==== VETOR ORDENADO ====\n");
        ordenarVetorInteiro(vetorB, tamanho);
        mostrarVetorInteiro(vetorB, tamanho);

        printf("\n===== DIVISORES ====\n");
        mostrarDivisores(vetorB, tamanho);

        printf("\n\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin,NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}