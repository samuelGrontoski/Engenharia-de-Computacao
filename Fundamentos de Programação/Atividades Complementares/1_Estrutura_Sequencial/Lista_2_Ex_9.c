/*9) Ler um n�mero inteiro com at� 3 d�gitos. Separar os d�gitos desse n�mero e mostr�-los em linhas distintas.
Na sequ�ncia calcular e mostrar o inverso do n�mero.*/

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
