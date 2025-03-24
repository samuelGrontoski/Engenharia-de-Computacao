#include <stdio.h>

int main (void) {

    int num1, num2, opcao;

    printf ("Informe o primeiro numero: ");
    scanf ("%d", &num1);
    printf ("Informe o segundo numero: ");
    scanf ("%d", &num2);

    printf ("1 - Soma\n");
    printf ("2 - Subtracao\n");
    printf ("3 - Multiplicacao\n");
    printf ("4 - Divisao\n");
    printf ("5 - Resto\n");
    printf ("\nEscolha uma opcao: ");
    scanf ("%d", &opcao);

    switch (opcao) {

        case 1 :
            printf ("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case 2 :
            printf ("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case 3 :
            printf ("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case 4 :
            if(num2 !=0) {
            printf ("%d / %d = %d\n", num1, num2, num1 / num2);
            } else {
                printf ("Nao eh possivel fazer a divisao por 0.\n");
            }
            break;
        case 5 :
            if(num2 !=0) {
            printf ("%d %% %d = %d\n", num1, num2, num1 % num2);
            } else {
                printf ("Nao eh possivel fazer a divisao por 0.\n");
            }
            break;

        default:
            printf ("Opcao invalida\n");
    }

    return 0;
}
