#include <stdio.h>
#include <locale.h>

void soma(int valor1, int valor2)
{
    printf("\nSoma: %d\n", valor1 + valor2);
}

int subtracao(int valor1, int valor2)
{
    int resultado;

    resultado = valor1 - valor2;

    return (resultado);
}

void multiplicacao(void)
{
    int num1, num2, resultado;

    printf("Informe o primeiro valor: ");
    scanf("%d", &num1);
    printf("Informe o segundo valor: ");
    scanf("%d", &num2);

    resultado = num1 * num2;

    printf("Multiplicacao: %d\n", resultado);
}

float divisao (void)
{
    int num1, num2, resultado;

    printf ("Informe o primeiro valor: ");
    scanf ("%d", &num1);

    do
    {
        printf ("\nInforme o segundo valor: ");
        scanf ("%d", &num2);

        if (num2 = 0)
        {
            printf ("\nValor invalido\n");
        }
        
    } while (num2 = 0);
    
    resultado = (float)num1 / num2;

    printf ("%d / %d = %.2f", num1, num2, resultado);

    return (resultado);
}

int main(void)
{

    int num1, num2;
    char opcao;

    do{

        printf("Informe o primeiro valor: ");
        scanf("%d", &num1);
        printf("Informe o segundo valor: ");
        scanf("%d", &num2);

        soma(num1, num2);

        printf("\nSubtracao: %d\n", subtracao(num1, num2));

        multiplicacao();

        setbuf(stdin, NULL);
        printf("\nDeseja repetir o programa (S/s)? ");
        scanf("%c", &opcao);
        printf("\n");

    }while(opcao == 's' || opcao == 'S');

    return 0;
}
