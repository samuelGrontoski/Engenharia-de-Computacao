/* 2) Ler um número positivo, validar a entrada repetindo a leitura até que seja informado um número que
atende essa condição. Esse número representa a quantidade de números ímpares a serem mostrados.
Apresentar esses valores n por linha, sendo n um número maior que zero, informado pelo usuário. Os valores
são apresentados separados por tabulação. Fazer a média dos números ímpares mostrados. */

#include <stdio.h>

int main(void)
{
    int quantidade, quantidadeLinha, countImp, impar, i, count, somaImpar;
    float media;
    char opcao;

    do
    {
        countImp = 0;
        somaImpar = 0;

        do
        {
            printf("Informe a quantidade de numeros impares que deseja mostrar: ");
            scanf("%d", &quantidade);

            if (quantidade <= 0)
            {
                printf("\nInforme um numero positivo\n\n");
            }
        } while (quantidade <= 0);

        do
        {
            printf("Informe quantos impares por linha deseja mostrar: ");
            scanf("%d", &quantidadeLinha);

            if (quantidadeLinha <= 0)
            {
                printf("\nInforme um numero positivo\n\n");
            }
        } while (quantidadeLinha <= 0);

        do
        {
            count = 0;
            impar = 1;
            for (i = 0; i < quantidade; i++)
            {  
                printf ("%d\t", impar);
                somaImpar = somaImpar + impar;
                impar =  impar + 2;
                countImp++;
                count++;
                if (count % quantidadeLinha == 0)
                {
                    printf ("\n");
                }
            }
        } while (countImp < quantidade);

        // media esta dando errada
        media = somaImpar/quantidade;
        printf ("A media dos impares eh: %.2f", media);
        
        printf("\nDeseja digitar outro numero (S/s)? ");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}