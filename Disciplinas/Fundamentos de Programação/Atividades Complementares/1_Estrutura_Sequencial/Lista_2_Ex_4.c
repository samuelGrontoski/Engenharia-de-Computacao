/* 4) Fazer um programa que leia um n�mero inteiro de at� tr�s d�gitos (considere que ser� fornecido um
n�mero de at� 3 d�gitos), calcule e imprima a soma dos seus d�gitos.*/

int main (void) {

    int num, cent, dez, uni, soma;

    printf ("Informe um numero inteiro com ate tres digitos: ");
    scanf ("%d", &num);

    cent = num / 100;
    dez = (num % 100) / 10;
    uni = num % 10;
    soma = cent + dez + uni;

    printf ("%d = %d + %d + %d = %d\n", num, cent, dez, uni, soma);

    return 0;
}
