void mostrarVetorInteiro(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%2d\t", vetor[i]);
    }
}

// ex 1

void gerarVetorInteiroComFaixa(int vetor[], int tamanho)
{
    int i, limInf = 5, limSup = 20, vetorB[tamanho];

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = (rand() % ((limSup - limInf) + 1)) + limInf;
    }
}

void ordenarVetorInteiro(int vetor[], int tamanho)
{
    gerarVetorInteiroComFaixa(vetor, tamanho);

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