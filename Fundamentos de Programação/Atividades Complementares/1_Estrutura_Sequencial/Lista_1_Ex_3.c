/*3) Um professor atribui pesos de 1 a 3 para as notas de tr�s avalia��es, respectivamente. Fa�a um algoritmo que receba as notas e calcule e mostre a m�dia ponderada. A m�dia e as notas ser�o valores do tipo float.
M�dia Ponderada = (nota1 * 1 + nota2 * 2 + nota3 * 3)/(1+2+3)
*/

#include <stdio.h>

int main (void) {
    float nota1, nota2, nota3,media;

    printf ("Informe a Nota 1: ");
    scanf ("%f", &nota1);
    printf ("Informe a Nota 2: ");
    scanf ("%f", &nota2);
    printf ("Informe a Nota 3: ");
    scanf ("%f", &nota3);

    media = (nota1*1 + nota2*2 + nota3*3)/6;

    printf ("Media Ponderada: %.2f", media);

    return 0;
}
