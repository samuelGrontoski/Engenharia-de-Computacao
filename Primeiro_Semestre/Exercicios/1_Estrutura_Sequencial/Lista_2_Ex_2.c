/*2) Considerando que para um consórcio sabe-se o número total de prestações, a quantidade de prestações
pagas e o valor de cada prestação (que é fixo). Escreva um programa que determine o valor total já pago pelo
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
