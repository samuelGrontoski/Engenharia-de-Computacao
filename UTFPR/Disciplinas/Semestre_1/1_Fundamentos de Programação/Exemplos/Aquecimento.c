#include <stdio.h>
#include <locale.h>

int main (void)
{
    setlocale (LC_ALL, "PORTUGUESE");

    char opcao, ch;
    int decimal, i, countDiv;

    do
    {
        printf ("Informe um caracter: ");
        setbuf (stdin, NULL);
        scanf ("%c", &ch);

        decimal = ch;
        countDiv = 0;

        for (i = 2; i < decimal; i++)
        {
            if (decimal % i == 0)
            {
                countDiv++;
                break;
            }
        }

        if (countDiv == 0)
        {
            printf ("\nO decimal '%d' é primo.", decimal);
        }
        else
        {
            printf ("\nO decimal '%d' não é primo.", decimal);
        }

        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');
    
    return 0;
}