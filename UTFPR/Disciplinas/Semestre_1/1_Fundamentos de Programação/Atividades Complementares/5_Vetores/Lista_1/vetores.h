//ex1

void mostrarVetorInteiros(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%2d\t", vetor[i]);
    }
}

void gerarVetorInteiroDe0aLimite (int vetor[], int tamanho, int limite)
{
    int i;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % (limite + 1);
    }
}

//ex2

void gerarVetorInteiroDe1a25 (int vetor[], int tamanho, int limite)
{
    int i, limInf = 1, limSup = 25;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % ((limSup - limInf) + 1) + limInf;
    }
}

//ex3

void gerarVetorInteiroDe1a10 (int vetor[], int tamanho, int limite)
{
    int i, limInf = 1, limSup = 10;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % ((limSup - limInf) + 1) + limInf;
    }
}

//ex4

void gerarVetorInteiroDe1a15 (int vetor[], int tamanho, int limite)
{
    int i, limInf = 1, limSup = 15;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % ((limSup - limInf) + 1) + limInf;
    }
}

void gerarVetorInteiroDe1a20 (int vetor[], int tamanho, int limite)
{
    int i, limInf = 1, limSup = 20;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % ((limSup - limInf) + 1) + limInf;
    }
}

//ex 5

void gerarVetorInteiroDe0a1 (int vetor[], int tamanho, int limite)
{
    int i, limInf = 0, limSup = 1;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % ((limSup - limInf) + 1) + limInf;
    }
}

void mostrarVetorInteiroDosZeros(int vetor[], int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] != 0)
        {
            printf("%2d\t", vetor[i]);
        }
    }
}