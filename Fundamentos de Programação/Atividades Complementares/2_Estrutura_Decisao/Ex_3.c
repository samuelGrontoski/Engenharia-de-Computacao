/*
3) Escreva um programa que leia um número e verifique se ele se encontra no intervalo entre 5 e 20 ou fora
do fora do intervalo entre 5 e 20.
*/

int main (void) {

    int num;

    printf ("Informe um numero: ");
    scanf ("%d", &num);

    if (num >= 5 && num <= 20) {
        printf ("\n%d esta no intervalo entre 5 e 20\n", num);
    } else {
        printf ("\n%d nao esta no intervalo entre 5 e 20\n", num);
    }

return 0;
}
