#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "PORTUGUESE");
    int valor;

    printf("Informe um valor positivo: ");
    scanf("%d", &valor);

    if (primo(valor) == 0)
    {
        printf("%d eh primo\n", valor);
    }
    else
    {
        printf("%d nao eh primo\n", valor);
    }

    return 0;
}

int primo(int num)
{
    int i, contDiv = 0;

    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            contDiv++;
            break;
        }
    }

    return (contDiv);
}