/* Questão 3 (3,2 pontos) ? Ler uma string e copiar para uma nova string somente os caracteres em que o valor decimal ASCII é um número
primo. A verificação se o caractere decimal ASCII é ou não um número primo deve ser feito via função. O programa também deve copiar o
valor decimal ASCII primo para um vetor de inteiros. Mostrar a nova string e o vetor. Ordenar o vetor. Mostrar o vetor ordenado. Construir uma
matriz de n linhas e duas colunas, sendo que n representa a quantidade de elementos do vetor (se o elemento ocorrer mais de uma vez,
considerar apenas uma ocorrência). Na segunda coluna da matriz armazenar a quantidade de repetições de cada elemento no vetor. Mostrar a
matriz*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int primos(int num);
void mostraVetor(int vetor[], int tamanho);
void ordenarVetor(int vetor[], int tamanho);
int ocorreNoVetor(int vetor[], int tamanho, int num);

int main(void)
{
    char opcao, string[100];
    int i, j, countString, countPrimos, count;

    do
    {
        printf("\nInforme a string: ");
        setbuf(stdin, NULL);
        gets(string);

        i = 0;
        countString = 0;
        while (string[i] != '\0')
        {
            countString++;
            i++;
        }

        int matriz[countString][2];
        countPrimos = 0;
        for (i = 0; i < countString; i++)
        {
            matriz[i][0] = string[i];
            matriz[i][1] = primos(string[i]);
            if (matriz[i][1] == 0)
            {
                countPrimos++;
            }
        }

        j = 0;
        int vPrimos[countPrimos];
        for (i = 0; i < countString; i++)
        {
            if (matriz[i][1] == 0)
            {
                vPrimos[j] = matriz[i][0];
                j++;
            }
        }

        printf("\n=== VETOR ===\n");
        mostraVetor(vPrimos, countPrimos);
        printf("\n");

        printf("\n=== VETOR ORDENADO ===\n");
        ordenarVetor(vPrimos, countPrimos);
        mostraVetor(vPrimos, countPrimos);
        printf("\n");

        count = 0;
        for (i = 0; i < countPrimos; i++)
        {
            if (i == 0 || vPrimos[i] != vPrimos[i - 1])
            {
                count++;
            }
        }

        int matriz2[count][2];
        j = 0;
        for (i = 0; i < countPrimos; i++)
        {
            if (vPrimos[i] != vPrimos[i + 1])
            {
                matriz2[j][0] = vPrimos[i];
                matriz2[j][1] = ocorreNoVetor(vPrimos, countPrimos, vPrimos[i]);
                j++;
            }
        }

        printf("\n=== MATRIZ ===\n");
        for (i = 0; i < count; i++)
        {
            printf("%d\t%d\n", matriz2[i][0], matriz2[i][1]);
        }
        printf("\n");

        printf("\nDeseja repetir o programa (S ou N)?");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
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

int primos(int num)
{
    int i, count = 0;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            count++;
            break;
        }
    }
    return (count);
}