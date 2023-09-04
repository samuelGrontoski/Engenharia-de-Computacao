/* Questão 2 (3,2 pontos) - Gerar dois vetores com 5 elementos cada, os elementos devem ser distintos (não repetidos). Os valores para o
vetor devem ser gerados de forma aleatória entre 1 e 15 para o primeiro vetor e entre 1 e 10 para o segundo vetor. Gerar um terceiro vetor
cujos valores será o resultado da interseção dos elementos dos dois primeiros vetores. Gerar também um quarto vetor que terá como valores
o resultado da união dos elementos dos dois primeiros vetores. Utilizar o conceito matemático de interseção e união entre conjuntos. Mostrar
os quatro vetores */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetorSemRepeticao(int vetor[], int tamanho, int limite);
void mostraVetor(int vetor[], int tamanho);
void ordenarVetor(int vetor[], int tamanho);

int main(void)
{
    char opcao;
    int i, j, k, vetor1[5], vetor2[5], vetor3[10], countInt, countSemRep;

    do
    {
        printf("\n==== VETOR 1 ====\n");
        gerarVetorSemRepeticao(vetor1, 5, 15);
        mostraVetor(vetor1, 5);
        printf("\n");

        printf("\n==== VETOR 2 ====\n");
        gerarVetorSemRepeticao(vetor2, 5, 10);
        mostraVetor(vetor2, 5);
        printf("\n");

        countInt = 0;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (vetor1[i] == vetor2[j])
                {
                    countInt++;
                }
            }
        }

        int vetorInt[countInt];
        k = 0;
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (vetor1[i] == vetor2[j])
                {
                    vetorInt[k] = vetor2[j];
                    k++;
                }
            }
        }

        printf("\n==== INTERSECAO ====\n");
        mostraVetor(vetorInt, countInt);
        printf("\n");

        k = 0;
        for (i = 0; i < 10; i++)
        {
            if (i < 5)
            {
                vetor3[k] = vetor1[i];
                k++;
            }
            else
            {
                vetor3[k] = vetor2[i-5];
                k++;
            }
        }
        ordenarVetor(vetor3, 10);
        countSemRep = 0;
        for (i = 0; i < 10; i++)
        {
            if (i == 0 || vetor3[i] != vetor3[i+1])
            {
                countSemRep++;
            }
        }

        int vetorUniao[countSemRep];
        j = 0;
        for (i = 0; i <= 10; i++)
        {
            if (vetor3[i] != vetor3[i+1])
            {
                vetorUniao[j] = vetor3[i];
                j++;
            }
        }
        
        printf("\n==== UNIAO ====\n");
        mostraVetor(vetorUniao, countSemRep);
        printf("\n");

        printf("\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}

void gerarVetorSemRepeticao(int vetor[], int tamanho, int limite)
{
    int i, j, limInf = 1, limSup = limite;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % ((limSup - limInf) + 1) + limInf;
        for (j = 0; j < i; j++)
        {
            if (vetor[j] == vetor[i])
            {
                i--;
                break;
            }
        }
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