/* 5) Fazer um programa que mostra os caracteres repetidos de uma string. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    char string[100];
    int i, j, count;

    printf ("Informe uma string: ");
    setbuf(stdin, NULL);
    gets(string);

    j = 0;
    for (i = 65; i < 91; i++)
    {
        count = 0;
        for (j = 0; string[j] != '\0'; j++)
        {
            if (string[j] == i || string[j] == i+32)
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("%c", i+32);
        }
        
    }
    
}