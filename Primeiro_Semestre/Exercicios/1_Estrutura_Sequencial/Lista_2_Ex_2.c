/*2) Considerando que para um cons�rcio sabe-se o n�mero total de presta��es, a quantidade de presta��es
pagas e o valor de cada presta��o (que � fixo). Escreva um programa que determine o valor total j� pago pelo
consorciado e o saldo devedor.*/

#include <stdio.h>

int main (void) {
    int prest, prestPagas;
    float valorPrest, valorPago, valorDev;

    printf ("Informe a quantidade total de prestacoes: ");
    scanf ("%d", &prest);
    printf ("Informe a quantidade de prestacoes pagas: ");
    scanf ("%d", &prestPagas);
    printf ("Informe o valor (fixo) da prestacao: ");
    scanf ("%f", &valorPrest);

    valorPago = prestPagas * valorPrest;
    valorDev = (prest * valorPrest) - valorPago;

    printf ("Valor total ja pago: R$ %.2f\n", valorPago);
    printf ("SaldO devedor: R$ %.2f\n", valorDev);

    return 0;
}
