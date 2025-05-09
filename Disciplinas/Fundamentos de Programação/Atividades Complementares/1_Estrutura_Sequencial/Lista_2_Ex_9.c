/*9) Ler um número inteiro com até 3 dígitos. Separar os dígitos desse número e mostrá-los em linhas distintas.
Na sequência calcular e mostrar o inverso do número.*/

int main (void) {

    int num, d1, d2, d3, numInv;

    printf ("Informe um numero inteiro com ate tres digitos: ");
    scanf ("%d", &num);

    d1 = num / 100;
    d2 = (num % 100) / 10;
    d3 = num % 10;

    printf ("%d eh o primeiro digito\n", d1);
    printf ("%d eh o segundo digito\n", d2);
    printf ("%d eh o terceiro digito\n", d3);

    numInv = (d3 * 100) + (d2 * 10) + d1;

    printf ("\nO inverso do numero eh: %d\n", numInv);

    return 0;
}
