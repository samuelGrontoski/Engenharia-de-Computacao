#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    setlocale (LC_ALL,"PORTUGUESE");

    char opcao;
    int pessoas, countPessoa, passos;
    float metros, distancia, i, j, k;
    
    do
    {
        do
        {
            printf ("Informe o total de pessoas que farão a caminhada: ");
            scanf ("%d", &pessoas);

            if (pessoas <= 0)
            {
                printf ("\nValor de entrada inválido\n\n");
            }
        } while (pessoas <= 0);

        do
        {
            printf ("Informe o valor da distância a ser percorrida em metros: ");
            scanf ("%f", &metros);
            
            if (metros <= 0)
            {
                printf ("\nValor de entrada inválido\n\n");
            }
        } while (metros <= 0);
        
        printf ("Iniciando a caminhada de %.2f metros", metros);

        distancia = metros / pessoas;
        countPessoa = 1;

        do
        {
            printf ("\n--------------------Caminhada da pessoa %d--------------------\n", countPessoa);
            i = 0;
            j = 0;
            k = 0;
            for (passos = 1; k <= distancia; passos++)
            {
                i = (float)rand () / ((200 - 50) + 1) + 50;
                j = (j + i);
                k = k + j/100;

                printf ("Passo %d: Distância do passo: %.2f cm. Total percorrido: %.2f metros\n", passos, i, k);
            }
            countPessoa++;
        } while (countPessoa <= pessoas);
        

        printf("Deseja continuar no programa (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    

    return 0;
}