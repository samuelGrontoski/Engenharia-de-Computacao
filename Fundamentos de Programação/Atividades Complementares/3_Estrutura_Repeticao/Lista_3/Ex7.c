/* 7) Fazer um programa que calcule o fatorial dos números inteiros de 1 até 12. */

#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    int i, j, fat = 1, countLinha = 1, count = 0;

    for (i = 1; i <= 12; i++)
    {
        fat = fat * i;
        count++;

        printf("\n%d! => ", i);

        for (j = i; j > 1; j--)
        {
            printf("%d * ", j);
        }
        if (j == 1)
        {
            printf("1 = %d", fat);
        }
    }
    return 0;
}