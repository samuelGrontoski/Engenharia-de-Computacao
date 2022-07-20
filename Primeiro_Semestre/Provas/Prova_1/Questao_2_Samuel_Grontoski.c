#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");

    char caracter;
    int decimal, i, j, count, countLinha;

    do
    {
        count = 0;
        countLinha = 0;
        j = 2;

        printf("\nInforme um caractere: ");
        setbuf(stdin, NULL);
        scanf("%c", &caracter);

        decimal = caracter;

        if (caracter < '0')
        {
            printf("\nInforme um valor válido\n\n");
        }
        if (decimal >= 49 && decimal <= 57)
        {
            for (i = decimal; i >= 2; i--)
            {
                printf("%d * ", i);
            }
            printf("1");
        }
        if (decimal >= 65 && decimal <= 90)
        {
            for (i = 2; i <= decimal; i++)
            {
                if (i % j == 0)
                {
                    count++;
                }
                if (count == 2)
                {
                    printf("%d\t", i);
                    countLinha++;
                    count = 0;
                }
                if (countLinha == 6)
                {
                    printf("\n");
                    countLinha = 0;
                }
                j++;
            }
        }
        if (decimal >= 97 && decimal <= 122)
        {
            for (i = 2; i <= decimal; i++)
            {
                if (i % j == 0)
                {
                    count++;
                }
                if (count == 2)
                {
                    printf("%d\t", i);
                    countLinha++;
                    count = 0;
                }
                if (countLinha == 6)
                {
                    printf("\n");
                    countLinha = 0;
                }
                j++;
            }
        }

    } while (caracter != '0');

    return 0;
}