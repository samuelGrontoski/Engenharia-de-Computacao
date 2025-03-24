#include <stdio.h>

int main (void)
{
    int num, i, count=0;

    printf ("Informe um numero: ");
    scanf ("%d", &num);

    for (i=1; i<=num; i++)
    {
        if (num%i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        printf ("%d eh primo\n", num);
    }
    else
    {
        printf ("%d nao eh primo", num);
    }
    return 0;
}