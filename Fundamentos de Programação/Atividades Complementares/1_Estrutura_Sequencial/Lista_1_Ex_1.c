/*1) Escreva um algoritmo que leia o comprimento (cm), a largura (cm) e a altura (cm) de uma caixa retangular e calcule o seu volume (cm3), cuja fórmula é:
Volume = Comprimento * Largura * Altura
*/

#include <stdio.h>

int main (void){
    float comprimento, largura, altura, volume;

    printf ("Informe o comprimento: ");
    scanf ("%f", &comprimento);
    printf ("Informe a alrgura: ");
    scanf ("%f", &largura);
    printf ("Informe a altura: ");
    scanf ("%f", &altura);

    volume = comprimento * largura * altura;

    printf ("Volume: %.2f", volume, "cm³");

    return 0;
}
