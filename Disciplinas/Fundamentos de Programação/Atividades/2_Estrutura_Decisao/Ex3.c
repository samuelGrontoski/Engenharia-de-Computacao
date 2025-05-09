/*3) A figura a seguir representa uma árvore de decisão para identificar se um paciente está saudável ou
doente. Elabore um programa que implementa essa árvore de decisão.*/

#include <stdio.h>

int main (void)
{
    int situacao, dor;
    float temperatura;

    printf ("\nOla! Eu sou Baymax, seu agente pessoal de saude.\n");
    printf ("Voce se sente bem? \n1 - Sim \n2 - Nao \nEscolha uma opcao: ");
    scanf ("%d", &situacao);

    if (situacao == 1)
    {
        printf ("Aparentemente voce esta saudavel.");
    }
    else
    {
        printf ("Voce esta com dor? \n1 - Sim \n2 - Nao \nEscolha uma opcao: ");
        scanf ("%d", &dor);

        if (dor == 1)
        {
            printf ("Aparentemente voce esta doente.");
        }
        else
        {
            printf ("Informe sua temperatura: ");
            scanf ("%f", &temperatura);

            if (temperatura <= 37)
            {
                printf ("Aparentemente voce esta saudavel.");
            }
            else
            {
                printf ("Aparentemente voce esta doente.");
            }
        }
    }
    return 0;
}