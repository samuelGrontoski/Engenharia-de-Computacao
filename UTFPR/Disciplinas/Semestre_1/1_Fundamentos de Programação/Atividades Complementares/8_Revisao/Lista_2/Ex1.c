/* 1) Gerar um vetor que n�o contenha n�meros repetidos, com 10 elementos aleat�rios entre 0 e 50. Utilizar
uma fun��o para verificar se cada elemento do vetor � ou n�o um n�mero primo. Essa fun��o retorna 0 para
indicar que o n�mero � primo ou 1 para indicar que o n�mero n�o � primo. Criar uma matriz 10x3 onde a
primeira coluna vai armazenar o �ndice do vetor, a segunda coluna vai armazenar o elemento do vetor e a
terceira coluna vai armazenar 0 se o elemento do vetor for um n�mero primo ou 1 caso o elemento do vetor
n�o seja um n�mero primo. Fazer a m�dia dos n�meros primos encontrados no vetor. */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void gerarVetorSemRepeticao(int vetor[], int tamanho, int limite);
void mostrarVetorInteiro(int vetor[], int tamanho);
int primo(int num);
void mostrarMatriz(int linha, int coluna, int matriz[linha][coluna]);

int main(void)
{
    setlocale(LC_ALL,"PORTUGUESE");
    
    char opcao;
    int i, j, tamanho = 10, vetor[tamanho], limite = 50, matriz[tamanho][3], soma, count;
    float media;

    do
    {
        printf("\n==== VETOR ====\n");
        gerarVetorSemRepeticao(vetor, tamanho, limite);
        mostrarVetorInteiro(vetor, tamanho);

        soma = 0;
        count = 0;
        for (i = 0; i < tamanho; i++)
        {
            matriz[i][0] = i;
            matriz[i][1] = vetor[i];
            matriz[i][2] = primo(vetor[i]);
            if (matriz[i][2] == 0)
            {
                soma = soma + matriz[i][1];
                count++;
            }
        }

        printf("\n\nINDICE\tNUMERO\tPRIMO\n");
        mostrarMatriz(10, 3, matriz);

        media = (float)soma / count;

        printf ("\nMedia dos n�meros primos: %.2f", media);

        printf("\n\nDeseja repetir o programa (S ou N)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}

void gerarVetorSemRepeticao(int vetor[], int tamanho, int limite)
{
    int i, j;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % limite;
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

void mostrarVetorInteiro(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%2d\t", vetor[i]);
    }
}

void mostrarMatriz(int linha, int coluna, int matriz[linha][coluna])
{
    int i, j;

    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            printf("%2d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int primo(int num)
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