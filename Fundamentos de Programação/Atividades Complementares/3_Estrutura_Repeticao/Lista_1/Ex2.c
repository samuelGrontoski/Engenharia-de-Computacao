/*
2) Ler uma s�rie de n�meros indicados pelo usu�rio at� ser informado o valor zero. Encontrar e mostrar o
maior e o menor dos valores informados pelo usu�rio. O valor zero indica o final da leitura e n�o deve ser
considerado.
*/

#include <stdio.h>

int main (void) {

    int num, maior=0, menor=0, count=0;

    do {
        printf ("Informe um numero: ");
        scanf ("%d", &num);

        count++;

        if (num != 0 && count == 1) {
            maior = num;
            menor = num;
        } else
        if (num != 0 && count != 1) {
            if (num > maior) {
                maior = num;
            } else
            if (num < menor) {
                menor = num;
            }
        }
    } while (num != 0);

    printf ("\nMaior: %d\t Menor: %d\n", maior, menor);

    return 0;
}
