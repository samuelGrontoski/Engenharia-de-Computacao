void mostrarDivisores(int vetor[], int tamanho)
{
    qtdeDivisores(vetor, tamanho);
    int div, i, j, k;

    for (i = 0; i < tamanho; i++)
    {
        j = 1;

        if (i == i+1)
        {
            break;
        }
        else
        {
            printf("%2d => ", vetor[i]);

            for (k = 1; k <= vetor[i]; k++)
            {
                div = vetor[i] % j;

                if (div == 0)
                {
                    printf("%2d  ", j);
                }
                if (k == vetor[i])
                {
                    printf("%d divisores");
                    printf("\n");
                }
                j++;
            }
        }
    }
}

void qtdeDivisores(int vetor[], int tamanho)
{
    int countDiv = 0, i, div;

    for (i = 1; i < tamanho; i++)
    {
        div = vetor[i] % i;

        if (div == 0)
        {
            countDiv++;
        }
    }
}