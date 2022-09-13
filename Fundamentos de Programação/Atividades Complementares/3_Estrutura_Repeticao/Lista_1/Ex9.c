/*
9) Ler n�meros inteiros informados pelo usu�rio at� ser informado um valor negativo. Dentre os n�meros
informados, exceto o valor negativo que � a condi��o de sa�da:
a) Contar a quantidade de n�meros menores que 10 ou maiores que 100.
b) Contar a quantidade de n�meros �mpares.
c) Contar a quantidade de n�meros divis�veis por 10.
d) Contar a quantidade de n�meros entre 10 e 100.
e) Contar quantas vezes � informado o n�mero 30.
f) Contar quantas vezes � informado um n�mero diferente de 10, de 20 e de 30.
*/

int main (void)
{
    //usar a mesma l�gica da 2 para valida��o

    int num, countM10ou100=0, countImp=0, countDiv10=0, countEnt10e100=0, count30=0, countNaoDeci=0;

    do
    {
        printf ("Informe um numero (negativo para finalizar): ");
        scanf ("%d", &num);

        if (num < 10 || num > 100)
        {
            countM10ou100++;
        }
        if (num % 2 != 0)
        {
            countImp++;
        }
        if (num % 10 == 0)
        {
            countDiv10++;
        }
        if (num >= 10 && num <= 100)
        {
            countEnt10e100++;
        }
        if (num == 30)
        {
            count30++;
        }
        if (num != 10 && num !=20 && num !=30)
        {
            countNaoDeci++;
        }
    } while (num >= 0);

    printf ("Quantidade de numeros menores que 10 ou maiores que 100: %d\n", countM10ou100);
    printf ("Quantidade de numeros impares: %d\n", countImp);
    printf ("Quantidade de numeros divisiveis por 10: %d\n", countDiv10);
    printf ("Quantidade de numeros entre 10 e 100: %d\n", countEnt10e100);
    printf ("Quantidade de vezes que o numero 30 foi informado: %d\n", count30);
    printf ("Quantidade de vezes que foi informado um numero diferente de 10, 20 e 30: %d\n", countNaoDeci);

    return 0;
}
