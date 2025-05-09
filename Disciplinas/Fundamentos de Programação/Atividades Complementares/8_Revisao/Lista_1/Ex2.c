/* 2) Ler uma string e criar uma função que receba a string e retorne quantas palavras a mesma possui. Criar
uma segunda função para contar quantas letras têm em cada palavra da string, armazenando essa contagem
em um vetor passado por parâmetro para a função (esse vetor terá como tamanho o número de palavras da
string). Na sequência, ordenar o vetor e mostrar o vetor. Construir uma matriz de n linhas e duas colunas,
sendo que n representa a quantidade de elementos do vetor (se o elemento ocorrer mais de uma vez,
considerar apenas uma ocorrência). Na segunda coluna da matriz armazenar a quantidade de divisores que o
elemento possui será armazenada. Percorrer a matriz mostrando os elementos das colunas 0 e 1 e
escrevendo ?Sim? quando o elemento que está na coluna 0 for primo e ?Não? caso contrário*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void mostrarVetorInteiro(int vetor[], int tamanho);
void ordenarVetorInteiro(int vetor[], int tamanho);
int divisores(int vetor[], int tamanho, int num);

int main (void)
{
    setlocale(LC_ALL,"PORTUGUESE");
    
    char opcao, string[100];
    int i, j, countPalavras, countLetras;

    do
    {
        printf("Informe uma string: ");
        setbuf(stdin, NULL);
        gets(string);

        // conta as palavras da string
        i = 0;
        countPalavras = 0;
        while (string[i] != '\0')
        {
            if (string[i] != ' ')
            {
                if (string[i+1] == ' ' || string[i+1] == '\0')
                {
                    countPalavras++;
                }
            }
            i++;
        }
        printf("\nA string tem %d palavras.", countPalavras);

        // conta as letras de cada palavra
        int vetorLetras[countPalavras];

        i = 0;
        j = 0;
        countLetras = 0;
        while (string[i] != '\0')
        {
            if (string[i] != ' ')
            {
                countLetras++;
                if (string[i+1] == ' ' || string[i+1] == '\0')
                {
                    vetorLetras[j] = countLetras;
                    countLetras = 0;
                    j++;
                }
            }
            i++;
        }
        
        printf("\n\n==== VETOR ====\n");
        mostrarVetorInteiro(vetorLetras, countPalavras);

        printf("\n\n==== VETOR ORDENADO ====\n");
        ordenarVetorInteiro(vetorLetras, countPalavras);
        mostrarVetorInteiro(vetorLetras, countPalavras);

        countLetras = 0;

        // define o tamanho da matriz
        for (i = 0; i < countPalavras; i++)
        {
            if (i == 0 || vetorLetras[i] != vetorLetras[i-1])
            {
                countLetras++;
            }
        }

        int matriz[countLetras][2];

        // constroi a matriz
        j = 0;
        for (i = 0; i < countPalavras; i++)
        {
            if (i == 0 || vetorLetras[i] != vetorLetras[i-1])
            {
                matriz[j][0] = vetorLetras[i];
                matriz[j][1] = divisores(vetorLetras, countPalavras, vetorLetras[i]);
                j++;
            }
        }
        
        printf("\n\n==== MATRIZ ====\n");
        printf("VALOR\tQTDE DIVISORES\tPRIMO\n");
        for (i = 0; i < j; i++)
        {
            printf("%d\t%d\t", matriz[i][0], matriz[i][1]);
            if (matriz[i][1] == 2)
            {
                printf("SIM\n");
            }
            else
            {
                printf("NÃO\n");
            }
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

int divisores(int vetor[], int tamanho, int num)
{
    int i, j, count=0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 1; j <= num; j++)
        {
            if (num % j == 0)
            {
                count++;
            }
        }
        return (count);
        count = 0;
    }
}