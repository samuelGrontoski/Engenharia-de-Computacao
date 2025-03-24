
// Aluno: Samuel Grontoski

#include <stdio.h>
#include <locale.h>

int main (void)
{
    setlocale(LC_ALL,"PORTUGUESE");

    int numDec, bin[100], i, j, aux_numDec, resto;

    printf("\nCONVERSOR  DE BASE - DECIMAL PARA BINÁRIO");
    printf("\n=========================================\n\n");

    printf("Digite o valor em decimal que deseja converter para binário: ");
    scanf("%d", &numDec);

    aux_numDec = numDec;

    for (i = 0; numDec > 0; i++)
    {
        bin[i] = numDec % 2;
        numDec = numDec / 2;
    }
    
    printf("\n%d em binário: ", aux_numDec);

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", bin[j]);
    }
    
    return 0;
}