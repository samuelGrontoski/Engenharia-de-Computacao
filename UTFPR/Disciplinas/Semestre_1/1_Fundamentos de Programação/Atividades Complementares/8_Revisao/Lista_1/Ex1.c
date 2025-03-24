/*1) Ler uma string e contar os espaços em branco que ocorrem no início, entre as palavras e no final da string,
e armazenar a contagem em um vetor. Mostrar o vetor. Ordenar o vetor. Mostrar o vetor ordenado. Construir
uma matriz de n linhas e duas colunas, sendo que n representa a quantidade de elementos do vetor (se o
elemento ocorrer mais de uma vez, considerar apenas uma ocorrência). Na segunda coluna da matriz
armazenar a quantidade de repetições de cada elemento no vetor. Mostrar a matriz.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void mostrarVetorInteiro(int vetor[], int tamanho);
void ordenarVetorInteiro(int vetor[], int tamanho);
int ocorreNoVetor(int vetor[], int tamanho, int num);

int main(void)
{
    char opcao, string[100];
    int tamanhoA = 0, vetorA[tamanhoA], i, countEsp, k;

    do
    {
        printf ("Informe uma frase: ");
        setbuf (stdin, NULL);
        gets(string);

        countEsp = 0;
        tamanhoA = 0;
        i = 0;
        while (string[i] != '\0')
        {
            if (string[i] == ' ') 
            {
                countEsp++;
                if (string[i+1] == '\0')
                {
                    vetorA[tamanhoA] = countEsp;
                    tamanhoA++;
                }
            }
            else
            {
                if (countEsp > 0)
                {
                    vetorA[tamanhoA] = countEsp;
                    tamanhoA++;
                    countEsp = 0;
                }
            }
            i++;
        }
        
        printf("\n\n==== VETOR ====\n");
        mostrarVetorInteiro(vetorA, tamanhoA);

        printf("\n\n==== VETOR ORDENADO ====\n");
        ordenarVetorInteiro(vetorA, tamanhoA);
        mostrarVetorInteiro(vetorA, tamanhoA);

        countEsp = 0;

        for (i = 0; i < tamanhoA; i++)
        {
            if (i == 0 || vetorA[i] != vetorA[i-1])
            {
                countEsp++;
            }
        }

        int matriz[countEsp][2];

        k = 0;
        for (i = 0; i < tamanhoA; i++)
        {
            if (i == 0 || vetorA[i] != vetorA[i-1])
            {
                matriz[k][0] = vetorA[i];
                matriz[k][1] = ocorreNoVetor(vetorA, tamanhoA, vetorA[i]);
                k++;
            }
        }
        
        printf("\n\n==== MATRIZ ====\n");
        for (i = 0; i < k; i++)
        {
            printf("%d\t%d\n", matriz[i][0], matriz[i][1]);
        }
        
        printf ("\nDeseja repetir o programa (S ou N)? ");
        setbuf (stdin, NULL);
        scanf ("%c", &opcao);
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
    int i, count=0;

    for(i=0; i<tamanho; i++)
    {
        if(vetor[i] == num)
        {
            count++;
        }
    }
    return(count);
}