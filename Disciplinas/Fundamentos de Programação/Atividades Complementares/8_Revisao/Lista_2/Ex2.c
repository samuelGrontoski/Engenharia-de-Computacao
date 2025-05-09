/* 2) Ler uma string e copiar o valor decimal do código ASCII de cada elemento da string para um vetor. Mostrar
o vetor. Ordenar o vetor. Mostrar o vetor ordenado. Percorrer o vetor ordenado contando, sem repetição, os
números pares e os números ímpares e mostrar a soma total desses valores. Criar um vetor chamado vPares
e um vetor chamado vImpares e copiar, sem repetição, os elementos pares e ímpares para os respectivos
vetores. Mostrar os dois vetores. Criar uma matriz chamada mPares e uma matriz chamada mImpares, sendo
que mPares deverá conter na primeira coluna todos os elementos pares do vetor e na segunda coluna a
quantidade de ocorrências de cada elemento par no vetor e na matriz mImpares fazer o mesmo com os
elementos ímpares. Mostrar as duas matrizes. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void mostrarVetorInteiro(int vetor[], int tamanho);
void ordenarVetorInteiro(int vetor[], int tamanho);
int ocorreNoVetor(int vetor[], int tamanho, int num);

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    char opcao, string[100];
    int tamanho, i, j, count, countPar, countImpar;

    do
    {
        printf("Informe uma string: ");
        setbuf(stdin, NULL);
        gets(string);

        i = 0;
        count = 0;
        while (string[i] != '\0') // conta o tamanho da string
        {
            count++;
            i++;
        }

        tamanho = count;
        int vetor[tamanho];

        for (i = 0; i < tamanho; i++) // coloca o valor ASCII do caracter em um vetor
        {
            vetor[i] = string[i];
        }

        printf("\n== VETOR ==\n");
        mostrarVetorInteiro(vetor, tamanho);

        printf("\n\n== VETOR ORDENADO==\n");
        ordenarVetorInteiro(vetor, tamanho);
        mostrarVetorInteiro(vetor, tamanho);

        countPar = 0;
        countImpar = 0;
        for (i = 0; i < tamanho; i++) // conta os pares e impares
        {
            if (vetor[i] % 2 == 0)
            {
                if (vetor[i] != vetor[i - 1])
                {
                    countPar++;
                }
            }
            else
            {
                if (vetor[i] != vetor[i - 1])
                {
                    countImpar++;
                }
            }
        }
        printf("\n\nNúmero de pares (sem repetição): %d", countPar);
        printf("\nNúmero de ímpares (sem repetição): %d", countImpar);

        int vPares[countPar], vImpares[countImpar];
        j = 0;
        for (i = 0; i < tamanho; i++) // separa no vetor par
        {
            if (vetor[i] % 2 == 0)
            {
                if (i == 0 || vetor[i] != vetor[i - 1])
                {
                    vPares[j] = vetor[i];
                    j++;
                }
            }
        }
        j = 0;
        for (i = 0; i < tamanho; i++) // separa no vetor impar
        {
            if (vetor[i] % 2 != 0)
            {
                if (i == 0 || vetor[i] != vetor[i - 1])
                {
                    vImpares[j] = vetor[i];
                    j++;
                }
            }
        }

        printf("\n\n== VETOR PAR ==\n");
        mostrarVetorInteiro(vPares, countPar);

        printf("\n\n== VETOR IMPAR ==\n");
        mostrarVetorInteiro(vImpares, countImpar);

        int mPares[countPar][2], mImpares[countImpar][2];

        j = 0;
        for (i = 0; i < countPar; i++) // monta e mostra a matriz dos pares
        {
            mPares[j][0] = vPares[j];
            mPares[j][1] = ocorreNoVetor(vetor, tamanho, vPares[j]);
            j++;
        }
        printf("\n\n== MATRIZ DE PARES ==\n");
        for (i = 0; i < j; i++)
        {
            printf("%d\t%d\n", mPares[i][0], mPares[i][1]);
        }

        j = 0;
        for (i = 0; i < countImpar; i++) // monta e mostra a matris dos impares
        {
            mImpares[j][0] = vImpares[j];
            mImpares[j][1] = ocorreNoVetor(vetor, tamanho, vImpares[j]);
            j++;
        }
        printf("\n\n== MATRIZ DE IMPARES ==\n");
        for (i = 0; i < j; i++)
        {
            printf("%d\t%d\n", mImpares[i][0], mImpares[i][1]);
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

void ordenarVetorInteiro(int vetor[], int tamanho)
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

int ocorreNoVetor(int vetor[], int tamanho, int num)
{
    int i, count = 0;

    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] == num)
        {
            count++;
        }
    }
    return (count);
}