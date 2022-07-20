/* Questão 4 (3,2 pontos) - Gerar um vetor com 10 números aleatórios inteiros. Exibir o vetor. Gerar um novo vetor com os dados do primeiro na
seguinte ordem: o primeiro número do vetor deve ser trocado com o último, o segundo número deve ser trocado com o penúltimo e assim
sucessivamente até realizar a troca de todos os valores atendendo a essa lógica. Exibir o novo vetor. Ordenar o novo vetor. Gerar um terceiro
vetor com os elementos do segundo, sem repetição */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(int vetor[], int tamanho);
void mostraVetor(int vetor[], int tamanho);

int main (void)
{
    char opcao;
    int i, j, vetor[10], vetorAux[10], count;

    do
    {
        printf("\n==== VETOR ====\n");
        gerarVetor(vetor, 10);
        mostraVetor(vetor, 10);
        printf("\n");

        j = 9;
        for (i = 0; i < 10; i++)
        {
            vetorAux[j] = vetor[i];
            j--;
        }
        printf("\n==== VETOR COM ELEMENTOS TROCADOS ====\n");
        mostraVetor(vetorAux, 10);
        printf("\n");

        printf("\n==== VETOR ORDENADO ====\n");
        ordenarVetor(vetorAux, 10);
        mostraVetor(vetorAux, 10);
        printf("\n");

        count = 0;
        for (i = 0; i < 10; i++)
        {
            if (i == 0 || vetorAux[i] != vetorAux[i+1])
            {
                count++;
            }
        }
        
        int vetorSemRep[count];
        j = 0;
        for (i = 0; i < 10; i++)
        {
            if (vetorAux[i] != vetorAux[i+1])
            {
                vetorSemRep[j] = vetorAux[i];
                j++;
            }
        }
        printf("\n==== VETOR SEM REPETIDOS ====\n");
        mostraVetor(vetorSemRep, count);
        printf("\n");

        printf("\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}

void gerarVetor(int vetor[], int tamanho)
{
    int i, limInf = 0, limSup = 10, vetorB[tamanho];

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = (rand() % ((limSup - limInf) + 1)) + limInf;
    }
}

void mostraVetor(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%d\t", vetor[i]);
    }
}

void ordenarVetor(int vetor[], int tamanho)
{
    int i, i2, auxiliar;

    for (i2 = tamanho - 1; i2 > 0; i2--)
    {
        for (i = 0; i < i2; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;
            }
        }
    }
}