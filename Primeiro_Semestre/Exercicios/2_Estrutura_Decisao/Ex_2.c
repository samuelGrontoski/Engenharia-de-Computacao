/*
2) Escreva um programa que leia um número e verifique se ele é maior, menor ou igual a 10
*/

int main (void) {

    int num;

    printf ("Informe um numero: ");
    scanf ("%d", &num);

    if (num == 10) {
        printf ("\n%d eh igual a 10\n", num);
    } else if (num > 10) {
        printf ("\n%d eh maior que 10\n", num);}
     else {
        printf ("\n%d eh menor que 10\n", num);
    }
return 0;
}
