/* 4) Fazer um programa que leia um número inteiro de até três dígitos (considere que será fornecido um
número de até 3 dígitos), calcule e imprima a soma dos seus dígitos.*/

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
