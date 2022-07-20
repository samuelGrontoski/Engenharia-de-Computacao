/*3) Ler uma string e armazenar em um vetor o valor decimal ASCII apenas dos caracteres que fazem parte do
alfabeto. Mostrar o vetor. Ordenar o vetor. Mostrar o vetor ordenado. Em uma segunda string, armazenar os
caracteres ordenados do vetor e mostrar a string*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void mostrarVetorInteiro(int vetor[], int tamanho);
void ordenarVetor(int vetor[], int tamanho);

int main(void)
{
    char opcao, string1[100];
    int i, j, countString, countVetor;

    do
    {
        printf("\nInforme uma string: ");
        setbuf(stdin, NULL);
        gets(string1);

        i = 0;
        countString = 0;
        countVetor = 0;
        while (string1[i] != '\0') // conta o tamanho da string e do vetor
        {
            countString++;
            if (string1[i] != ' ')
            {
                countVetor++;
            }
            i++;
        }

        int vetorLetras[countVetor];
        j = 0;
        for (i = 0; i < countString; i++) // adiciona os caracteres (sem o espaço) a um vetor
        {
            if (string1[i] != ' ')
            {
                vetorLetras[j] = string1[i];
                j++;
            }
        }

        printf("\nString 1: ");
        for (i = 0; i < countString; i++)
        {
            printf("%c", string1[i]);
        }
        printf("\n");

        printf("\n== VETOR LETRAS ==\n");
        mostrarVetorInteiro(vetorLetras, countVetor);
        printf("\n");

        printf("\n== VETOR LETRAS ORDENADO ==\n");
        ordenarVetor(vetorLetras, countVetor);
        mostrarVetorInteiro(vetorLetras, countVetor);
        printf("\n");

        char string2[countVetor];
        for (i = 0; i < countVetor; i++)
        {
            string2[i] = vetorLetras[i];
        }
        
        printf("\nString 2: ");
        for (i = 0; i < countVetor; i++)
        {
            printf("%c", string2[i]);
        }
        
        printf("\n\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}

void mostrarVetorInteiro(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%2d\t", vetor[i]);
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