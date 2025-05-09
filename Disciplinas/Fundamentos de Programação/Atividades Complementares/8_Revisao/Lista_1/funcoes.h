void mostrarVetorInteiro(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%2d\t", vetor[i]);
    }
}

void ordenarVetorInteiro(int vetor[], int tamanho)
{    
    int i, i2, auxiliar;

    for (i2 = tamanho - 1; i2 > 0; i2--)
    {
        for (i = 0; i < i2; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;
            }
        }
    }
}

// ex1

int ocorreNoVetor(int vetor[], int tamanho, int num)
{
    int i, count=0;

    for(i=0; i<tamanho; i++)
    {
        if(vetor[i] == num)
        {
            count++;
        }
    }
    return(count);
}

// ex2

int divisores(int vetor[], int tamanho, int num)
{
    int i, j, count=0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 1; j <= num; j++)
        {
            if (num % j == 0)
            {
                count++;
            }
        }
        return (count);
        count = 0;
    }
}