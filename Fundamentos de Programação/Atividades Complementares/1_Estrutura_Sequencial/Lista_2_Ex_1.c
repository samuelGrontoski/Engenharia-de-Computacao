/* 1) Ler um número double. Separar a parte inteira e a parte decimal desse número. Apresentar a parte decimal
como um valor double e como um inteiro de três dígitos. Da parte inteira separar o número que representa
unidade, dezena e centena e mostrar. */

#include <stdio.h>

int main (void) {

    double num, parteDec;
    int parteInt, parteDecInt, unidade, dezena, centena;

    printf ("Informe um valor double: ");
    scanf ("%lf", &num);

    parteInt = (int)num;
    parteDec = num - parteInt;
    parteDecInt = parteDec * 1000;

    centena = parteInt / 100;
    dezena = (parteInt % 100) / 10;
    unidade = parteInt % 10;

    printf ("Numero informado: %lf\n", num);
    printf ("Parte inteira: %d\n", parteInt);
    printf ("Parte decimal: %lf\n", parteDec);
    printf ("Parte decimal como inteiro de tres digitos: %d\n", parteDecInt);
    printf ("Centena(s): %d\n", centena);
    printf ("Dezena(s): %d\n", dezena);
    printf ("Unidade(s): %d\n", unidade);

    return 0;
}
