#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale (LC_ALL, "PORTUGUESE");

    int a[10], b[10], i;

    for (i = 0; i < 10; i++)
    {
        printf("Informe um valor para a posição %d do vetor A: ", i+1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        b[i] = a[i] * 2;
    }
    for (i = 0; i < 10; i++)
    {
        printf("\nA posição %d do vetor B vale: %d", i + 1, b[i]);
    }

    return 0;
}