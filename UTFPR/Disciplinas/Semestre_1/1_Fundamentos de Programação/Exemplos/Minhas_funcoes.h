int calculaFat(int num)
{
    int i, fat=1;

    for (i =  num; i >= 2; i--)
    {
        fat = fat * i;
    }
    return (fat);
}

void mostraFat (int num, int resultado)
{
    int i;

    printf ("%d! = ", num);

    for (i = num; i >= 2; i--)
    {
        printf ("%d * ", i);
    }

    printf ("1 = %d\n", resultado);
    
}