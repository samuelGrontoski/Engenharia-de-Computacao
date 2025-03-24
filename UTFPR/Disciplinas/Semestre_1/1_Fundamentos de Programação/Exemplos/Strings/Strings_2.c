#include <stdio.h>
#include <locale.h>

int main (void)
{
    char opcao, string1[50], string2[50];
    int i;

    do
    {
        i = 0;

        printf ("Informe uma string: ");
        setbuf(stdin,NULL);
        gets(string1);

        printf ("String1: %s\n", string1);

        while (string1[i] != '\0')
        {
            string2[i] = string1[i];
            i++;
        }
        
        string2[i] = '\0';

        printf("String2: %s\n", string2);

        printf ("\nDeseja repetir o programa (S ou N)?");
        setbuf (stdin,NULL);
        scanf ("%c", &opcao);
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}