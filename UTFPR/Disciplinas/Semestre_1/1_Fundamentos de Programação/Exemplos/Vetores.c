#include <stdio.h>
#include <locale.h>

int main (void)
{
    setlocale (LC_ALL, "PORTUGUESE");

    float notas[5], media = 0;
    int i;

    for (i = 0; i < 5; i ++);
    {
        printf ("Informe a note do aluno %d: ", i);
        scanf ("%f", &notas[i]);

        media = media + notas[i];
    }

    media = media / 5;

    printf ("Media das notas: %.1f\n", media);

    return 0;
}