/*6) Fazer um programa que leia um valor double que representa o salário de uma pessoa. Apresente
separadamente os reais (parte inteira) e os centavos (parte decimal).*/

#include <math.h>

int main (void) {

    double salario, cents;
    int reais;

    printf ("Informe o valor do salario: R$ ");
    scanf ("%lf", &salario);

    reais = (int)salario;
    cents = (salario - reais) * 100;
    round(cents);

    printf ("Salario informado: R$ %.2lf\n", salario);
    printf ("Reais: %d\n", reais);
    printf ("Centavos: %.0lf\n", cents);

    return 0;
}
