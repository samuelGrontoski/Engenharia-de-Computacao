/*8) Ler um n�mero inteiro com at� 5 d�gitos. Separar os d�gitos desse n�mero e mostr�-los em linhas distintas.
Tamb�m calcular e mostrar a soma dos d�gitos.*/

int main (void) {

    int num, d1, d2, d3, d4, d5, soma;

    printf ("Informe um numero inteiro com ate cinco digitos: ");
    scanf ("%d", &num);

    d1 = num / 10000;
    d2 = (num % 10000) / 1000;
    d3 = (num % 1000) / 100;
    d4 = (num % 100) / 10;
    d5 = num % 10;
    soma = d1 + d2 + d3 + d4 + d5;

    printf ("%d eh o primeiro digito\n", d1);
    printf ("%d eh o segundo digito\n", d2);
    printf ("%d eh o terceiro digito\n", d3);
    printf ("%d eh o quarto digito\n", d4);
    printf ("%d eh o quinto digito\n", d5);
    printf ("\nA soma dos digitos eh: %d\n", soma);

    return 0;
}
