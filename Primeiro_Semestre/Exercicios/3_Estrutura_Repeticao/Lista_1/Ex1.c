/*
1) Ler um n�mero maior que 2 e imprimir todos os pares entre 2 e o n�mero lido (inclusive). Imprimir a soma dos pares,
o produto dos �mpares que s�o divis�veis por 9 e a m�dia de todos os n�meros do intervalo.
*/

#include <stdio.h>

int main (void) {

    int num, i, soma=0, produto=1;
    float media;

    do
    {
        printf ("Informe um numero maior que 2: ");
        scanf ("%d", &num);

        if (num <=2)
        {
            printf ("Valor invalido\n");
        }
    } while (num <= 2);

    printf ("Numeros pares:\n");

    for (i=2; i<=num; i++)
    {
        if (i%2 == 0)
        {
            printf ("%d\t", i);
            soma = soma + i;
        } else
        if (i%9 == 0)
        {
            produto = produto * i;
        }
        media = media + i;
    }

    printf ("\n\nSoma dos pares: %d\n", soma);
    printf ("Produto dos impares divisiveis por 9: %d\n", produto);
    printf ("Media de todos os numeros: %.2f\n", media/(num-1));

    return 0;
}
