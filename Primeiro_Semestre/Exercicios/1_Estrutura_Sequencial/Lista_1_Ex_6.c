/*6) Leia dois valores A e B e efetue a troca do conte�do das duas vari�veis lidas,
de forma que a vari�vel A passe a ter o valor de B e a vari�vel B o valor de A.
Mostre o conte�do das vari�veis antes e depois da troca.
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
