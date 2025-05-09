/*8) Apresentar os n�meros divis�veis por 4 ou m�ltiplos de 10 entre 500 e 0 e a m�dia desses m�ltiplos.*/

#include <stdio.h>

int main (void)
{
    int num, soma=0, count=0;
    float media;

    for (num=500; num >= 1; num--)
    {
        if (num % 4 == 0 || num % 10 == 0)
        {
            printf ("\t%2d", num);
            count++;
            soma = soma + num;
        }
    }
    media = (float)soma / count;

    printf ("\n\nMedia: %.2f\n", media);

    return 0;
}
