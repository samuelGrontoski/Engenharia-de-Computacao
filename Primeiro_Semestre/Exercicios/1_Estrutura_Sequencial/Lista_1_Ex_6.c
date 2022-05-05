/*6) Leia dois valores A e B e efetue a troca do conteúdo das duas variáveis lidas,
de forma que a variável A passe a ter o valor de B e a variável B o valor de A.
Mostre o conteúdo das variáveis antes e depois da troca.
*/

int main (void) {

    float valorA, valorB, troca;

    printf ("Informe o valor A: ");
    scanf ("%f", &valorA);
    printf ("Informe o valor B: ");
    scanf ("%f", &valorB);

    printf ("Antes da troca: A=%.2f e B=%.2f\n", valorA, valorB);
    troca = valorA;
    valorA = valorB;
    valorB = troca;
    printf ("Depois da troca: A=%.2f e B=%.2f\n", valorA, valorB);

    return 0;
}
