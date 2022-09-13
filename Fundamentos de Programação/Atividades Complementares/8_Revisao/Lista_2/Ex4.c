/* 4) Ler uma string e contar os espaços em branco (sucessivos ou não) e armazenar a contagem em um vetor.
Mostrar o vetor. Percorrer o vetor copiando apenas os números que são primos para um novo vetor. Mostrar
o novo vetor (de números primos). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char opcao, string[100];
    int i, j, countString, countEsp, countDiv, countPrimos, tamanho = 0, vetor[tamanho];

    do
    {
        printf("\nInforme uma string: ");
        setbuf(stdin, NULL);
        gets(string);

        i = 0;
        countString = 0;
        while (string[i] != '\0') // conta o tamanho da string
        {
            countString++;
            i++;
        }

        printf("\n==== STRING ====\n");
        for (i = 0; i < countString; i++)
        {
            printf("%c", string[i]);
        }
        printf("\n");

        i = 0;
        countEsp = 0;
        tamanho = 0;
        while (string[i] != '\0') // conta e atribui a quantidade de espaços a um vetor
        {
            if (string[i] == ' ')
            {
                countEsp++;
                if (string[i + 1] == '\0')
                {
                    vetor[tamanho] = countEsp;
                    tamanho++;
                }
            }
            else
            {
                if (countEsp > 0)
                {
                    vetor[tamanho] = countEsp;
                    tamanho++;
                    countEsp = 0;
                }
            }
            i++;
        }

        printf("\n==== VETOR ====\n");
        for (i = 0; i < tamanho; i++)
        {
            printf("%2d\t", vetor[i]);
        }
        printf("\n");

        int matriz[tamanho][2];
        countDiv = 0;
        countPrimos = 0;
        for (i = 0; i < tamanho; i++) // conta a quantidade de divisores de cada numero, e os adiciona a uma matriz
        {
            for (j = 1; j <= vetor[i]; j++)
            {
                if (vetor[i] % j == 0)
                {
                    countDiv++;
                }
            }
            if (countDiv == 2) // verifica se o numero é primo, e o conta caso for primo
            {
                countPrimos++;
            }
            matriz[i][0] = vetor[i];
            matriz[i][1] = countDiv;
            countDiv = 0;
        }
        
        int vetorPrimos[countPrimos];
        j = 0;
        for (i = 0; i < tamanho; i++) // caso o numero de divisores seja igual a 2, o numero é adiciona ao vetorPrimos
        {
            if (matriz[i][1] == 2)
            {
                vetorPrimos[j] = matriz[i][0];
                j++;
            }
        }
        
        printf("\n==== PRIMOS ====\n");
        for (i = 0; i < countPrimos; i++)
        {
            printf("%2d\t", vetorPrimos[i]);
        }
        printf("\n");

        printf("\n\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}