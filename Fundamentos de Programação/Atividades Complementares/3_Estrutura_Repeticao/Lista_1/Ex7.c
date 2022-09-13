/*
7) Em um intervalo de 0 a 100, apresentar:
a) Os números divisíveis por 3.
b) O quadrado dos números divisíveis por 3.
c) Os números divisíveis por 5 ou por 7.
d) A raiz quadrada dos números divisíveis por 5 ou por 7.
Apresentar cada item em listagem separada. Colocar um cabeçalho antes de cada listagem de maneira a
identificar o conteúdo da mesma. Em cada listagem separar os números por uma tabulação. A raiz quadrada
pode ser obtida pela função sqrt() que está na biblioteca math.h
*/

#include <stdio.h>
#include <math.h>

int main (void)
{
    int num;

    printf ("=== DIVISIVEIS POR 3 ===\n");
    for (num=1; num <= 100; num++)
    {
        if (num % 3 == 0)
        {
            printf ("\t%2d", num);
        }
    }

    printf ("\n\n=== QUADRADO DOS DIVISIVEIS POR 3 ===\n");
    for (num=1; num <= 100; num++)
    {
        if (num % 3 == 0)
        {
            printf ("\t%2d", num*num);
        }
    }

    printf ("\n\n=== DIVISIVEIS POR 5 OU 7 ===\n");
    for (num=1; num <= 100; num++)
    {
        if (num % 5 == 0 || num % 7 ==0)
        {
            printf ("\t%2d", num);
        }
    }

    printf ("\n\n=== RAIZ QUADRADA DOS DIVISIVEIS POR 5 OU 7 ===\n");
    for (num=1; num <= 100; num++)
    {
        if (num % 5 == 0 || num % 7 ==0)
        {
            printf ("\t%.2f", sqrt(num));
        }
    }

    return 0;
}
